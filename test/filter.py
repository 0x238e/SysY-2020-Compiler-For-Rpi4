#!/bin/env python3

import os
import re
from functools import reduce
from subprocess import check_output

source_dir = "llvm-testsuite"
target_dir = "pre"

id_pat = r"([a-zA-Z_][a-zA-Z0-9_]*)"

# Files with substrings that match following patterns will be rejected
reject = [
    r"struct\s+",
    r"typedef\s+",
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
    r"\.\.\.",
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
    r"__attribute__\s*\(\(.*\)\)",
    r"#.*\n",
    r"\+\+",
    r"--",
]

delete_count = 0
delete_pattern = reduce(lambda x, y: x + "(" + y + ")" + r"|", delete, "")
delete_pattern = delete_pattern[:-1]


sign = r"(\+|-)?"
digit_prefix = r"(0|0b|0B|0x|0X)?"
digit_body = r"([0-9a-fA-F]+)"
digit_postfix = r"(llu|ll|lu|l|u|LLU|LL|LU|L|U)?"

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

    # Accumulative operation
    (id_pat + r"(\s*)(\+|-|\*|/)=(\s*)(.*);", r"\1 = \1 \3 \5;"),
    # Non int primitive types
    # Might change identifier names, but who cares
    (r"((unsigned|signed)\s+)?((bool)|(char)|(short int)|(short)|\
       (long long int)|(long long)|(long int)|(long)|(int))", r"int"),
    (r"(uint|int)[0-9a-zA-Z_]*", r"int"),

    # The following requires clang-format preprocessing to work properly
    (r"\s&\s", r"*"),
    (r"\s\|\s", r"+"),

    (r"\(void\)", r"()"),
    # Pointer declaration
    (r"(int|void)\s+\*+", r"int "),
    # Pointer dereference
    (r"\*+" + id_pat, r" \1"),
    (r"\*+\((.*)\)", r" \1"),
    # Address operation
    (r"\&" + id_pat, r" \1"),
    (r"\&+\((.*)\)", r" \1"),
    # Type cast
    (r"\(int\)", ""),

    # Remove postfix of numbers
    (r"(\s|\()" + sign + digit_prefix + digit_body + digit_postfix + r"(\s|\))", r"\1\2\3\4\6"),
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

limit = 10000
for file in files:
        try:
            s = check_output(["clang-format", "--style=Microsoft", file]).decode("utf-8")
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
                print(s)

            # Write to pre/
            if s == "":
                continue

            fo = open(target_dir + "/" + file.split("/")[-1], "w")
            fo.write(s)
            fo.close()

            limit -= 1
            if limit == 0:
                break

print("total files =", len(files))
print("reject_count =", reject_count)
print("delete_count =", delete_count)
print("replace_count =", replace_count)