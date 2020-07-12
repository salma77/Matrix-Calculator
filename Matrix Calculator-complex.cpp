#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
int main()
{
	int row1 = 1, col1 = 1, row2 = 1, col2 = 1, i, j, k;
	float matrix1[100][100];
	float matrix2[100][100];
	float matrix3[100][100];
	float matrix4[100][100];
	float matrix_resultR[100][100];
	float matrix_resultI[100][100];

	string mat1[600];
	string mat2[600];
	string s1, s2;
	char op;
	getline(cin, s1);
	cin >> op;
	cin.ignore();
	getline(cin, s2);

	//to get number of columns and rows
	for (i = 0; i < s1.length(); i++) {
		if (s1[i] == ';')
			row1++;
		if (s1[i] == ' ' && row1 == 1)
			col1++;
	}
	for (i = 0; i < s2.length(); i++) {
		if (s2[i] == ';')
			row2++;
		if (s2[i] == ' ' && row2 == 1)
			col2++;
	}

	//filling the matrix
	//we delete the first [ ]
	//and add space to make a general case
	s1.erase(0, 1);
	s1.erase(s1.length() - 1, 1);
	s1 += " ";
	//to parse the string
	int len1 = s1.length();
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

	// the second matrix
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

	int c1 = 0;
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			if (mat1[c1].find("+") != -1) {
				int f = mat1[c1].find("+");
				string s1 = mat1[c1].substr(0, f);
				matrix1[i][j] = atof(s1.c_str());
				mat1[c1].erase(0, f);
				mat1[c1].erase(mat1[c1].length() - 1, 1);
				matrix3[i][j] = atof(mat1[c1].c_str());

			}
			else if(mat1[c1].find("i")!=-1){
				matrix1[i][j] = 0;
				mat1[c1].erase(mat1[c1].length() - 1, 1);
				matrix3[i][j] = atof(mat1[c1].c_str());
			}
			else {
				matrix1[i][j] = atof(mat1[c1].c_str());
				matrix3[i][j] = 0;
			}
			
			c1++;

		}
	}
	int c2 = 0;
	for (i = 0; i < row2; i++) {
		for (j = 0; j < col2; j++) {

			if (mat2[c2].find("+") != -1) {
				int f = mat2[c2].find("+");
				string s1 = mat2[c2].substr(0, f);
				matrix2[i][j] = atof(s1.c_str());
				mat2[c2].erase(0, f);
				mat2[c2].erase(mat2[c2].length() - 1, 1);
				matrix4[i][j] = atof(mat2[c2].c_str());

			}
			else if (mat2[c2].find("i") != -1) {
				matrix2[i][j] = 0;
				mat2[c2].erase(mat2[c2].length() - 1, 1);
				matrix4[i][j] = atof(mat2[c2].c_str());
			}
			else {
				matrix2[i][j] = atof(mat2[c2].c_str());
				matrix4[i][j] = 0;
			}
			c2++;

		}
	}

	//operations

	if (op == '+') {
		if (row1 == row2 && col1 == col2) {


			cout << "[";

			for (i = 0; i < row1; i++) {
				for (j = 0; j < col1; j++) {
					matrix_resultR[i][j]= matrix1[i][j] + matrix2[i][j];
					matrix_resultI[i][j] = matrix3[i][j] + matrix4[i][j];
					if(matrix_resultI[i][j]>0)
					cout << matrix_resultR[i][j]<<"+"<< matrix_resultI[i][j]<<"i";
					else if(matrix_resultI[i][j]<0)
						cout << matrix_resultR[i][j] << matrix_resultI[i][j] << "i";
					else if(matrix_resultI[i][j]=0)
						cout << matrix_resultR[i][j];
					if (matrix_resultR[i][j] = 0) 
						cout << matrix_resultI[i][j] << "i";
					
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
			cout << "ERROR";
	}
	else if (op == '-') {
		if (row1 == row2 && col1 == col2) {

			cout << "[";

			for (i = 0; i < row1; i++) {
				for (j = 0; j < col1; j++) {
					matrix_resultR[i][j] = matrix1[i][j] - matrix2[i][j];
					matrix_resultI[i][j] = matrix3[i][j] - matrix4[i][j];
					if (matrix_resultI[i][j] > 0)
						cout << matrix_resultR[i][j] << "+" << matrix_resultI[i][j] << "i";
					else if (matrix_resultI[i][j] < 0)
						cout << matrix_resultR[i][j] << matrix_resultI[i][j] << "i";
					else if (matrix_resultI[i][j] = 0)
						cout << matrix_resultR[i][j];
					if (matrix_resultR[i][j] = 0)
						cout << matrix_resultI[i][j] << "i";

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
			cout << "ERROR";
	}
	else if (op == '*') {
		if (row2 == col1) {

			for (i = 0; i < row1; i++) {
				for (j = 0; j < col2; j++) {
					float sum = 0;
					for (k = 0; k < row2; k++) {
						sum += matrix1[i][k] * matrix2[k][j];
						matrix_resultR[i][j] = sum;
					}
				}
			}
			cout << "[";
			for (i = 0; i < row1; i++) {
				for (j = 0; j < col2; j++) {
					cout << matrix_resultR[i][j];
					if (j != col2 - 1)
						cout << " ";
				}
				if (i != row1 - 1) {
					cout << ";";
				}
			}

			cout << "]";
		}
		else
			cout << "ERROR";
	}
	else
		cout << "ERROR";

	//system("pause");
	return 0;
}