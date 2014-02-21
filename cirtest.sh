#!/bin/bash

python inpgen/inputgen.py $1 $2 $3 $4 > $1x$2x$3x$4.c.input && python inpgen/ctopcf.py < $1x$2x$3x$4.c.input > $1x$2x$4x$4.pcf2.input
./translate.sh testcircuit/galelimited.$1x$2x$3x$4.lcc testcircuit/galelimited.$1x$2x$3x$4.pcf2
./testcircuit/galelimited.$1x$2x$3x$4 $1x$2x$4x$4.c.input > ctest.out
./simulate.sh testcircuit/galelimited.$1x$2x$3x$4.pcf2 $1x$2x$3x$4.pcf2.input > pcftest.out
diff ctest.out pcftest.out >> log.txt
