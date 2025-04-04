#include<iostream>

using namespace std;
template<class T>
void matrixAdd(T** a, T** b, T** c, int numberOfRows, int numberOfColumns)
{
	for (int i = 0; i < numberOfRows; i++)
		for (int j = 0; j < numberOfColumns; j++)
			c[i][j] = a[i][j] + b[i][j];
}
template<class T>
void squareMatrixMultiply(T** a, T** b, T** c, int n)
{
	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			T sum = 0;
			for (int k = 0; k < n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
}
template<class T>
void matrixMultiply(T** a, T** b, T** c, int m, int n, int p)
{
	for(int i =0;i<m;i++)
		for (int j = 0; j < p; j++)
		{
			T sum = 0;
			for (int k = 0; k < n; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
}
template<class T>
bool minmax(T a[], int n, int& indexOfMin, int& indexOfMax)
{
	if (n < 1)return false;
	indexOfMin = indexOfMax = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[indexOfMin] > a[i])indexOfMin = i;
		if (a[indexOfMax < a[i]])indexOfMax = i;
	}
	return true;
}
template<class T>
bool minmax(T a[], int n, int& indexOfMin, int& indexOfMax)
{
	if (n < 1)return false;
	indexOfMin = indexOfMax = 0;
	for (int i = 1; i < n; i++)
		if (a[indexOfMin] > a[i])indexOfMin = i;
		else if (a[indexOfMax] < a[i])indexOfMax = i;
	return true;
}
template<class T>
int sequentialSearch(T a[], int n, const T& x)
{
	a[n] = x;
	int i;
	for (i = 0; a[i] != x; i++);
	if (i == n)return -1;
	return i;
}
void d(int x[], int n)
{
	int i;
	for (i = 0; i < n; i += 2)
		x[i] += 2;
	i = 1;
	while (i <= n / 2)
	{
		x[i] += x[i + 1];
		i++;
	}
}
int main()
{

	return 0;
}