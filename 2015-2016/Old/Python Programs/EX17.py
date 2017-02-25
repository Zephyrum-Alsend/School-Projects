def openJournal(filename, opp):
	if opp[0].lower() == 'a':
		appendJournal(filename)
	elif opp[0].lower() == 'r':
		readJournal(filename)
	else:
		print("Unrecognized command.")

def appendJournal(filename):
	File = open(filename, 'a')
	print("Type QUIT to save and exit.")
	inpu = ''
	while inpu != 'QUIT':
		File.write(inpu+'\n')
		inpu = input(">>> ")
	File.close()

def readJournal(filename):
	File = open(filename, 'r')
	print()
	for line in File:
		print(line, end="")
	File.close()

openJournal("journal.txt", input("Do you wish to add an entry or read written entries? "))