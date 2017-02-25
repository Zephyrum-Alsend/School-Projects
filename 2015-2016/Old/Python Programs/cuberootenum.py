cube = int(input("Enter a number and I'll calculate the integer cube root. If it exists. "))
root = 0
while root**3 < abs(cube):
	root += 1
if root**3 > abs(cube):
	print(cube, "has no integer cube root!")
else:
	if cube < 0:
		root = -root
	print("The cube root of", cube, "is", root)