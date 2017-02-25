def removeDuplicates(list1):
	list2 = []
	for i in list1:
		if i not in list2:
			list2.append(i)
	del list1[:]
	list1.extend(list2)

list1 = [1, 1, 2, 2, 3, 3, 4, 5, 6, 6]
print (list1)
removeDuplicates(list1)
print (list1)