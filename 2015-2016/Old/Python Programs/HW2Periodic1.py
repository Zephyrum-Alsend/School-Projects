#Lucas Crockett
#HW2: Periodic Table - Programming Python
#Status: working

def build_periodic_table(filename="periodic_table.txt"):
	input_file = open(filename, 'r')
	table = dict()
	for element in input_file:
		tokens = element.split()
		table[tokens[2].upper()] = (tokens[1], int(tokens[0]), float(tokens[3]))
	input_file.close()
	return table

def symbolSearch(table, name):
	results = [(table[sym], sym) for sym in table if sym == name.upper()]
	if results == []:
		results = [(table[sym], sym) for sym in table if name.lower() in table[sym][0].lower()]
	return results

def massSearch(table, mini, maxi):
	results = [(table[sym], sym) for sym in table if mini <= table[sym][2] and table[sym][2] <= maxi]
	return results

def massCalc(table):
	mass = 0
	ele = ''
	while ele != '.':
		ele = input("Enter atomic symbol of element: ")
		if ele.isalpha():
			ele = ele.upper()
			if ele in table:
				x = ''
				while not x.isdecimal() and x != '.':
					x = input("Enter number of atoms of "+ele+" in molecule: ")
				if x != '.':
					mass += int(x)*(table[ele][2])
				else:
					break
			else:
				print("Unknown element in formula.\n")
				return None
	print("The molecular mass is", str(mass)+".\n")
	return None

#prints values in columns created with .ljust() and \n
def columnFormat(data):
	print("Z".ljust(10), "Element".ljust(17), "Sym.".ljust(5), "Mass")
	for x in range(len(data)):
			print ((str(data[x][0][1])+' ').ljust(10, '-'), (str(data[x][0][0])+' ').ljust(17, '-'), (str(data[x][1])+' ').ljust(5, '-'), data[x][0][2], "\n")

PeriodicTable = build_periodic_table()
command = 0
while command != '4':
	print("1) Search by symbol/name\n2) Search by atomic mass\n3) Molecular Mass Calculation\n4) Quit\n")
	command = input("Please enter your choice: ")
	if command == '1':
		columnFormat(symbolSearch(PeriodicTable, input("1) Search by symbol/name\n>>> ")))
	elif command == '2':
		columnFormat(massSearch(PeriodicTable, float(input("2) Search by atomic mass\nEnter minimum value.\n>>> ")), float(input("Enter maximum value.\n>>> "))))
	elif command == '3':
		print("3) Molecular Mass Calculation\nEnter '.' when done.\n")
		massCalc(PeriodicTable)