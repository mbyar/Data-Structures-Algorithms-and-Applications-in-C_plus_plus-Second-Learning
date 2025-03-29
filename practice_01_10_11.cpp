#include<iostream>
using namespace std;
int abc(int a, int b, int c)
{
	if (a < 0 && b < 0 && c < 0)
		throw 1;
	if (a == 0 && b == 0 && c == 0)
		throw 2;
	return a + b * c;
}
template<typename T>
void count(T* a, int n, T value)
{
	if (n < 1)
		throw"There is a error";
	else
	{
		for (int i = 0; i++; i < n)
			a[i] = value;
	}
}
int main()
{
	try { cout << abc(-2, -1, -3) << endl; }
	catch (int e)
	{
		if (e == 1)
			cout << "a and b and c all smaller than zero" << endl;
		if (e == 2)
			cout << "a and b and c all equal to zero" << endl;
	}
	return 0;
}