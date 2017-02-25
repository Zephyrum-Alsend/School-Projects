print("Enter -1 to stop.\nWill print out largest odd integer entered.")
entry = 0
max_odd = 0
while entry != -1:
	try:
		entry = int(input("Enter a positive integer: "))
		if entry < -1:
			print("Don't be negative.")
		elif entry % 2 != 0 and entry > max_odd:
			max_odd = entry
	except:
		print("Not a number!")
if max_odd == 0:
	print("No odd numbers entered.")
else:
	print(max_odd)