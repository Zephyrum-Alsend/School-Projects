valid = False
while valid == False:
	try:
		soceco = (int(input("Yearly Salary: ")), int(input("Years at job: ")))
		valid = True
	except:
		print("Invalid data entry.")
if soceco[0] > 60000 or (soceco[0] > 35000 and soceco[1] > 5):
	print("Qualified for loan.")
else:
	print("Unqualified for loan.")