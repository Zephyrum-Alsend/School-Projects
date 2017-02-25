terms = int(input("Enter a number of terms to estimate PI to: "))
pi = 0
iterations = 1
for i in range(terms):
	pi += ( (-1)**(iterations+1) ) / ( (2*iterations) - 1 )
	iterations += 1
pi *= 4
print("PI is", pi)