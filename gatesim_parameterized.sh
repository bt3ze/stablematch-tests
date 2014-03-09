echo "0.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.0.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "1.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.1.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "12.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.12.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "123.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.123.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "1234.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.1234.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "12345.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.12345.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "123456.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.123456.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "1234567.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.1234567.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt
echo "12345678.$1x$2x$3x$4.pcf2" >> gatecounts.$1x$2x$3x$4.txt
./simulate.sh ~/stablematch/gatetests/galelimited.12345678.$1x$2x$3x$4.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1x$2x$3x$4.txt

