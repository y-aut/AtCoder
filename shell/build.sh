#!/bin/bash

# [d|r], workspaceFolder, file, outFileName
if [ "$1" == "d" ]; then
    args=(
        "-std=gnu++20"
        "-O0"
        "-gdwarf-3"
        "-DONLINE_JUDGE"
        "-DATCODER"
        "-DDEBUG"
        "-Wall"
        "-Wextra"
        "-Wno-unknown-pragmas"
        "-pthread"
        "-g"
        "-fno-inline"
        "-ftrapv"
        "-fconstexpr-depth=2147483647"
        "-fconstexpr-loop-limit=2147483647"
        "-fconstexpr-ops-limit=2147483647"
        "-I$2/ac-library"
        "-I$2/include"
        "-I$2/tpl"
        "-o"
        "$2/$4"
        "$3"
        "-lgmpxx"
        "-lgmp"
        "-I/usr/include/eigen3"
    )
else
    args=(
        "-std=gnu++20"
        "-O2"
        "-DONLINE_JUDGE"
        "-DATCODER"
        "-Wall"
        "-Wextra"
        "-Wno-unknown-pragmas"
        "-mtune=native"
        "-march=native"
        "-fconstexpr-depth=2147483647"
        "-fconstexpr-loop-limit=2147483647"
        "-fconstexpr-ops-limit=2147483647"
        "-I$2/ac-library"
        "-I$2/include"
        "-I$2/tpl"
        "-o"
        "$2/$4"
        "$3"
        "-lgmpxx"
        "-lgmp"
        "-I/usr/include/eigen3"
    )
fi

if [ "$(uname)" == 'Darwin' ]; then
    export CPATH="/opt/homebrew/include/:$CPATH"
    export LIBRARY_PATH="/opt/homebrew/lib:$LIBRARY_PATH"
    unbuffer /opt/homebrew/bin/g++-12 ${args[@]} 2>&1 | tee build.ans
    exit ${PIPESTATUS[0]}
else
    /usr/bin/g++-12 ${args[@]}
fi
