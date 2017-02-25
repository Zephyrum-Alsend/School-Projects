def diaTop (row):
	for s in range(row):
		diaLine(row, s)
def diaBot (row):
	for s in range(row-2, -1, -1):
		diaLine(row, s)
def diaLine (row, space):
	print(" "*(row - 1 - space) + "*"*(2*space + 1))
def diamond (row):
	diaTop(row)
	diaBot(row)

row = 0
while row <= 0:
	row = int(input("Enter a positive integer: "))
diamond(row)