mass, miles = float(input("What is the mass of your package? (kg) ")), float(input("What is the distance to your destination? (miles) "))
if mass <= 2:
	rate = 1.1
elif mass <= 6:
	rate = 2.2
elif mass <= 10:
	rate = 3.7
elif mass <= 20:
	rate = 4.8
else:
	print("The deliveryman is overencumbered.")
	exit()
cost = rate * (miles / 500)
#"{0:.2f}".format( ) copied/incorporated from answer code; rounds to 2 decimals
print("The delivery fee will be", "{0:.2f}".format(cost), "$.")