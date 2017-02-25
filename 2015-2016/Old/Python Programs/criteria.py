print("Enter five (5) numbers that are divisible by three (3) and five (5).")
count = 0
while count < 5:
	userin = int(input())
	if userin % 3 == 0 and userin % 5 == 0:
		count += 1
print("Congratulations!\nYou can go home now!")