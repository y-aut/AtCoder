# workspaceFolder, exe1, exe2
while true; do
    /usr/bin/python3 $1/tools/geninput.py >$1/in.txt
    out1=$($1/$2 <$1/in.txt)
    out2=$($1/$3 <$1/in.txt)
    if [ "$out1" != "$out2" ]; then
        echo -e "$2:\n$out1\n\n$3:\n$out2" >$1/out.txt
        echo Found an input.
        exit 0
    fi
done
