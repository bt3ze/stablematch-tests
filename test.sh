#!/bin/bash

python inpgen/inputgen.py 20 20 5 5 > 20x20x5x5.c && python inpgen/ctopcf.py < 20x20x5x5.c > 20x20x5x5.pcf2
./translate.sh testcircuit/galelimited.lcc testcircuit/galelimited.pcf2
./testcircuit/galelimited 20x20x5x5.c > ctest.out
./simulate.sh testcircuit/galelimited.pcf2 20x20x5x5.pcf2 > pcftest.out
diff ctest.out pcftest.out >> log.txt
