#!/bin/sh
python inputgen.py $1 $2 $3 $4 > $1x$2x$3x$4.c.input
python ctolcc.py < $1x$2x$3x$4.c.input > $1x$2x$3x$4.lcc.input
python ctopcf.py < $1x$2x$3x$4.c.input > $1x$2x$3x$4.pcf.input
