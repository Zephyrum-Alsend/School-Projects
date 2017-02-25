def characters (str):
	str = str.lower()
	str2 = ''
	for i in range(len(str)):
		if str[i] in 'abcdefghijklmnopqrstuvwxyz':
			str2 += str[i]
	return str2

def palindrome (str):
	str = characters(str)
	if len(str) <= 1:
		return True
	else: 
		return str[0] == str[-1] and palindrome(str[1:-1])
	

def test_palindrome():
	if palindrome("Radar"):
		print("Radar is a palindrome")
	else:
		print("Test failure")
	if palindrome("No lemon, no melon."):
		print("No lemon, no melon. is a palindrome")
	else:
		print("Test failure")
	if palindrome("1234"):
		print("1234 is a plindrome")
	else:
		print("Test failure")
	if palindrome("dog god"):
		print("dog god is a palindrome")
	else:
		print("Test failure")
	if not palindrome("dogood"):
		print("dogood is not a palindrome")
	else:
		print("Test failure")
test_palindrome()