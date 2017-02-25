# we'll see more about imports later on....
import time


n = int(input("Enter N:  "))
ans = 1

# convert to float to use as input to fact function
old_n = n

# get current time (clock ticks since Jan 1 1970)
start = time.time()
while n > 0:
    ans *= n
    n-= 1

end = time.time()
print("Answer is:  " , ans)
print("Computed iteratively in ", end-start, " seconds")


def fact(n):
    if n == 1: 
        return 1
    else :
        return n * fact(n-1)

start = time.time()
ans = fact(old_n)
end = time.time()
print("Answer is:  " , ans)
print("Computed recursively in ", end-start, " seconds")