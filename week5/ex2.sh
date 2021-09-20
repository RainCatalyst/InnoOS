while ! ln numbers.txt numbers.lock; do :; done
for i in {1..10}
do
    text=$(<numbers.txt)
    echo -n " $((1 + ${text##* }))" >> numbers.txt
    sleep 1
done
rm numbers.lock