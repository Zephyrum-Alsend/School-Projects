mini = 5000
maxi = -5000
sm = 0
term = 0

name_file = open('data.txt', 'r')
for p in name_file:
	q = float(p)
	if q > maxi:
		maxi = q
	if q < mini:
		mini = q
	sm += q
	term += 1
name_file.close()

print("The maximum temperature is:", maxi)
print("The minimum temperature is:", mini)
print("The average temeperature is:", (sm/term))