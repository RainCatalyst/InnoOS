# Usage run_n_times.sh times command
for ((i=1;i<=$1;i++))
    do
        eval $2
done
