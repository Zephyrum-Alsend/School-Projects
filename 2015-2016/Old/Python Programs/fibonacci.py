def fibonacci(N):
	if N < 2:
		return 1
	else:
		return fibonacci(N-1) + fibonacci(N-2)

def test_fibonacci():
	if fibonacci(5) == 8:
		print("Test successful")
	else:
		print("Test returned", fibonacci(5))

	if fibonacci(8) == 34:
		print("Test successful")
	else:
		print("Test returned", fibonacci(8))

	if fibonacci(11) == 144:
		print("Test successful")
	else:
		print("Test returned", fibonacci(11))
test_fibonacci()