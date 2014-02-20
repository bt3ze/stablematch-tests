import fileinput
import sys

buffer = []

def emptybuf(bffr):
    while len(bffr) > 0:
        sys.stdout.write("{0:0>3}".format(hex(bffr.pop())[2:]))
    print ""    

def process(line):
    if len(line.split(" ")) < 2:
        emptybuf(buffer)
    else:
        for num in line.strip().split(" "):
            buffer.append(int(num.strip(),16))
#    buffer.push()

for line in fileinput.input():
    process(line)
emptybuf(buffer)
