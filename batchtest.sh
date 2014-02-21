for ((i = 0; i < 50; i++))
do
	echo "$i : 20x20x5x5" >> log.txt
	./cirtest.sh 20 20 5 5
done
for ((i = 0; i < 50; i++))
do
  	echo "$i : 4x4x4x4" >> log.txt
        ./cirtest.sh 4 4 4 4
done
for ((i = 0; i < 50; i++))
do
  	echo "$i : 10x30x4x10" >> log.txt
        ./cirtest.sh 10 30 4 10
done
for ((i = 0; i < 50; i++))
do
  	echo "$i : 30x10x10x4" >> log.txt
        ./cirtest.sh 30 10 10 4
done
for ((i = 0; i < 20; i++))
do
  	echo "$i : 50x50x20x20" >> log.txt
        ./cirtest.sh 50 50 20 20
done
