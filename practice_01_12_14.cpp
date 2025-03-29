#include<iostream>
using namespace std;
template<typename T>
void make2dArray(T**& x, int numberOfRows, int* rowSize)
{
	x = new T * [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
	{
		x[i] = new T[rowSize[i]];
	}
}
template<typename T>
void changeLength1D(T*& x, int oldLength, int newLength)
{
	T* y = new T[newLength];
	int min = oldLength;
	if (newLength < oldLength)
		min = newLength;
	for (int i = 0; i < min; i++)
		y[i] = x[i];
	delete[]x;
	x = y;
}
template<typename T>
void changeLength2D(T**& x, int oldrows, int newrows, int oldcols, int newcols)
{
	T** y = new T * [newrows];
	for (int i = 0; i < newrows; i++)
	{
		y[i] = new T[newcols];
	}
	int rowmin = oldrows;
	int colmin = oldcols;
	if (newrows < rowmin)
		rowmin = newrows;
	if (newcols < colmin)
		colmin = newcols;
	for (int i = 0; i < rowmin; i++)
		for (int j = 0; j < colmin; j++)
			y[i][j] = x[i][j];
	for (int i = 0; i < oldrows; i++)
		delete[]x[i];
	delete[]x;
	x = y;
}
int main()
{

	return 0;
}