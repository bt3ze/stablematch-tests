for ((i = 0; i < 3; i++))
do
        echo "$i : 700x700x60x3" >> sororitylog.txt
        ./cirtest.sh 700 700 60 3
done
for ((i = 0; i < 3; i++))
do
        echo "$i : 700 700 3 60" >> log.txt
        ./cirtest.sh 700 700 3 60
done
