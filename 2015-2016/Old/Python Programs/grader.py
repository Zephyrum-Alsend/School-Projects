#You can do a lot in one line of code
grade = float(input("Enter a grade (0 - 100, incase you forgot): "))
if grade > 100 or grade < 0:
	print("Out of Bounds")
	exit()
elif 90 <= grade:
	print("A")
elif 80 <= grade:
	print("B")
elif 70 <= grade:
	print("C")
elif 60 <= grade:
	print("D")
else:
	print("F")