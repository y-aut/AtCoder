# workspaceFolder
args=(
    "-std=gnu++20"
    "-O0"
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
if [ "$(uname)" == 'Darwin' ]; then
    export CPATH="/opt/homebrew/include/:$CPATH"
    /opt/homebrew/bin/g++-12 ${args[@]}
else
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
