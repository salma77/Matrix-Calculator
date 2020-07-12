#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
int main()
{
	int row1 = 1, col1 = 1, row2 = 1, col2 = 1, i, j;
	float matrix1[100][100];
	float matrix2[100][100];
	string s1 = "", s2 = "", ans, space = " ";
	char op;
	getline(cin, s1);
	cin >> op;
	cin.ignore();
	getline(cin, s2);


	//to get number of columns and rows of the first matrix 
	for (i = 0; i < s1.length(); i++) {
		if (s1[i] == ';')
			row1++;
		if (s1[i] == ' ' && row1 == 1)
			col1++;
	}

	//filling the matrix
	//we delete the first [ ]
	//and add space to make a general case
	s1.erase(0, 1);
	s1.erase(s1.length() - 1, 1);
	s1 += " ";
	//to parse the string
	while (s1.length() != 0) {
		for (i = 0; i < row1; i++) {
			for (j = 0; j < col1; j++) {
				//we find the space and create a sub string from the beginning to that space

				int space1 = s1.find(" ");
				string element1 = s1.substr(0, space1);
				//to handle the ;
				if (s2.find(";") != -1) {
					int found = s2.find(";");
					s2.replace(found, 1, " ");

				}
				float num1 = atof(element1.c_str());
				matrix1[i][j] = num1;
				//erase the element after adding it to the matrix
				s1.erase(0, space1);
			}
		}
	}
	//to get number of columns and rows of the second matrix 

	for (i = 0; i < s2.length(); i++) {
		if (s2[i] == ';')
			row2++;
		if (s2[i] == ' ' && row2 == 1)
			col2++;
	}

	// the second matrix
	s2.erase(0, 1);
	s2.erase(s2.length() - 1, 1);
	s2 += " ";
	//to parse the string
	while (s2.length() != 0) {
		for (i = 0; i < row2; i++) {
			for (j = 0; j < col2; j++) {
				//we find the space and create a sub string from the beginning to that space

				int space2 = s2.find(" ");
				string element2 = s2.substr(0, space2);
				//to handle the ;
				if (s2.find(";") != -1) {
					int found = s2.find(";");
					s2.replace(found, 1, " ");

				}
				float num2 = atof(element2.c_str());
				matrix2[i][j] = num2;
				//erase the element after adding it to the matrix
				s2.erase(0, space2);
			}
		}

	}

	//operations
	if (row1 == row2 && col1 == col2) {

		if (op == '+')
			add(matrix1, matrix2, row1, col1);
		else if (op == '-')
			subtract(matrix1, matrix2, row1, col1);

	}
	else
		cout << "ERROR";

	if (col1 == row2 && op == '*') {

		multiply(matrix1, matrix2, row1, col1);
	}
	else
		cout << "ERROR";

	return 0;
}