#Lucas Crockett
#Python, HW5
#Status: Working

import matplotlib.pyplot as pylab
import random

#Promptsthe user to enter a nucleotide sequence.
def getUserSeq():
    inputNotVal = True
    while inputNotVal:
        user = input('Enter the nucleotide sequence: ')
        if validString(user):
            inputNotVal = False
        else:
            print('Invalid character detected. Enter sequence again.')
    return user
####

#Checks if a nucleotide seuqence, *seq*, contains only valid characters.
def validString(seq):
    validChar = "ATCG"
    
    if not seq:
        return False

    for c in seq:
        if c not in validChar:
            return False
    return True
####

#Prompts the user to enter frequencies for each letter.
def getUserFrq():
    sum = 0
    A = T = C = G = 0.0
    while not (abs(sum - 1) < 0.00001):
        print('Enter the frequencies of each nucleotide as decimals.')
        try:
            A = float(input('A = '))
            T = float(input('T = '))
            C = float(input('C = '))
            G = float(input('G = '))
            sum = A + T + C + G
        except:
            print('Non-numeric input detected.')
    return (A, T, C, G)
####

#Given a nucleotide, *seq*, and chances of each letter occuring, *freq*,
#calculate and return the chance of finding the nucleotide.
def computeOccuranceChance(seq, freq):
    chance = 1

    for c in seq:
        if c == 'A':
            chance *= freq[0]
        elif c == 'T':
            chance *= freq[1]
        elif c == 'C':
            chance *= freq[2]
        elif c == 'G':
            chance *= freq[3]

    return chance
####

#Generates X and Y coordinates for a graph and creates it.
def createChart(seq, prob):
    L = len(seq)
    X = [x for x in range(5000) if x > L]
    Y = [(1 - (1 - prob)**y) for y in X]

    pylab.figure(1)
    pylab.plot(X, Y)
    pylab.xlabel('Sequence Length')
    pylab.ylabel('Probability of finding at least one motif')
    pylab.show()
####

#Returns a string of length *length*, with characters randomly assigned
#according to the chances contained in *freq*.
def generateString(freq, length):
    string = ''
    
    for i in range(length):
        r = random.random()
       
        if r < freq[0]:
            string += 'A'
        elif (r - freq[0]) < freq[1]:
            string += 'T'
        elif (r - (freq[0] + freq[1])) < freq[2]:
            string += 'C'
        else:
            string += 'G'
    
    return string
####

#Generates X and Y coordinates for a scatterplot and creates it.
def createScatterPlot(seq, freq):
    X = [100, 1000, 2000, 5000, 10000]
    Y = [computeAverage(generateData(seq, freq, y)) for y in X]

    pylab.figure(2)
    pylab.plot(X, Y, 'ro')
    pylab.xlabel('Sequence Length')
    pylab.ylabel('Average number of motif found')
    pylab.show()
####

#Takes a string (*string*) and substring (*seq*) and returns the number of
#times *seq* appears in *string*.
def analyzeString(seq, string):
    index = -1
    count = -1

    while True:
        index = string.find(seq, index + 1)
        count += 1
        if index == -1:
            break
    
    return count
####

#Creates a list containing how many times *seq* was found in randomly
#generated string of length *length* over 100 tests.
def generateData(seq, freq, length):
    rawData = []

    for i in range(100):
        rawData.append( analyzeString(seq, generateString(freq, length)) )

    return rawData[:]
####

#Accepts a list, *L*, as an argument and computes the average of its values.
def computeAverage(L):
    sum = 0

    for i in L:
        sum += i
    
    sum /= len(L)
    
    return sum
####

####MAIN####
motif = getUserSeq()
chances = getUserFrq()
probablity = computeOccuranceChance(motif, chances)
print("The probability of appearing in sequence N = "
        + str(len(motif)) + " is " + str(probablity))
createChart(motif, probablity)
createScatterPlot(motif, chances)