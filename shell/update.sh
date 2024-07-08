#!/bin/bash

# workspaceFolder
if [ "$(uname)" == 'Darwin' ]; then
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
        "-I$1/ac-library"
        "-I$1/include"
        "-I$1/tpl"
        "-x"
        "c++-header"
        "-o"
        "tpl/template.hpp.pch"
        "tpl/template.hpp"
        "-I/usr/include/eigen3"
    )
    export CPATH="/opt/homebrew/include/:$CPATH"
    /usr/bin/clang++ ${args[@]}
else
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
        "-I$1/ac-library"
        "-I$1/include"
        "-I$1/tpl"
        "-o"
        "tpl/template.hpp.gch"
        "tpl/template.hpp"
        "-I/usr/include/eigen3"
    )
    /usr/bin/g++-12 ${args[@]}
fi

cp /dev/null $1/tpl/template
while IFS= read line; do
    if [ "$line" == '// TEMPLATE' ]; then
        cat $1/tpl/template.hpp >>$1/tpl/template
        continue
    fi
    echo "$line" >>$1/tpl/template
done <$1/tpl/template.cpp
