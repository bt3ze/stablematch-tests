import random
import sys

S = int(sys.argv[1])
R = int(sys.argv[2])
SK = int(sys.argv[3])
RK = int(sys.argv[4])

def printprefs(n, k):
    for j in xrange(0,n):
        prefs = random.sample(range(0,n),k)
        for i in prefs:
            print hex(i)[2:],
        print ""

printprefs(S,SK)
print "-1" #max(S,R)
printprefs(R,RK)
