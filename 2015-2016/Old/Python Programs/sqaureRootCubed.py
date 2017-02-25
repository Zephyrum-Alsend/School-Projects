square = -1
while square < 0:
	square = float(input("Input a positive number to find the square root of: "))
Guess = 0
dif = 0.001
root = 0
while abs(square - root**2) >= dif and root <= square:
	root += dif**2
	Guess += 1
print("After", Guess, "guesses with Exhaustive Enumeration,", end=" ")
if abs(square - root**2) >= dif:
	print("the square root failed.")
else:
	print("the approximate square root is", root)
Guess = 0
low = 0
high = square
root = (high+low)/2
while abs(square - root**2) >= dif:
	Guess += 1
	if root**2 < square:
		low = root
	else:
		high = root
	root = (high+low)/2
print("After", Guess, "guesses with Bisection, the approximate square root is", root)
Guess, root = 0, square/2
while abs(square - root**2) >= dif:
	root = root - (((root**2) - square)/(2*root))
	Guess += 1
print("After", Guess, "guesses with Newton-Raphson, the approximate square root is", root)