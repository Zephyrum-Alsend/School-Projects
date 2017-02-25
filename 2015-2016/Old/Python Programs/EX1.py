count = 0
while count < 3:
	try:
		nums = [int(input("Enter number 1: ")), int(input("Enter number 2: ")), int(input("Enter number 3: "))]
		count = 3
	except:
		print("Not all input was of the integer variety!")
count = nums[0]
for i in range(len(nums)):
	if nums[i] % 2 != 0 and nums[i] > count:
		count = nums[i]
if count % 2 == 0:
	print("No numbers were odd!")
else:
	print(count, "is the largest odd number entered.")