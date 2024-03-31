# [d|r], workspaceFolder
cd /usr/include/x86_64-linux-gnu/c++/12/bits
if [ "$1" == "d" ]; then
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
        "-I$2/ac-library"
        "-I$2/include"
        # "-o"
        # "stdc++.h.gch/precompile.gch"
        "stdc++.h"
        # "-lgmpxx"
        # "-lgmp"
        # "-I/usr/include/eigen3"
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
        "-o"
        "stdc++.h.gch/precompile.gch"
        "stdc++.h"
        "-lgmpxx"
        "-lgmp"
        "-I/usr/include/eigen3"
    )
fi
sudo /usr/bin/g++-12 ${args[@]}
