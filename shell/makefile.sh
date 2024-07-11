#!/bin/bash
# URL からコンテストファイルを生成する

# workspaceFolder, url

if [[ $2 =~ ([a-z]+)([0-9]+)_([a-z]) ]]; then
    contest=${BASH_REMATCH[1]}
    number=${BASH_REMATCH[2]}
    task=${BASH_REMATCH[3]}

    # ディレクトリパスを作成
    dir_path=src/$contest/$number

    # ディレクトリが存在しない場合は作成
    mkdir -p $1/$dir_path

    # ファイルパスを作成
    file_path=$dir_path/$task.cpp
    if [ -e $1/$file_path ]; then
        echo File $file_path already exists.
    else
        cp $1/tpl/template $1/$file_path
        echo Created $file_path.
    fi

    code $1/$file_path
else
    echo "Invalid URL format."
fi
