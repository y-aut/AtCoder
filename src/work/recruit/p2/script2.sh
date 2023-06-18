while read line; do
    date=$(echo $line | cut -d , -f 1)
    if [ "$1" = "$date" ]; then
        echo $line >>data/$1.csv
    fi
done <data.csv
