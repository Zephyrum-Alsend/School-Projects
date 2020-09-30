#Lucas Crockett
#Advanced Topics: Python
#Homework 1
#Status: Working

import math

#finds out if x is prime
def isPrime(x):
    y = math.ceil(x**(0.5))
    if x == 2:
        return True
    for i in range(2, y+1):
        if (x % i) == 0:
            return False
    return True

#reverses a number x
def reverse(x):
    return int(str(x)[::-1])

#finds first x Emirps
def findEmirp(x):
    num = 2
    i = 0
    while i < x:
        if (isPrime(num) and isPrime(reverse(num))):
            i += 1
            if i % 5 == 0:
                print(num)
            else:
                print(num, end='\t')
        num += 1

#asks the user for an positive integer value
def getUserInt():
    inputNotInt = True
    while inputNotInt:
        user = input('Enter a positive integer, any positive integer: ')
        try:
            val = int(user)
            if val > 0:
                inputNotInt = False
        except:
            print('INTEGER.')
    return val

#START OF MAIN

findEmirp(getUserInt())