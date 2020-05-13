#!/bin/bash

if [ -d "csmith" ]; then
    echo "csmith exists"
else
    git clone https://github.com/csmith-project/csmith.git
fi

cd csmith
cmake .
make
