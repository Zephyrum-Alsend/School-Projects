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
	months = {'January': 1, 'Jan': 1, 'February':2, 'Feb':2, 'March':3, 'Mar':3, 'April':4,}

def rainfall(table):
	print("Eneter a year and month to recall the rain data of. \n(No Data before 1895 or after 2014)")
	x = int('abc')
	y, m = int(input("Year (YYYY): ")), input("Month (MM): ")
	summ = 0
	for i in table:
		summ += float(table[i][m-1])
	print("The rainfall in", m, "/", y, "was", table[y][m-1], "inches.")
	print("The average rainfall for this month is", (summ/len(table)), "inches.")

rainfall(masterTable())