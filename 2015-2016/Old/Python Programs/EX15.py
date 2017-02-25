def charonly(str1):
	chars = 'abcdefghijklmnopqrstuvwxyz'
	str1 = str1.lower()
	str2 = ''
	for x in str1:
		if x in chars:
			str2 += x
	return str2

def ispalin(str1):
	if len(str1) <= 1:
		return True
	elif str1[0] == str1[-1]:
		return ispalin(str1[1:-1])
	else:
		return False

def ispalindrome(str1):
	return ispalin(charonly(str1))

print(ispalindrome("Dog god."))
print(ispalindrome("A"))
print(ispalindrome("Lemon nomel"))
print(ispalindrome("Melon nolem"))
print(ispalindrome("Lemon melon"))
print(ispalindrome("Lemon flavored melon."))