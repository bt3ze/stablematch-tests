echo "$1.12.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.12.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.123.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.123.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.1234.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.1234.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.12345.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.12345.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.123456.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.123456.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.$1234567.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.1234567.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt
echo "$1.12345678.pcf2" >> gatecounts.$1.12345678.txt
./simulate.sh ~/stablematch/gatetests/galelimited.$1.12345678.pcf2 ~/stablematch/tests/4x4x4x4.worst.pcf2.input >> gatecounts.$1.12345678.txt

