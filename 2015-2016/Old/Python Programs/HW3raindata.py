#Lucas Crockett
#Programming Python - Homework #3
#Status: Working

class RainfallTable:
	def __init__(self, filepath = "njrainfall.txt"):
		try:
			filename = open(filepath, 'r')
			table = {}
			for line in filename:
				temp = line.split()
				table[int(temp[0])] = []
				for num in range(len(temp)-1):
					table[int(temp[0])].append(float(temp[num+1]))
			filename.close()
			self.data = table
		except:
			print("No file found or file contains inappropriate data types.")
	
	def getRainfall(self, year, month):
		try:
			return self.data[year][month-1]
		except:
			return "No data for date specified."
	def getAvgRainfallMonth(self, month):
		try:
			assert month <= 12 and month >= 1
		except:
			return "Double check the month is a valid entry."
		Sum = 0
		for k in self.data:
			Sum += self.data[k][month-1]
		return Sum/len(self.data)
	def getMinYear(self):
		return min(self.data.keys())
	def getMaxYear(self):
		return max(self.data.keys())
	

	def getMedianRainfallMonth(self, month):
		try:
			assert month <= 12 and month >= 1
		except:
			return "Double check the month is a valid entry."
		data = []
		for k in self.data:
			data.append(self.data[k][month-1])
		data.sort()
		if len(data) % 2 == 0:
			return (data[len(data)//2] + data[(len(data)//2)-1])/2
		else:
			return data[len(data)//2]
	def getAvgRainfallYear(self, year):
		try:
			Sum = 0
			for d in self.data[year]:
				Sum += d
			return Sum/12
		except:
			return "No data for year specified."
	def getMedianRainfallYear(self, year):
		try:
			data = []
			for d in self.data[year]:
				data.append(d)
			data.sort()
			return (data[5] + data[6])/2
		except:
			return "No data for year specified."
	

	def getAllByYear(self, year):
		try:
			for d in self.data[year]:
				yield d
		except:
			yield "No data for year specified."
	def getAllByMonth(self, month):
		try:
			assert month <= 12 and month >= 1
			for k in self.data:
				yield self.data[k][month-1]
		except:
			yield "Double check the month is a valid entry."
	
	
	def getDroughts(self):
		MonthlyAvg = (self.getAvgRainfallMonth(1), self.getAvgRainfallMonth(2), self.getAvgRainfallMonth(3), self.getAvgRainfallMonth(4), self.getAvgRainfallMonth(5), self.getAvgRainfallMonth(6), self.getAvgRainfallMonth(7), self.getAvgRainfallMonth(8), self.getAvgRainfallMonth(9), self.getAvgRainfallMonth(10), self.getAvgRainfallMonth(11), self.getAvgRainfallMonth(12))
		count, start, origin, droughts = 0, '', self.getMinYear(), []
		for k in range(len(self.data)):
			for i in range(12):
				if self.data[origin + k][i] <= 0.95*MonthlyAvg[i] and count == 0:
					count += 1
					start = str(i+1)+"/"+str(origin + k)
				elif self.data[origin + k][i] <= 0.95*MonthlyAvg[i]:
					count += 1
				elif count >= 3:
					count = 0
					if i == 0:
						droughts.append(start+" - 12/"+str(origin + k - 1))
					else:
						droughts.append(start+" - "+str(i)+"/"+str(origin + k))
				else:
					count = 0
		return droughts


table = RainfallTable("D:/Python Programs/njrainfall.txt")
print(table.getRainfall(1993, 6))
print(table.getAvgRainfallMonth(6))

for year in range(table.getMinYear(), table.getMaxYear()+1) :
    print("Average rainfall in ", year, "=", table.getAvgRainfallYear(year))
    print("Median rainfall in ", year, "=", table.getMedianRainfallYear(year))
    print("===========")
    for rain in table.getAllByYear(year):
        print(rain, end='\t')
    print("\n===========")


for month in range(1, 13) :
    print("Average rainfall in month", month, "=", table.getAvgRainfallMonth(month))
    print("Median rainfall in month", month, "=", table.getMedianRainfallMonth(month))
    print("===========")
    for rain in table.getAllByMonth(month):
        print(rain, end='\t')
    print("\n===========")

for d in table.getDroughts() :
    print("Drought:  ", d)