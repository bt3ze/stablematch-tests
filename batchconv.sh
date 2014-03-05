

for ((i = 0; i < 9; i++))
do
  	echo " 4.$i.lcc -> 4.$i.pcf2 " >> log.txt
        ./translate.sh ~/stablematch/gatetests/4.$i.lcc ~/stablematch/gatetests/4.$i.pcf2
done

for ((i = 0; i < 9; i++))
do
  	echo " 10.$i.lcc -> 10.$i.pcf2 " >> log.txt
        ./translate.sh ~/stablematch/gatetests/10.$i.lcc ~/stablematch/gatetests/10.$i.pcf2
done

for ((i = 0; i < 9; i++))
do
  	echo " 20.$i.lcc -> 20.$i.pcf2 " >> log.txt
        ./translate.sh ~/stablematch/gatetests/20.$i.lcc ~/stablematch/gatetests/20.$i.pcf2
done

for ((i = 0; i < 9; i++))
do
  	echo " 30.$i.lcc -> 30.$i.pcf2 " >> log.txt
        ./translate.sh ~/stablematch/gatetests/30.$i.lcc ~/stablematch/gatetests/30.$i.pcf2
done




