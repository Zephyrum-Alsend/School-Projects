def diamond(row):
	diamondtop(row)
	diamondbot(row)

def diamondtop(row):
	for n in range(row+1):
		print('*'*n)

def diamondbot(row):
	for n in range(row-1):
		print('*'*(row-(n+1)))

try:
	diamond(int(input("Enter number of rows: ")))
except:
	print("Entry must be of integer type.")