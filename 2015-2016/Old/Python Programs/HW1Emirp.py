#Lucas Crockett
#HW1: Emirp - Programming Python
#Status: working

def isPrime(val):
	for n in range(2, val):
		if ( (val % n) == 0 ):
			return False
	return True	

def reverse(val):
	return int(str(val)[::-1])

def isEmirp(val):
	if isPrime(val) and isPrime( reverse(val) ):
		return True
	else:
		return False

#N is the number of Emirps to find
N = 0
while N <= 0:
	N = int(input("Enter a positive integer: "))

testNum = 2
count = 0			#counts number of Emirps found
lineBreak = count 	#for formatting rows
while count != N:
	if isEmirp(testNum):
		count += 1
		print(testNum, end="	")
	#when 5 Emirps are printed, start new row
	if count % 5 == 0 and lineBreak != count:
		print("")
		lineBreak = count
	testNum += 1