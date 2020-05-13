#!/bin/env python3

import os
import re
from functools import reduce

# Files with substrings that match following patterns will be rejected
reject = [
    r"struct",
    r"typedef",
    r"switch",
    r"case",
]

reject_pattern = reduce(lambda x, y: x + r"(\s+)" + y + r"(\s+)" + r"|", reject, "")
reject_pattern = reject_pattern[:-1]

# Delete following substrings in files
delete = [
    r"static",
    r"volatile",
    r"inline",
    r"do",
]

# Comment out following substrings in files
comment_out = [
    "#include(\\s*)[\"<](.*)[\">]"
]

replace = []


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

files = getListOfFiles("c-testsuite/tests/single-exec")
files = list(filter(lambda s: s.endswith(".c"), files))

for file in files:
    with open(file, 'r') as f:
        s = f.read()

        if re.search(reject_pattern, s) != None:
            print(f.name)
            print(s)
            continue
