valid = False
while valid == False:
	try:
		shipdat = (int(input("Enter package wieght (kg): ")), int(input("Enter destination distance (mi): ")))
		valid = True
	except:
		print("Invalid data entry.")
if shipdat[0] <= 2:
	print("The shipping fee is $", 1.1*(shipdat[1]/500))
elif shipdat[0] <= 6:
	print("The shipping fee is $", 2.2*(shipdat[1]/500))
elif shipdat[0] <= 10:
	print("The shipping fee is $", 3.7*(shipdat[1]/500))
elif shipdat[0] <= 20:
	print("The shipping fee is $", 4.8*(shipdat[1]/500))
else:
	print("The package is too heavy.")