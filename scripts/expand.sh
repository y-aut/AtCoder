#!/bin/bash

# workspacefolder, file

export CPLUS_INCLUDE_PATH="$1/ac-library"
python3 $1/ac-library/expander.py $2
code combined.cpp
