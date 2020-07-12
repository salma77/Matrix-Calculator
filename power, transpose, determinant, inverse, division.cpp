#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
	int row1 = 1, col1 = 1, row2 = 1, col2 = 1, i, j, k, pow, counter1 = 0, counter2 = 0;
	float matrix1[100][100];
	float matrix2[100][100];
	float matrix_result[100][100];
	string mat1[600];
	string mat2[600];
	string s1, s2;
	char op;
	getline(cin, s1);
	cin >> op;
	cin.ignore();
	if (op == '^')
		cin >> pow;
	if (op == '/') {
		getline(cin, s2);


		for (i = 0; i < s2.length(); i++) {
			if (s2[i] == ';')
				row2++;
			if (s2[i] == ' ' && row2 == 1)
				col2++;
		}

		s2.erase(0, 1);
		s2.erase(s2.length() - 1, 1);
		s2 += " ";
		//to parse the string
		int len2 = s2.length();
		//to handle the ;
		for (i = 0; i < s2.length(); i++) {
			if (s2.find(";") != -1) {
				int found = s2.find(";");
				s2.replace(found, 1, " ");
			}
		}
		for (k = 0; k < len2 / 2; k++) {

			//we find the space and create a sub string from the beginning to that space

			int space2 = s2.find(" ");
			string element2 = s2.substr(0, space2);
			mat2[k] = element2;
			//erase the element after adding it to the matrix
			s2.erase(0, space2 + 1);

		}

		int c2 = 0;
		for (i = 0; i < row2; i++) {
			for (j = 0; j < col2; j++) {

				matrix2[i][j] = atof(mat2[c2].c_str());
				c2++;

			}
		}

	}


	int len1 = s1.length();
	//to get number of columns and rows
	for (i = 0; i < s1.length(); i++) {
		if (s1[i] == ';')
			row1++;
		if (s1[i] == ' ' && row1 == 1)
			col1++;
	}
	//to check on format of matrix
	int flag = 1;
	for (j = 0; j < len1; j++) {
		if (s1[j] == ' ')
			counter1++;
		if (s1[j] == ';') {
			if (counter1 != col1 - 1) {
				cout << "ERROR" << endl;
				flag = 0;
			}
			counter1 = 0;
		}
	}


	//filling the matrix
	//we delete the first [ ]
	//and add space to make a general case
	s1.erase(0, 1);
	s1.erase(s1.length() - 1, 1);
	s1 += " ";
	//to parse the string
	//to handle the ;
	for (i = 0; i < s1.length(); i++) {
		if (s1.find(";") != -1) {
			int found = s1.find(";");
			s1.replace(found, 1, " ");
		}
	}



	for (k = 0; k < len1 / 2; k++) {

		//we find the space and create a sub string from the beginning to that space

		int space1 = s1.find(" ");
		string element1 = s1.substr(0, space1);
		mat1[k] = element1;
		//erase the element after adding it to the matrix
		s1.erase(0, space1 + 1);

	}

	int c1 = 0;
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {

			matrix1[i][j] = atof(mat1[c1].c_str());
			c1++;

		}
	}


	//operations

	if (flag) {
		if (op == '^') {
			//power
			for (i = 0; i < row1; i++) {
				for (j = 0; j < col1; j++) {
					matrix2[i][j] = matrix1[i][j];
				}
			}
			if (row1 == col1) {
				for (i = 0; i < pow - 1; i++) {

					for (i = 0; i < row1; i++) {
						for (j = 0; j < row1; j++) {
							float sum = 0;
							for (k = 0; k < row1; k++) {
								sum += matrix1[i][k] * matrix2[k][j];
								matrix_result[i][j] = sum;
							}
						}
					}

				}
				cout << "[";
				for (i = 0; i < row1; i++) {
					for (j = 0; j < col1; j++) {
						cout << matrix_result[i][j];
						if (j != col1 - 1)
							cout << " ";
					}
					if (i != row1 - 1) {
						cout << ";";
					}
				}

				cout << "]" << endl;

			}
			else
				cout << "ERROR" << endl;
		}
		else if (op == 'T') {
			//transpose
			transpose(matrix1, row1, col1);

		}
		else if (op == 'D') {
			//  Determinant  
			if (row1 == col1) {
				cout << det(matrix1, row1) << endl;
			}
			else
				cout << "ERROR";
		}
		else if (op == 'I') {
			// inverse
			inverse(matrix1, matrix_result, row1);
		}
		else if (op == '/') {
			//division
			divide(matrix2, matrix_result, matrix1, row1);
		}
		else
			cout << "ERROR";
	}
	return 0;
}