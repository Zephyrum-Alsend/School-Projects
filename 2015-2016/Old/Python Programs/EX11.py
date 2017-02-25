def pyramid(row):
	pyratop(row)
	pyrabot(row)

def pyratop(row):
	for x in range(row):
		print(" "*(row-x-1) + "*"*(2*x+1))

def pyrabot(row):
	for x in range(row-1):
		print(" "*(x+1) + "*"*(2*(row-x-2)+1))

pyramid(4)