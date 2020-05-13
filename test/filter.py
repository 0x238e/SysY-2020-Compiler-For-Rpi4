#!/bin/env python3

import os
import re
from functools import reduce

source_dir = "llvm-testsuite"
target_dir = "pre"

id_pat = r"([a-zA-Z_][a-zA-Z0-9_]*)"

# Files with substrings that match following patterns will be rejected
reject = [
    r"struct\s+",
    r"typedef\s+",
    r"#define",
    r"#if",
    r"#ifdef",
    r"#ifndef",
    r"#pragma",
    r"\s+switch\s+",
    r"\s+case\s+",
    r"\s+double\s+",
    r"\s+float\s+",
    r":",
    r"\?",
]

reject_count = 0
reject_pattern = reduce(lambda x, y: x + "(" + y + ")" + r"|", reject, "")
reject_pattern = reject_pattern[:-1]

# Delete following substrings in files
delete = [
    r"do\s+",
    r"extern\s+",
    r"inline\s+",
    r"static\s+",
    r"volatile\s+",
    r"#.*\n",
    r"\+\+",
    r"--",
    r"\.\.\.",
]

delete_count = 0
delete_pattern = reduce(lambda x, y: x + "(" + y + ")" + r"|", delete, "")
delete_pattern = delete_pattern[:-1]

replace = [
    # chars
    (r"\'.*\'", "0"),
    # strings "..."
    (r"\".*\"", "0"),
    # int main(void | argc ...)
    (r"int(\s|\n)+main(\s*)\((.*)\)", r"int\1main\2()"),
    # for loops
    (r"for(\s*)\((.*);(.*);(.*)\)", r"while\1(\3)"),
    # Bitwise operation
    (r"\^", r"+"),
    (r"~", r"!"),
    (r"<<", r"*"),
    (r">>", r"/"),
    (r"(^&)&(^&)", "+"),
    # Accumulative operation
    (id_pat + r"(\s*)(\+|-|\*|/)=(\s*)(.*);", r"\1 = \1 \3 \5"),
    # Non int primitive types
    # (r"(\s+)(unsigned\s+)?((char)|(short int)|(short)|(long long int)|(long long)|(long))\s+", r"\1int"),
    # (r"(\s+)(uint|int)[a-zA-Z_]*\s+", r"\1int"),
    # (r"(\s+)bool", r"\1int"),
]

replace_count = 0

print("reject_pattern = ")
print(reject_pattern)
print("delete_pattern = ")
print(delete_pattern)

input()

def getListOfFiles(dirName):
    listOfFile = os.listdir(dirName)
    allFiles = list()
    for entry in listOfFile:
        fullPath = os.path.join(dirName, entry)
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)

    return allFiles

files = getListOfFiles(source_dir)
files = list(filter(lambda s: s.endswith(".c"), files))

limit = 100000
for file in files:
    with open(file, 'r') as f:
        s = ""

        try:
            s = f.read()
        except BaseException:
            continue
        else:
            if re.search(reject_pattern, s) != None:
                reject_count += 1
                continue

            # Delete
            s, dn = re.subn(delete_pattern, "", s)
            if dn > 0:
                delete_count += 1

            # Replace
            replaced = False
            for replace_pattern in replace:
                s, rn = re.subn(*replace_pattern, s)
                if rn > 0:
                    replaced = True

            if replaced:
                replace_count += 1
                print(f.name)
                print(s)

            # Write to pre/
            if s == "":
                continue

            fo = open(target_dir + "/" + f.name.split("/")[-1], "w")
            fo.write(s)
            fo.close()

            limit -= 1
            if limit == 0:
                break

print("total files =", len(files))
print("reject_count =", reject_count)
print("delete_count =", delete_count)
print("replace_count =", replace_count)