./translate.sh ~/stablematch/lccprogs/galelimited.4.mult.lcc ~/stablematch/pcf2/4.mult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.10.mult.lcc ~/stablematch/pcf2/10.mult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.25.mult.lcc ~/stablematch/pcf2/25.mult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.50.mult.lcc ~/stablematch/pcf2/50.mult.pcf2
./simulate.sh ~/stablematch/pcf2/4.mult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/10.mult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/25.mult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/50.mult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input

./translate.sh ~/stablematch/lccprogs/galelimited.4.nomult.lcc ~/stablematch/pcf2/4.nomult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.10.nomult.lcc ~/stablematch/pcf2/10.nomult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.25.nomult.lcc ~/stablematch/pcf2/25.nomult.pcf2
./translate.sh ~/stablematch/lccprogs/galelimited.50.nomult.lcc ~/stablematch/pcf2/50.nomult.pcf2
./simulate.sh ~/stablematch/pcf2/4.nomult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/10.nomult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/25.nomult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input
./simulate.sh ~/stablematch/pcf2/50.nomult.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input

