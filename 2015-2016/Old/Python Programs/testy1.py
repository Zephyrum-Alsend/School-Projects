import time
import random

def binary_search(data, key):
    def bsearch(L, e, low, high):
        if high == low:
            return L[low] == e
        mid = (low + high)//2
        if L[mid] == e:
            return True
        elif L[mid] > e:
            if low == mid:
                return False
            else:
                return bsearch(L, e, low, mid-1)
        else:
            return bsearch(L, e, mid+1, high)

    if len(data) == 0:
        return False
    else:
        return bsearch(data, key, 0, len(data)-1)

def linear_find_unordered(data, key):
    for i in data:
        if i == key:
            return True;
    return False

def linear_find_ordered(data, key):
    for i in data:
        # The following isn't great, because now we have
        # two comparisons for each value instead of one - 
        # any performance gain we have from ending early 
        # is killed...
        #if i == key:
        #    return True;
        #if i > key:
            #return False

        # Instead, we write it a bit more cryptically, but we'll
        # see a performance increase roughly proportional to the number
        # of misses
        if i >= key:
            return i == key
    return False


gen_max = 10000
random.seed(time.time())
data = []
for i in range(0, gen_max):
    data.append(random.randint(0,gen_max))

data.sort()

hits_linear_unordered = 0
hits_linear_ordered = 0
hits_binary = 0
elapsed_time_linear_unordered = 0
elapsed_time_linear_ordered = 0
elapsed_time_binary = 0

keys = []
for i in range (0, gen_max):
    keys.append(random.randint(0, gen_max))

for key in keys:
    # test unordered linear search
    start = time.time()
    if linear_find_unordered(data, key):
        hits_linear_unordered += 1
    end = time.time()
    elapsed_time_linear_unordered += (end-start)

    # test linear, but ordered search
    start = time.time()
    if linear_find_ordered(data, key):
        hits_linear_ordered += 1
    end = time.time()
    elapsed_time_linear_ordered += (end-start)

    # test binary_search
    start = time.time()
    if binary_search(data, key):
        hits_binary += 1
    end = time.time()
    elapsed_time_binary += (end-start)

print("Linear Unordered:  Found", hits_linear_unordered, " successfully in", elapsed_time_linear_unordered, "seconds")
print("Linear Ordered:    Found", hits_linear_ordered, " successfully in", elapsed_time_linear_ordered, "seconds")
print("Binary:            Found", hits_binary, " successfully in", elapsed_time_binary, "seconds")