def gcd (p, q):
	if p > q:
		if p % q == 0:
			return q
		else:
			return gcd(q, p % q)
	else: 
		if q % p == 0:
			return p
		else:
			return gcd(p, q % p)

def test_gcd ():
	if gcd(35, 15) == 5:
		print("Test successful")
	else:
		print("GCD of 35 and 15 returned as", gcd(35, 15))

	if gcd(6, 9) == 3:
		print("Test successful")
	else:
		print("GCD of 6 and 9 returned as", gcd(6, 9))

	if gcd(102, 68) == 34:
		print("Test successful")
	else:
		print("GCD of 102 and 68 returned as", gcd(102, 68))
test_gcd()