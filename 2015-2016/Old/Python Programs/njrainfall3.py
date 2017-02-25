def masterTable():
	filename = open('njrainfall.txt', 'r')
	#dummy string to allow use of .split()
	dummy = ''
	for i in filename:
		dummy += str(i)
	filename.close() #Never forget this!
	#Contains all data elements
	pseudoTable = dummy.split()
	#will contain all data elements formatted
	Table = {}
	while len(pseudoTable) > 0:
		tempList = []
		#Pops index 1 - 12, the monthly rain data
		for i in range(12):
			tempList.append( float(pseudoTable.pop(1)) )
		#pops index 0, the year, and stores it in the table
		Table[int(pseudoTable.pop(0))] = list(tempList)
		#clears tempList for next round
		del tempList[:]
	return Table

def monthNameToNumber(month):
	months = {'january': 1, 'february':2, 'march':3, 'april':4, 'may': 5, 'june':6, 'july':7, 'august':8, 'september':9, 'october':10, 'november':11, 'december':12}
	month = month.lower()
	for nam in months:
		if month in nam:
			return months[nam]
	raise IndexError

def rainfall(table):
	print("Eneter a year and month to recall the rain data of. \n(No Data before 1895 or after 2014)")
	y, m = int(input("Year: ")), input("Month: ")
	try:
		m = int(m)
	except ValueError:
		try:
			m = monthNameToNumber(m)
		except IndexError:
			print("Imaginary month entered! Defaulting to January.")
			m = 1
	summ = 0
	try:
		for i in table:
			summ += float(table[i][m-1])
	except IndexError:
		print("Imaginary month entered! Defaulting to January.")
		for i in table:
			summ += float(table[i][0])
	print("The average rainfall for this month is", (summ/len(table)), "inches.")
	try:
		print("The rainfall in", m, "/", y, "was", table[y][m-1], "inches.")
	except KeyError:
		print("No data on the year", y, ".")

rainfall(masterTable())