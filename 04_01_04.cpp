#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
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
void test01()
{
	int a[1000], step = 10;
	double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
	cout << "The worst-case time, in milliseconds, are" << endl;
	cout << "n \t Time" << endl;
	for (int n = 0; n <= 1000; n += step)
	{
		for (int i = 0; i < n; i++)
			a[i] = n - i;
		clock_t startTime = clock();
		insertionSort(a, n);
		double elapsedMillis = (clock() - startTime) / clocksPerMillis;
		cout << n << '\t' << elapsedMillis << endl;
		if (n == 100)step = 100;
	}
}
void test02()
{
	int a[1000], step = 10;
	double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
	cout << "The worst-case time, in milliseconds, are" << endl;
	cout << left << setw(8) << "n" << setw(16) << "Repetitions" << setw(16) << "Total Ticks" << setw(16) << "Time per Sort" << endl;
	for (int n = 0; n <= 1000; n += step)
	{
		long numberOfRepetitions = 0;
		clock_t startTime = clock();
		do
		{
			numberOfRepetitions++;
			for (int i = 0; i < n; i++)
				a[i] = n - i;
			insertionSort(a, n);
		} while (clock() - startTime < 1000);
		double elapsedMillis = (clock() - startTime) / clocksPerMillis;
		cout << left << setw(8) << n << setw(16) << numberOfRepetitions << setw(16) << elapsedMillis
			<< setw(16) << elapsedMillis / numberOfRepetitions
			<< endl;
		if (n == 100)step = 100;
	}
}
int main()
{
	long numberOfRepetitions = 0;
	clock_t elapsedTime = 0;
	do
	{
		numberOfRepetitions++;
		clock_t startTime = clock();
		//doSomething();
		elapsedTime += clock() - startTime;
	} while (elapsedTime < 1000);
	cout << "Time is (in ticks)"
		<< ((double)elapsedTime) / numberOfRepetitions
		<< endl;
	return (0);
}
void fastSquareMatrixMultiply(int** a, int** b, int** c, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
}
int main()
{
	//test01();
	//test02();
	//test03();
	return 0;
}
