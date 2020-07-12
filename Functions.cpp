void add(float matrix1[100][100], float matrix2[100][100], int row1, int col1) {
	int i, j;
	float matrix_result[100][100];
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	cout << "[";
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			if (j == col1)
				cout << matrix_result[i][j] << ";";
			else
				cout << matrix_result[i][j] << " ";
		}
	}
	cout << "]";

}
void subtract(float matrix1[100][100], float matrix2[100][100], int row1, int col1) {
	int i, j;
	float matrix_result[100][100];
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			matrix_result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	cout << "[";
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			if (j == col1)
				cout << matrix_result[i][j] << ";";
			else
				cout << matrix_result[i][j] << " ";
		}
	}
	cout << "]";

}
void multiply(float matrix1[100][100], float matrix2[100][100], int row1, int col1) {
	int i, j;
	float matrix_result[100][100];
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			int sum = 0;
			sum += matrix1[i][j] * matrix2[j][i];
			matrix_result[i][j] = sum;
		}
	}
	cout << "[";
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {
			if (j == col1)
				cout << matrix_result[i][j] << ";";
			else
				cout << matrix_result[i][j] << " ";
		}
	}
	cout << "]";

}
void transpose(float matrix1[100][100], int row1, int col1) {
	float matrix_result[100][100];

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			matrix_result[j][i] = matrix1[i][j];

		}
	}
	cout << "[";
	for (int i = 0; i < col1; i++) {
		for (int j = 0; j < row1; j++) {
			cout << matrix_result[i][j];
			if (j != row1 - 1)
				cout << " ";
		}
		if (i != col1 - 1) {
			cout << ";";
		}
	}

	cout << "]" << endl;
}
float det(float mat[100][100], int row) {
	float d = 0;
	float submat[100][100];

	if (row == 2)
		return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
	else
		for (int k = 0; k < row; k++) {
			int subi = 0;

			for (int i = 1; i < row; i++) {
				int subj = 0;

				for (int j = 0; j < row; j++) {
					if (j == k)
						continue;

					submat[subi][subj] = mat[i][j];
					subj++;
				}
				subi++;
			}
			d += pow(-1, k) * mat[0][k] * det(submat, row - 1);
		}
	return d;
}
void Cofactor(float mat1[100][100], float temp[100][100], int p, int q, int n)
{
	int i = 0, j = 0;

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{

			if (row != p && col != q)
			{
				temp[i][j++] = mat1[row][col];

				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

void adjoint(float mat1[100][100], float adj[100][100], int row1)
{

	int sign = 1;
	float temp[100][100];

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < row1; j++)
		{

			Cofactor(mat1, temp, i, j, row1);
			if ((i + j) % 2 == 0)
				sign = 1;
			else
				sign = -1;

			adj[j][i] = (sign) * (det(temp, row1 - 1));
		}
	}
}

void inverse(float mat1[100][100], float inverse[100][100], int row1)
{

	float d = det(mat1, row1);


	float adj[100][100];
	adjoint(mat1, adj, row1);

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {

			inverse[i][j] = adj[i][j] / d;

		}
	}
	cout << "[";
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {
			cout << inverse[i][j];
			if (j != row1 - 1)
				cout << " ";
		}
		if (i != row1 - 1) {
			cout << ";";
		}
	}

	cout << "]" << endl;

}

void divide(float mat1[100][100], float inverse[100][100], float mat2[100][100], int row1)
{
	int i, j, k;
	float d = det(mat1, row1);
	float matrix_result[100][100];

	float adj[100][100];
	adjoint(mat1, adj, row1);

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {

			inverse[i][j] = adj[i][j] / d;

		}
	}

	for (i = 0; i < row1; i++) {
		for (j = 0; j < row1; j++) {
			float sum = 0;
			for (k = 0; k < row1; k++) {
				sum += mat2[i][k] * inverse[k][j];
				matrix_result[i][j] = sum;
			}
		}
	}
	cout << "[";
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < row1; j++) {
			cout << matrix_result[i][j];
			if (j != row1 - 1)
				cout << " ";
		}
		if (i != row1 - 1) {
			cout << ";";
		}
	}

	cout << "]" << endl;

}