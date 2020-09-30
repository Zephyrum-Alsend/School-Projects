class RainfallTable:
    def __init__(self, filepath):
        self.table = dict()
        try:
            f = open(filepath, 'r')
            for y in f:
                tokens = y.split()
                y = int(tokens[0])
                rainfall = [float(x) for x in tokens[1:]]
                self.table[y] = rainfall
                self.start = min(self.table.keys())
                self.end = max(self.table.keys())
            f.close()

        except:
            print("There was an error in creating the table.\n" +
                    "Please check the validity of the file.\n")
    
    def __str__(self):
        return "This is a rainfall table."

    ##########Part 1 Functions##########
    def get_rainfall(self, year, month):
        try:
            assert(1 <= month <= 12)
            rainfall = self.table[year][month - 1]
            return rainfall

        except:
            print("Date not available.")
            return 0

    def get_average_rainfall_for_month(self, month):
        try:
            assert(1 <= month <= 12)
            sum = 0.0
            for key in self.table:
                sum += self.table[key][month - 1]
            return sum / len(self.table)

        except:
            print("Month must be an integer in the range of 1 - 12.")
            return 0

    def get_min_year(self):
        return self.start

    def get_max_year(self):
        return self.end

    ##########Part 2 Functions##########
    def get_median_rainfall_for_month(self, month):
        try:
            assert(1 <= month <= 12)
            data = list()
            for key in self.table:
                data.append(self.table[key][month - 1])
            data.sort()
            return data[ len(data)//2 ]

        except:
            print("Month must be an integer in the range of 1 - 12.")
            return 0

    def get_average_rainfall_for_year(self, year):
        sum = 0.0
        try:
            for month in range(12):
                sum += self.table[year][month]
            return sum / 12
        except:
            print("Date not available.")
            return 0

    def get_median_rainfall_for_year(self, year):
        data = list()
        try:
            for month in range(12):
                data.append(self.table[year][month])
            data.sort()
            return data[ len(data)//2 ]
        
        except:
            print("Date not available.")
            return 0

    ##########Part 3 Functions##########
    def get_all_by_year(self, year):
        try:
            for month in range(1, 13):
                yield self.table[year][month]
        
        except:
            yield 0

    def get_all_by_month(self, month):
        try:
            for key in self.table:
                yield self.table[key][month-1]
        
        except:
            yield 0

    ##########Part 4 Functions##########
    def get_droughts(self):
        drought_duration_months = 2
        count = 0
        droughts = list()
        medians = list()
        st = str()
        en = str()

        for month in range(1, 13):
            medians.append(self.get_median_rainfall_for_month(month))

        for year in sorted(self.table):
            for month in range(12):
                if self.table[year][month] <= (0.95 * medians[month]):
                    if count == 0:
                        st = str(month + 1) + "/" + str(year)
                    elif count >= drought_duration_months:
                        en = str(month + 1) + "/" + str(year)
                    count += 1
                else:
                    if count > drought_duration_months:
                        droughts.append(st + " - " + en)
                    count = 0

        return droughts

##########MAIN##########
table = RainfallTable("njrainfall.txt")
print(table.get_rainfall(1993, 6))
print(table.get_average_rainfall_for_month(6))

for year in range(table.get_min_year(), table.get_max_year()+1) :
    print("Average rainfall in ", year, "=", table.get_average_rainfall_for_year(year))
    print("Median rainfall in ", year, "=", table.get_median_rainfall_for_year(year))
    print("===========")
    for rain in table.get_all_by_year(year):
        print(rain, end='\t')
    print("\n===========")


for month in range(1, 13) :
    print("Average rainfall in month", month, "=", table.get_average_rainfall_for_month(month))
    print("Median rainfall in month", month, "=", table.get_median_rainfall_for_month(month))
    print("===========")
    for rain in table.get_all_by_month(month):
        print(rain, end='\t')
    print("\n===========")

for d in table.get_droughts() :
    print("Drought:  ", d)
##########END##########