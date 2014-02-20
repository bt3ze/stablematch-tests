import fileinput
import sys

def process(line):
    if "[1]" in line or "[0]" in line:
        print line,

for line in fileinput.input():
    process(line)
