salary, tenure = float(input("How much money do you make in a year? ")), float(input("How long have you worked at your job? "))
if salary > 60000 or (salary > 35000 and tenure >= 5):
	print("You qualify for the loan.")
else:
	print("You do not qualify for the loan.")