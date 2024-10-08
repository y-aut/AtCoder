#!/bin/bash

# [d|r], workspaceFolder, file, outFileName
if [ "$(uname)" == 'Darwin' ]; then
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
            "-Wno-sign-compare"
            "-pthread"
            "-g"
            "-fno-inline"
            "-ftrapv"
            "-fconstexpr-depth=2147483647"
            "-fconstexpr-steps=2147483647"
            "-fsanitize=address,undefined"
            "-fno-omit-frame-pointer"
            "-I$2/ac-library"
            "-I$2/include"
            "-I$2/tpl"
            "-include"
            "$2/tpl/template.hpp"
            "-o"
            "$2/$4"
            "$3"
            "-lgmpxx"
            "-lgmp"
            "-I/opt/homebrew/include/eigen3"
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
            "-Wno-sign-compare"
            "-Wno-unused-const-variable"
            "-mtune=native"
            "-march=native"
            "-fconstexpr-depth=2147483647"
            "-fconstexpr-steps=2147483647"
            "-I$2/ac-library"
            "-I$2/include"
            "-I$2/tpl"
            "-o"
            "$2/$4"
            "$3"
            "-lgmpxx"
            "-lgmp"
            "-I/opt/homebrew/include/eigen3"
        )
    fi
    export CPATH="/opt/homebrew/include/:$CPATH"
    export LIBRARY_PATH="/opt/homebrew/lib:$LIBRARY_PATH"
    unbuffer /usr/bin/clang++ ${args[@]} 2>&1 | tee build.ans
    exit ${PIPESTATUS[0]}
else
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
    /usr/bin/g++-12 ${args[@]}
fi
