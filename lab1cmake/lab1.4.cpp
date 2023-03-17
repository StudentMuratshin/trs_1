#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void tridiagonal_matrix(const int n, const double* A, const double* B, const double* C, const double* D, double* X) {
	double* P = new double[n - 1];
	double* Q = new double[n];

	// forward
	P[0] = C[0] / B[0];
	Q[0] = D[0] / B[0];
	for (int i = 1; i < n; ++i) {
		if (i < n - 1) P[i] = C[i] / (B[i] - A[i] * P[i - 1]);
		Q[i] = (D[i] - A[i] * Q[i - 1]) / (B[i] - A[i] * P[i - 1]);
	}

	//backward
	X[n - 1] = Q[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		X[i] = Q[i] - P[i] * X[i + 1];
	}
	delete[] P;
	delete[] Q;
}

double f(double x)
{
	return cosh(x * 2);
}

int main() 
{
	ofstream X_4("C:\\Users\\PETA4\\Desktop\\3\\6_sem\\trs\\labs\\trs_1\\out\\X4_out.csv");
	int a = 0;
	int b = 1; 
	vector<double> N = { 11, 101, 1001, 10001 };
	for (int j = 0; j < N.size(); j++)
	{
		int n = N[j];
		double h = (b - a) / (double)n;
		double* K1 = new double[n];
		double* K2 = new double[n];
		double* K3 = new double[n];
		double* fi = new double[n];
		double* u = new double[n];

		K3[n-1] = K1[0] = 0;

		for (int i = 0; i < n; i++)
		{
			if (i != 0)
				K1[i] = 1. / (h * h) + 1. / h;
			K2[i] = -2. / (h * h) - 1. / h;
			if (i == n - 1)
				K2[i] = K2[i - 1] + K3[i - 1] * 1 / (h + 1);
			if (i != n - 1)
				K3[i] = 1 / (h * h);
			fi[i] = f(i * h);
		}

		tridiagonal_matrix(n, K1, K2, K3, fi, u);

		for (int i = 0; i < n; i++)
		{
			X_4 << i * h << " " << u[i] << endl;
		}

		delete[] K1;
		delete[] K2;
		delete[] K3;
		delete[] fi;
		delete[] u;
	}

	X_4.close();
}