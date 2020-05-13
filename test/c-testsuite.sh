#!/bin/bash

if [ -d "c-testsuite" ]; then
    echo "c-testsuite exists"
else
    git clone https://github.com/c-testsuite/c-testsuite.git
fi
