operation = input("Do you want to read or add an entry to the journal? (r/a) ")

if operation[0].lower() == 'a':
	name_file = open('journal.txt', 'a')
	print("Type QUIT on a new line to exit.")
	line = input()
	while line != "QUIT":
		name_file.write(line + '\n')
		line = input()
	name_file.close()
elif operation[0].lower() == 'r':
	name_file = open('journal.txt', 'r')
	for line in name_file:
		print(line[:-1])
	name_file.close()