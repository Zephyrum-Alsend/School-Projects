print("Hello World!")
num1, num2, num3 = input("Enter number 1: "), input("Enter number 2: "), input("Enter number 3: ")
if int(num1) % 2 != 0 and num1 >= num2 and num1 >= num3:
	print(num1, "is the greatest odd number entered.")
elif int(num2) % 2 != 0 and num2 >= num1 and num2 >= num3:
	print(num2, "is the greatest odd number entered.")
elif int(num3) % 2 != 0 and num3 >= num1 and num3 >= num2:
	print(num3, "is the greatest odd number entered.")
else:
	print("How odd... No numbers were not even.")