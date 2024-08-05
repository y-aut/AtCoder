import os
import sys
import re
import json
from pathlib import Path

# エラーメッセージを表示してプログラムを終了する関数
def error_exit(message):
    print(f"Error: {message}")
    sys.exit(1)

# 引数のチェック
args = sys.argv
if len(args) < 3:
    error_exit("Usage: make_snippets.py <workspace_dir> <out_filename>")

workspace_dir = args[1]
out_filename = args[2]

# ディレクトリの存在確認
if not os.path.isdir(workspace_dir):
    error_exit(f"Workspace directory '{workspace_dir}' does not exist or is not a directory.")

# lib 内のファイルを列挙
path = Path(os.path.join(workspace_dir, "lib"))
files = [str(file) for file in path.rglob('*') if file.is_file()]

snippets = {}

# body にファイルの内容を書き込む
def add_body(snippet, filepath, included):
    filename = os.path.splitext(os.path.basename(filepath))[0]
    snippet["body"].append(f'#pragma region "{filename}"')
    snippet["body"].append("")
    skip = False
    with open(filepath, encoding="utf8") as f:
        for line in f:
            m = re.fullmatch(r"// *!endhidden *\n", line)
            if m:
                skip = False
                continue
            if skip: continue
            m = re.fullmatch(r"// *!hidden *\n", line)
            if m:
                skip = True
                continue
            m = re.fullmatch(r"#include *\"(.+)\" *\n", line)
            if m:
                file = m.group(1)
                if file in included: continue
                add_body(snippet, os.path.join(workspace_dir, file), included)
                included.append(file)
                continue
            line = line.rstrip()
            # 先頭または連続する空行は削除
            if line == "" and (len(snippet["body"]) == 0 or snippet["body"][-1] == ""):
                continue
            snippet["body"].append(line)
    snippet["body"].append("")
    snippet["body"].append(f'#pragma endregion "{filename}"')


def make_snippet(filepath):
    filename = os.path.splitext(os.path.basename(filepath))[0]
    snippet = {
        "scope": "cpp",
        "prefix": filename,
        "body": [],
    }
    add_body(snippet, filepath, [])
    snippet_name = filepath[len(workspace_dir) + 1:]
    snippets[snippet_name] = snippet

for file in files:
    print(f"processing {file}...", end="")
    make_snippet(file)
    print(" Done.")

print("writing...", end="")
with open(os.path.join(workspace_dir, ".vscode", out_filename), "w", encoding="utf8") as f:
    json.dump(snippets, f, indent=4)
print(" Done.")
