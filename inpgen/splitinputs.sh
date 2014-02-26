#!/bin/sh

python getgen.py < $1.pcf.input > $1.pcf.input.gen
python getevl.py < $1.pcf.input > $1.pcf.input.evl
