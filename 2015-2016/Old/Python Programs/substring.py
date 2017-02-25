#hard way - there's an in function
def isIn(str1, str2):
	def subin (str1, str2):
		In = False
		for i in range(0, len(str2), 1):
			if str1 == str2[i:(i+len(str1))]:
				In = True
		return In

	if len(str1) == len(str2):
		if str1 == str2:
			return True
		else:
			return False
	elif len(str1) > len(str2):
		return subin(str2, str1)
	else:
		return subin(str1, str2)

#using in function
def isInn(str1, str2):
	if str1 in str2:
		return True
	elif str2 in str1:
		return True
	else:
		return False


def test_isIn(sample, sample2):
	if isIn(sample, sample2):
		print ("Test True.")
	else:
		print("Test False.")
	if isInn(sample, sample2):
		print ("Test True.")
	else:
		print("Test False.")
	print("")

test_isIn("Hello World", "Hello")
test_isIn("Hi", "Hi Bob")
test_isIn("Hi", "Bob Hi")
test_isIn("Hello", "Goodbye")
test_isIn("Goodbye", "Hello")
test_isIn("Hi", "Bob Hi Bye")
test_isIn("Hi", "Bob, hi and bye")