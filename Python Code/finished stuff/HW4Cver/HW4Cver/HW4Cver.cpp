#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main(int argv, char ** argc) {
	fstream file1;
	fstream file2;
	string sequence1 = "";
	string sequence2 = "";
	string finalSeq1 = "";
	string finalSeq2 = "";

	if (argv >= 3) {
		cout << argc[1] << endl;
		file1.open(argc[1]);
		cout << argc[2] << endl;
		file2.open(argc[2]);
	}
	else {
		cerr << "Improper usage. Expects [program [file1] [file2]].\n";
		exit(1);
	}

	// Get start time
	int start = clock();

	// Extract *file1* into *sequence1*
	while (!file1.eof()) {
		string str;
		getline(file1, str);
		sequence1 += str;
	}
	// Reset flags and close
	file1.clear();
	file1.seekg(0, ios::beg);
	file1.close();

	// Extract *file2* into *sequence2*
	while (!file2.eof()) {
		string str;
		getline(file2, str);
		sequence2 += str;
	}
	// Reset flags and close
	file2.clear();
	file2.seekg(0, ios::beg);
	file2.close();

	// Initialize the *matrix* and *edits*
	size_t M = sequence1.length() + 1;
	size_t N = sequence2.length() + 1;
	vector< vector< int >> matrix(M, vector<int>(N));
	vector< vector< int >> edits(M, vector<int>(N));

	// Generate first row and column of *matrix*
	for (int i = 0; i < M; i++) {
		matrix[i][0] = i;
	}
	for (int i = 0; i < N; i++) {
		matrix[0][i] = i;
	}

	// Generate *matrix* and *edits*
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			// If the characters match
			if (sequence1[i - 1] == sequence2[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1];
				edits[i][j] = 0;
			}
			else {
				int del = matrix[i - 1][j] + 1;
				int ins = matrix[i][j - 1] + 1;
				int sub = matrix[i - 1][j - 1] + 1;
				// Find the minimum the three above values
				int mini = min({ del, ins, sub });

				matrix[i][j] = mini;

				// Determine the value to put in *edits*
				if (mini == del) {
					edits[i][j] = 1;
				}
				else if (mini == ins) {
					edits[i][j] = 2;
				}
				else {
					edits[i][j] = 0;
				}
			}
		}
	}

	
	// Create aligned sequences from *edits*
	for (int i = M - 1, j = N - 1; i > 0 && j > 0;) {
		if (edits[i][j] == 1 || j <= 0) {
			finalSeq1.insert(0, 1, sequence1[i - 1]);
			finalSeq2.insert(0, 1, '-');
			i -= 1;
		}
		else if(edits[i][j] == 2 || i <= 0) {
			finalSeq1.insert(0, 1, '-');
			finalSeq2.insert(0, 1, sequence2[j - 1]); 
			j -= 1;
		}
		else {
			finalSeq1.insert(0, 1, sequence1[i - 1]);
			finalSeq2.insert(0, 1, sequence2[j - 1]);
			i -= 1;
			j -= 1;
		}
	}

	// Output
	cout << "Input sequences:\n";
	cout << sequence1 << endl;
	cout << sequence2 << endl << endl;

	cout << "Aligned sequences:\n";
	cout << finalSeq1 << endl;
	cout << finalSeq2 << endl << endl;

	cout << "The minimum edit distance is " << matrix[M - 1][N - 1] << endl;

	int t = clock() - start;
	cout << "Completed in " << ((float)t) / CLOCKS_PER_SEC << " seconds." << endl;
}