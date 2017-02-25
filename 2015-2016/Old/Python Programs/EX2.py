grade = (input("Enter a grade: "))
if not grade.isdecimal() or int(grade) > 100 or int(grade) < 0:
	print("Invalid entry.")
	exit()
grade = int(grade)
if grade >= 90:
	print("A")
elif grade >= 80:
	print("B")
elif grade >= 70:
	print("C")
elif grade >= 60:
	print("D")
else:
	print("F")