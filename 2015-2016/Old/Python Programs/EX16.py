def storeFile(filename):
	FileName = open(filename, 'r')
	returning = []
	for elements in FileName:
		returning.append(int(elements))
	FileName.close()
	return returning

def findMinMax(values):
	values.sort()
	MinMax = (values[0], values[-1])
	return MinMax

def findAvg(values):
	Sum = 0
	for num in values:
		Sum += num
	return (Sum / len(values))

File = storeFile("data.txt")
MinMax = findMinMax(File)
print(MinMax[0],"\n", MinMax[1], "\n", findAvg(File))