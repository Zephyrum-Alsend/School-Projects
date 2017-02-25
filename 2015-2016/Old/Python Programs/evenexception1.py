def isEven(L):
	even = -1
	for x in L:
		if even == -1 and x % 2 == 0:
			even = x
	if even == -1:
		raise ValueError("No even numbers!")
	return even

def test_isEven():
	try:
		print(isEven([0, 1, 2, 3, 4]))
	except:
		print("No even numbers!")
	try:
		print(isEven([4, 3, 2, 1, 0]))
	except:
		print("No even numbers!")
	try:
		print(isEven([0, 1, 3, 5, 7]))
	except:
		print("No even numbers!")
	try:
		print(isEven([-1, -2, -3, -4]))
	except:
		print("No even numbers!")
	try:
		print(isEven([0]))
	except:
		print("No even numbers!")
	try:
		print(isEven([1]))
	except:
		print("No even numbers!")
	try:
		print(isEven([2]))
	except:
		print("No even numbers!")

	test_isEven()