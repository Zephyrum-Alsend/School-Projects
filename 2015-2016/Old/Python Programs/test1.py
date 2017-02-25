num = 0
maxOdd = 0
while num != -1:
	num = int(input("Enter a positive integer. Enter -1 to stop. "))
	if num % 2 != 0 and num > maxOdd:
		maxOdd = num
if maxOdd == 0:
	print("No odd numbers were entered.")
else:
	print(maxOdd, "is the largest odd number you entered.")