import sys
import time

ArgNum = 0
MaxArg = 2
files = list()
sequence = list()
alignseq = ["" for x in range(2)]

#Get start time
start = time.time()

#Read and open up to 2 file names
for i in sys.argv[1:]:
    print(i)
    files.append(open(i, 'r'))
    ArgNum += 1
    if ArgNum >= MaxArg:
        break
####

assert (ArgNum == MaxArg), "Improper usage. Expects [program [file1] [file2]]."

#Store sequences from *files* in *sequence*
for f in files:
    sequence.append(f.read().replace('\n', ''))
    f.close()
####

#Initialize *matrix* and *edits*
rows = len(sequence[0]) + 1
cols = len(sequence[1]) + 1
matrix = [[0 for x in range(cols)] for x in range(rows)]
edits = [[0 for x in range(cols)] for x in range(rows)]


#Generate first row and column of *matrix*
i = 0
for row in matrix:
    matrix[i][0] = i
    i += 1
####

i = 0
for col in matrix[0]:
    matrix[0][i] = i
    i += 1
####

#Generate *matrix* and *edits*
for i in range(1, len(matrix)):
    for j in range(1, len(matrix[i])):
        if sequence[0][i - 1] == sequence[1][j - 1]:
            matrix[i][j] = matrix[i - 1][j - 1]
            edits[i][j] = 0
        else:
            dl = matrix[i - 1][j] + 1
            ins = matrix[i][j - 1] + 1
            sub = matrix[i - 1][j - 1] + 1
            mini = min(dl, ins, sub)

            matrix[i][j] = mini

            if mini == dl:
                edits[i][j] = 1
            elif mini == ins:
                edits[i][j] = 2
            else:
                edits[i][j] = 0
####

#Generate aligned sequences from *edits*
i = rows - 1
j = cols - 1
while i > 0 and j > 0:
    if edits[i][j] == 1 or j <= 0:
        alignseq[0] = sequence[0][i - 1] + alignseq[0]
        alignseq[1] = "-" + alignseq[1]
        i -= 1
    elif edits[i][j] == 2 or i <= 0:
        alignseq[0] = "-" + alignseq[0]
        alignseq[1] = sequence[1][j - 1] + alignseq[1]
        j -= 1
    else:
        alignseq[0] = sequence[0][i - 1] + alignseq[0]
        alignseq[1] = sequence[1][j - 1] + alignseq[1]
        i -= 1
        j -= 1
####

print("\nInput sequences:")
for s in sequence:
    print(s)
####
print("\nAligned sequences:")
for s in alignseq:
    print(s)
####
print("\nThe minimum edit distance is " + str(matrix[-1][-1]))
print("Completed in " + str(time.time() - start) + " seconds.")