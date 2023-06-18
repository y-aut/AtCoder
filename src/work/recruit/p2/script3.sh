for file in data/*; do
    sum=0
    while read line; do
        price=$(echo $line | cut -d , -f 3)
        sum=$(expr $sum + $price \* 4 / 5)
    done <$file
    date=$(basename $file .csv)
    echo $date: $sum
done
