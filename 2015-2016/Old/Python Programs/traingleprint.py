row = 0
while row <= 2 or row >= 20:
	row = int(input("Enter an integer between 2 and 20. "))
for s in range(row):
	print('*'*(s+1))
for s in range(row-1, 0, -1):
	print('*'*s)