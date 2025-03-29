#include<iostream>
using namespace std;
template<typename T>
bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
	try {
		x = new T * [numberOfRows];
		for (int i = 0; i < numberOfRows; i++)
			x[i] = new int[numberOfColumns];
		return true;
	}
	catch (bad_alloc) { return false; }
}
int main()
{
	float** x;
	make2dArray(x, 3, 3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			x[i][j] = 1.128;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}