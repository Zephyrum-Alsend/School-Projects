def gcd(num1, num2):
	if num1 > num2:
		if num1 % num2 == 0:
			return num2
		else:
			return gcd(num2, num1%num2)
	else:
		if num2 % num1 == 0:
			return num1
		else:
			return gcd(num1, num2%num1)

print(gcd(102, 68))
print(gcd(15, 30))
print(gcd(256, 200))