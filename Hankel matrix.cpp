#include <iostream>
using namespace std;

/*
 * This is needed for 2D arrays as the second dimension cannot be passed as variables
 */
#define n 6

/*
 * Takes in the matrix and their size and prints the matrix in the console
 */

void print(double A[][n], int M, int N)
{
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
			cout << (A[i][j]) << "\t";
		cout << endl;
	}
	cout << endl;
}

/*
 * Returns the average value of the diagonal elements when called
 * Runs for each element of the first row
 * and for the last elements of the subsequent rows
 */

double get_element(double A[][n], int M, int N, int i, int j)
{
	int value=0;
	double count=0;
	while(i<M && j>=0)
	{
		value += A[i][j];
		i++;
		j--;
		count++;
	}
	return value/count;
}

/*
 * Converts the input matrix into a Hankel matrix
 * In-place conversion
 * for row 0 the values are calculated once
 * for subsequent rows the values are just copied from the previous diagonal element
 * and computation is done again only for the last element
 */

void get_Hankel_matrix(double A[][n], int M, int N)
{
	int i=0;
	for(int j=0; j<N;j++)
	{
		A[i][j] = get_element(A,M,N,i,j);
	}

	for(i=1;i<M;i++)
	{
		for(int j=0; j<N; j++)
		{
			if(j==N-1)
				A[i][j] = get_element(A,M,N,i,j);
			else
				A[i][j] = A[i-1][j+1];
		}
	}

	print (A,M,N);
}

int main()
{
	double A[3][6] = {{2, 5, -1, 9, -3, 6}, {7, 4, 2, 4, 2, 10}, {3, -2, -10, 1, 4, 2}};
	int M = 3;
	int N = 6;

	if(N != n)
	{
		cout << "Change the second dimension in the code in #define n";
		return -1;
	}

	if(M==0 || N==0)
	{
		cout << "Dimensions can not be 0";
		return -1;
	}

	if(M>N)
		return -1;

	print(A,M,N);
	get_Hankel_matrix(A,M,N);

	return 0;
}


/*
P.S
to keep the dimensions as a variable, I tried using an alternate approach.

In this approach, I pass the address of the 1st element i.e. A[0][0] to my functions along with the dimensions.
	print(&A[0][0],M,N);
	get_Hankel_matrix(&A[0][0],M,N);

This way, my function definitions will be
	void get_Hankel_matrix(double *A, int M, int N)

However, I am failing in calculating the indices in the computation function.
	Here my accessing the 2D matrix goes as a simplified array index access.

	A[i][j] changes to A[i*M + j]
	But unfortunately somewhere I went wrong and was not able to generate a correct Hankel matrix.
	So, I am just submitting the simplified version where in the 2nd dimension is declared as a global constant.

*/
