#!/bin/bash

# workspacefolder, file

python3 $1/scripts/library_expander.py $2 $1/library && code combined.cpp
