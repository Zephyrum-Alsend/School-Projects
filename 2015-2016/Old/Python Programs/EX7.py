def findRoot(power, num):
	"""Assumes power and num are integers greater than 0.
	Finds integer root within epsilon of num and returns it 
	or returns 0 if none exist."""
	epsilon = 0.001
	for n in range(num+1):
		if abs(n**power - num) <= epsilon:
			return n
	return 0

print(findRoot(3, 27))
print(findRoot(3, 9))
print(findRoot(2, 9))