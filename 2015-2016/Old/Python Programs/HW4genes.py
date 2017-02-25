#Lucas Crockett
#Programming Python, HW4
#Status: Working

def askMotif():
	invalchar = True
	while invalchar:
		invalchar = False
		motif = input("Enter a motif.\n>>> ")
		if motif.isalpha():
			motif = motif.upper()
			for i in range(len(motif)):
				if not motif[i] in 'ATCG':
					invalchar = True
					print("Invalid characters entered.\nRe-", end="")
					break
		else:
			invalchar = True
			print("Invalid characters entered.\nRe-", end="")
	return motif

def askFrequencies():
	
	def askPercent(X):
		invalchar = True
		while invalchar:
			invalchar = False
			perc = input(X+"= ")

			#Will recognize and accept #.##, .##, ##% and ## formats
			if '.' in perc:
				try:
					perc = float(perc)
				except:
					invalchar = True
					print("Invalid entry.")
			elif perc.isdecimal():
				perc = float(perc)/100
			elif perc[-1] == '%':
				try:
					perc = float(perc[:-1])/100
				except:
					invalchar = True
					print("Invalid entry.")
			else:
				invalchar = True
				print("Invalid entry.")
		return perc

	print("Enter the frequencies of each nucleotide.")
	while True:
		Freq = (askPercent('A'), askPercent('T'), askPercent('C'), askPercent('G'))
		if sum(Freq) != 1.0:
			print("The frequencies must add up to 100%!")
		else:
			break
	return Freq


import matplotlib.pyplot as pylab
import random
class genome():
	def __init__(self, motif, frequencies):
		self.motif = motif
		self.freq = frequencies
		
		chance = 1
		for i in self.motif:
			if i == 'A':
				chance*=self.freq[0]
			elif i == 'T':
				chance*=self.freq[1]
			elif i == 'C':
				chance*=self.freq[2]
			else:
				chance*=self.freq[3]
		self.chance = chance
	
	def getProb(self, N):
		probability = 1 - (1 - self.chance)**N
		return probability
	
	def plotProb(self):
		proba = []
		n = len(self.motif)
		for N in range(5000 - n):
			proba.append(self.getProb(N + n))
		pylab.figure(1)
		pylab.plot(range(5000 - n), proba)
		pylab.axis([0, 5000, -0.1, 1.1])
		pylab.grid(True)
		pylab.title('Probability of Finding Motif')
		pylab.xlabel('Sequence Length')
		pylab.ylabel('Probability')
		pylab.show()
	
	def getRandSeq(self, N):
		sequence = ''
		A, T, C = self.freq[0], self.freq[0]+self.freq[1], self.freq[0]+self.freq[1]+self.freq[2]
		for n in range(N):
			ran = random.random()
			if ran < A:
				sequence += 'A'
			elif ran < T:
				sequence += 'T'
			elif ran < C:
				sequence += 'C'
			else:
				sequence += 'G'
		return sequence
	
	def findRandAvg(self, N):
		count = 0
		for n in range(100):
			index = -1
			rand = self.getRandSeq(N)
			while True:
				index = rand.find(self.motif, index+1)
				if index == -1:
					break
				else:
					count += 1
		return count/100
	
	def plotRand(self):
		yval = [self.findRandAvg(100), self.findRandAvg(1000), self.findRandAvg(2000), self.findRandAvg(5000), self.findRandAvg(10000)]
		pylab.figure(2)
		pylab.plot([100, 1000, 2000, 5000, 10000], yval, 'ro', markersize=50)
		pylab.title('Expected Instances of Motif')
		pylab.xlabel('Sequence Length')
		pylab.ylabel('Average Instances of Motif')
		pylab.grid(True)
		pylab.show()

	def __str__(self):
		return "Motif:\t"+self.motif+"\nFrequencies:\tA= "+str(self.freq[0]*100)+"%\tT= "+str(self.freq[1]*100)+"%\tC= "+str(self.freq[2]*100)+"%\tG= "+str(self.freq[3]*100)+"%\nProbability of Occurance:\t"+str(self.chance*100)+"%"


#Replace functions with a String "AGGT..." 
#and Tuple (A%, T%, C%, G%) to expedite testing.
#Beware: input error checks and corrections are 
#in the functions. The class itself does not 
#expect nor handle errors!
seq = genome(askMotif(), askFrequencies())
seq.plotProb()
seq.plotRand()
print(seq)