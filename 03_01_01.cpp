#include<iostream>

using namespace std;
template<class T>
int binarySearch(T a[], int n, const T& x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x == a[middle])return middle;
		if (x > a[middle])left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}
int main()
{

	return 0;
}