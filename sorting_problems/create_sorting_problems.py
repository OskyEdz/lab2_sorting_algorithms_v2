import random
import sys

size = int(sys.argv[1])
min = int(sys.argv[2])
max = int(sys.argv[3])
outName = sys.argv[4]

unsorted = []
sorted = []
backward = []

for i in range(0,size+1):
	pick = random.randint(min,max)
	unsorted.append(pick)
	sorted.append(pick)
	backward.append(pick)

backward.sort()

fB = open("%s-backward" %(outName), "w")

for i in range(size, 0, -1):
	fB.write("%d\n" %(backward[i]))

fB.close()
	
sorted.sort()

fU = open("%s-problem" %(outName), "w")
fS = open("%s-solution" %(outName), "w")

for i in range(0, size):
	fU.write("%d\n" %(unsorted[i]))
	fS.write("%d\n" %(sorted[i]))

fU.close()
fS.close()
