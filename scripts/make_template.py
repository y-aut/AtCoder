import os
import sys
import re

# エラーメッセージを表示してプログラムを終了する関数
def error_exit(message):
    print(f"Error: {message}")
    sys.exit(1)

# 引数のチェック
args = sys.argv
if len(args) < 3:
    error_exit("Usage: make_template.py <template_dir> <out_filename> [-d <definition1> [-d <definition2> ...]]")

template_dir = args[1]
out_filename = args[2]

# ディレクトリの存在確認
if not os.path.isdir(template_dir):
    error_exit(f"Template directory '{template_dir}' does not exist or is not a directory.")

# 定義のリスト
defs = []

# -d オプションの後の引数を収集
i = 3
while i < len(args):
    if args[i] == '-d':
        if i + 1 < len(args):
            defs.append(args[i + 1])
            i += 2
        else:
            error_exit("Missing definition after '-d'.")
    else:
        i += 1

# load template.hpp
header = []
with open(os.path.join(template_dir, "template.hpp"), encoding="utf8") as f:
    skip = False
    for line in f:
        m = re.fullmatch(r"// *!endif *\n", line)
        if m:
            skip = False
            continue
        if skip: continue
        m = re.fullmatch(r"// *!if(n?)def +([^ ]+) *\n", line)
        if m:
            if (not m.group(2) in defs) ^ (m.group(1) == "n"):
                skip = True
            continue
        header.append(line)

# load template.cpp and print
with open(os.path.join(template_dir, "template.cpp"), encoding="utf8") as fr:
    skip = False
    with open(os.path.join(template_dir, out_filename), "w", encoding="utf8") as fw:
        for line in fr:
            m = re.fullmatch(r"// *!endif *\n", line)
            if m:
                skip = False
                continue
            if skip: continue
            m = re.fullmatch(r"// *!if(n?)def +([^ ]+) *\n", line)
            if m:
                if (not m.group(2) in defs) ^ (m.group(1) == "n"):
                    skip = True
                continue
            m = re.fullmatch(r"// *!template *\n", line)
            if m:
                fw.writelines(header)
            else:
                fw.write(line)
