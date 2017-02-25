def test_isEven():
	t = isEven(L = [0, 1, 2, 3, 4])
	assert t == 0, "Expected 0, got "+str(t)
	t = isEven(L = [4, 3, 2, 1, 0])
	assert t == 4, "Expected 4, got "+str(t)	
	try:
		t = isEven(L = [9, 1, 3, 5, 7])
		assert False, "Should not be here..."
	except ValueError:
		print("Working as intended.")
	t = isEven(L = [-1, -2, -3, -4])
	assert t == -2, "Expected -2, got "+str(t)
	print("Done")

def isEven(L):
	for x in L:
		if x % 2 == 0:
			return x
	raise ValueError("No even numbers!")

test_isEven()