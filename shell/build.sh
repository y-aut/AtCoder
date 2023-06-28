# [d|r], workspaceFolder, file, outFileName
if [ "$1" == "d" ]; then
    args=(
        "-std=gnu++17"
        "-Wall"
        "-Wextra"
        "-Wno-unknown-pragmas"
        "-pthread"
        "-g"
        "-O0"
        "-D"
        "DEBUG"
        "-DONLINE_JUDGE"
        "-fno-inline"
        "-ftrapv"
        "-I/opt/boost/gcc/include"
        "-L/opt/boost/gcc/lib"
        "-I$2/ac-library"
        "-I$2/tpl"
        "-o"
        "$2/$4"
        "$3"
    )
else
    args=(
        "-std=gnu++17"
        "-g"
        "-O3"
        "-DONLINE_JUDGE"
        "-I/opt/boost/gcc/include"
        "-L/opt/boost/gcc/lib"
        "-I$2/ac-library"
        "-o"
        "$2/$4"
        "$3"
    )
fi
/usr/bin/g++ ${args[@]}
