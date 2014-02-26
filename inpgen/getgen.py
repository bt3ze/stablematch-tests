import fileinput
import sys

buffer = []

i = 0
for line in fileinput.input():
	if i == 0:
		sys.stdout.write(line)
	i = i + 1
