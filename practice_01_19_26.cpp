#include<iostream>
using namespace std;
//int cal(int n)
//{
//	int count = 1;
//	for (int i = 2; i <= n; i++)
//		count *= i;
//	return count;
//}
//int Fibonacci(int n)
//{
//	if (n <= 2)
//		return 1;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int Fibonacci(int n)
//{
//	int a = 1, b = 1;
//	if (n <= 2)
//		return 1;
//	for (int i = 3; i <= 3; i++)
//	{
//		a = a + b;
//		b = a - b;
//	}
//	return a;
//}
//21,22,23,24太简单了，就不写了
void Subgen(int a[], int s, int e)
{
	if (s == e)
	{
		for (int i = 0; i < 2; i++)
		{
			a[s] = i;
			copy(a, a + s + 1, ostream_iterator<int>(cout, ""));
			cout << endl;
		}
	}
	else
	{
		for (int j = 0; j < 2; j++)
		{
			a[s] = j;
			Subgen(a, s + 1, e);
		}
	}
}
void graycode(int n)
{
	if (n == 1)
		cout<<"1 ";
	else
	{
		graycode(n - 1);
		cout << n << " ";
		graycode(n - 1);
	}
	
}
int main()
{
	graycode(4);
	return 0;
}