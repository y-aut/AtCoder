#!/bin/bash

exe_path() {
    if [ "$1" = "d" ]; then
        echo debug.exe
    elif [ "$1" = "r" ]; then
        echo release.exe
    elif [ "$1" = "m" ]; then
        echo model.exe
    else
        echo $1
    fi
}

exe1=$(exe_path $2)
exe2=$(exe_path $3)

# workspaceFolder, exe1, exe2
while true; do
    /usr/bin/python3 $1/tools/geninput.py >$1/in
    cp $1/in $1/out
    $1/$exe1 <$1/in >>$1/out
    out2=$($1/$exe2 <$1/out)
    if [ "$out2" != "Yes" ]; then
        echo Found an input.
        exit 0
    fi
done
