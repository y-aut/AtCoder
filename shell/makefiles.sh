#!/bin/bash

# workspaceFolder, 大会ディレクトリ, ファイル名
mkdir -p $1/$2
count=0
files=()
for f in $3; do
    files+=($1/$2/$f.cpp)
    if [ -e $1/$2/$f.cpp ]; then
        echo -e "\e[31mError: File $2/$f.cpp already exists.\e[m"
    else
        cp $1/tpl/template $1/$2/$f.cpp
        count=$(expr $count + 1)
        echo Created $2/$f.cpp.
    fi
done
echo
echo Created $count files in $2.
code ${files[@]}
