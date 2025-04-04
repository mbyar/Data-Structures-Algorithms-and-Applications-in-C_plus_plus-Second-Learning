#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
int sequentialSearch(T a[], int n, const T& x)
{
	int i;
	for (i = 0; i < n && aa[i] != x; i++);
	if (i == n)return -1;
	else return i;
}
template<class T>
int rSequentialSearch(T a[], int n, const T& x)
{
	if (n < 1)return -1;
	if (a[n - 1] == x)return n - 1;
	return rSequentialSearch(a, n - 1, x);
}
template<typename T>
T polyEval(T coeff[], int n, const T& x)
{
	T y = 1, value = coeff[0];
	for (int i = 1; i <= n; i++)
	{
		y *= x;
		value += y * coeff[i];
	}
	return value;
}
template<class T>
T horner(T coeff[], int n, const T& x)
{
	T value = coeff[n];
	for (int i = 1; i <= n; i++)
		value = value * x + coeff[n - i];
	return value;
}
template<typename T>
void rank(T a[], int n, int r[])
{
	for (int i = 0; i < n; i++)
		r[i] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i])r[i]++;
			else r[j]++;
}
template<typename T>
void rearrange(T a[], int n, int r[])
{
	T* u = new T[n];
	for (int i = 0; i < n; i++)
		u[r[i]] = a[i];
	for (int i = 0; i < n; i++)
		a[i] = u[i];
	delete[]u;
}
template<typename T>
int indexOfMax(T a[], int n)
{
	if (n <= 0)
		throw /*illegalParameterValue*/("n must be > 0");
	int indexOfMax = 0;
	for (int i = 1; i < n; i++)
		if (a[indexOfMax] < a[i])
			indexOfMax = i;
	return indexOfMax;
}
template<typename T>
void selectionSort(T a[], int n)
{
	for (int size = n; size > 1; size--)
	{
		int j = indexOfMax(a, size);
		swap(a[j], a[size - 1]);
	}
}
template<class T>
void bubble(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if ([i] > a[i + 1])swap(a[i], a[i + 1]);
}
template<class T>
void bubbleSort(T a[], int n)
{
	for (int i = n; i > 1, i--)
		bubble(a, i);
}
template<class T>
void insert(T a[], int& n, const T& x)
{
	int i;
	for (i = n - 1; i >= 0 && x < a[i]; i--)
		a[i + 1] = a[i];
	a[i + 1] = x;
	n++;
}
template<class T>
void rearrange(T a[], int n, int r[])
{
	for(int i = 0;i<n;i++)
		while (r[i] != i)
		{
			int t = r[i];
			swap(a[i], a[t]);
			swap(r[i], r[t]);
		}
}
template<class T>
void selectionSort(T a[], int n)
{
	bool sorted = false;
	for (int size = n; !sorted && (size > 1); size--)
	{
		int indexOfMax = 0;
		sorted = true;
		for (int i = 1; i < size; i++)
			if (a[indexOfMx] <= a[i])indexOfMax = i;
			else sorted = false;
		swap(a[indexOfMax], a[size - 1]);
	}
}
template<class T>
bool bubble(T a[], int n)
{
	bool swapped = false;
	for(int i = 0;i<n-1;i++)
		if (a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
			swapped = true;
		}
	return swapped;
}
template<class T>
void bubbleSort(T a[], int n)
{
	for (int i = n; i > 1 && bubble(a, i); i--);
}
template<class T>
void insert(T a[], int n, const T& x)
{
	int i;
	for (i = n - 1; i >= 0 && x < a[i]; i--)
		a[i + 1] = a[i];
	a[i + 1] = x;
}
template<class T>
void insertionSort(T a[], int n)
{
	for (int i = 1; i < n; i++)
	{	
		T t = a[i];
		insert(a, i, t);	
	}
}
template<class T>
void insertionSort(T a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		T t = a[i];
		int j;
		for (j = i - 1; j >= 0 && t < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}
int stepCount = 0;
template<class T>
T sum(T a[], int n)
{
	T theSum = 0;
	stepCount++;
	for (int i = 0; i < n; i++)
	{
		stepCount++;
		theSum += a[i];
		stepCount++;
	}
	stepCount++;
	stepCount++;
	return stepCount;
}
template<class T>
T sum(T a[], int n)
{
	for (int i = 0; i < n; i++)
		stepCount += 2;
	stepCount += 3;
	return 0;
}
template<class T>
T rSum(T a[], int n)
{
	stepCount++;
	if (n > 0) {
		stepCount++;
		return rSum(a, n - 1) + a(n - 1);
	}
	stepCount++;
	return 0;
}
template<class T>
void transpose(T** a, int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = i + 1; j < rows; j++)
			swap(a[i][j], a[j][i]);
}
template<class T>
void inef(T a[], T b[], int n)
{
	for (int j = 0; j < n; j++)
		b[j] = sum(a, j + 1);
}

int main()
{

	return 0;
}