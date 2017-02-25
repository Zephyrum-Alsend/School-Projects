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
        if i >= key:
            return i == key
    return False


class Test:
    def __init__(self, name, algorithm):
        self.hits = 0
        self.elapsed_time = 0
        self.name = name
        self.algorithm = algorithm
    
    def __str__(self):
         return self.name + "\tFound " + str(self.hits) + " successfully in " + str(self.elapsed_time)  + " seconds"
    
    def run_test(self, data, keys):
        for key in keys:
            start = time.time()
            if self.algorithm(data, key):
                self.hits += 1
            end = time.time()
            self.elapsed_time += (end-start)
        

def make_random_list(max):
    data = []
    for i in range(0, max):
        data.append(random.randint(0,max))
    data.sort()
    return data


random.seed(time.time())
data = make_random_list(10000)
keys = make_random_list(10000)

tests = (
        Test("Linear, unordered", linear_find_unordered), 
        Test("Linear, ordered\t", linear_find_ordered), 
        Test("Binary Search\t", binary_search)
    )

for test in tests:
    test.run_test(data, keys)
    print(test)

