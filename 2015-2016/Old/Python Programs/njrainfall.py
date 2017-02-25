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
	Table = []
	while len(pseudoTable) > 0:
		tempList = []
		#Pops index 1 - 12, the monthly rain data
		for i in range(12):
			tempList.append( float(pseudoTable.pop(1)) )
		#pops index 0, the year, and stores it with the rain data in a single tuple
		tupl = (int( pseudoTable.pop(0) ), list(tempList))
		#clears tempList for next round
		del tempList[:]
		Table.append(tupl)
	return Table

def rainfall(table):
	print("Eneter a year and month to recall the rain data of. \n(No Data before 1895 or after 2014)")
	y, m = int(input("Year (YYYY): ")), int(input("Month (MM): "))
	summ = 0
	for i in range(len(table)):
		if table[i][0] == y:
			print("The rainfall in", m, "/", y, "was", table[i][1][m-1], "inches.")
		summ += float(table[i][1][m-1])
	print("The average rainfall for this month is", (summ/len(table)), "inches.")

rainfall(masterTable())