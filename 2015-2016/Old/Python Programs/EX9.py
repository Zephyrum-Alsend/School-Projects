def findPI(term):
	pi = 0
	for x in range(term+1):
		pi += (-1)**x / (1 + 2*x)
	pi *= 4
	return pi

print(findPI(10))
print(findPI(100))
print(findPI(1000))
print(findPI(10000))
print(findPI(100000))
print(findPI(1000000))