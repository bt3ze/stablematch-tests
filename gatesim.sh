
for ((i = 0; i < 9; i++))
do
  	echo "$1.$i.pcf2" >> gatecounts.$1.2.txt
        ./simulate.sh ~/stablematch/gatetests/$1.$i.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.2.txt
done


