print("Enter 5 numbers that are divisible by both 3 and 5.")
entries = []
while len(entries) < 5:
	x = int(input(">>> "))
	if x % 3 == 0 and x % 5 == 0:
		entries.append(x)
print(str(entries)[1:-1], "\nFinished.")