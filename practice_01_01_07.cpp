#include<iostream>
#include<cstddef>
using namespace std;
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
template<typename T, size_t N>
size_t count(const T(&a)[N]) {
	return N;
}
template<typename T>
void fill(T* a, int start, int end, const T& value)
{
	for (int i = start; i < end; i++)
		a[i] = value;
}
template<typename T>
T inner_product(T* a, T* b, int n)
{
	T value = 0;
	for (int i = 0; i < n; i++)
		value += a[i] * b[i];
	return value;
}
template<typename T>
void iota(T* a, const T& value, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = value + i;
}
template<typename T>
bool is_sorted(T* a, int size)
{
	int count = 0, equl = 0;
	if (size < 1)
	{
		cout << "The size is invalid" << endl;
		return false;
	}
	else if (size == 1)
		return true;
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (a[i + 1] - a[i] > 0)
				count++;
			else if (a[i + 1] - a[i] == 0)
				equl++;
			else
				count--;
		}
	}
	if (count < 0)
		count = -count;
	count += equl;
	if (count == size - 1)
		return true;
	else
		return false;
}
template<typename T>
int mismatch(T* a, T* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != b[i])
			return i;
	}
	return -1;
}
void test01()
{
	int a = 1, b = 2;
	swap(a, b);
	cout << a << b << endl;
}
void test02()
{
	int a[3] = { 1,2,3 };
	cout << count(a) << endl;
}
void test03()
{
	int a[10];
	fill(a, 0, 10, 0);
	fill(a, 1, 4, 3);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
}
void test04()
{
	int a[] = { 1,2,3 };
	int b[] = { 2,3,4 };
	cout << inner_product(a, b, 3) << endl;
}
void test05()
{
	int a[] = { 1,2,3 };
	iota(a, 1, 3);
	for (int i = 0; i < 3; i++)
		cout << a[i] << " ";
}
void test06()
{
	int a[] = { 1,1,2,2,3,4,5 };
	cout << is_sorted(a, 7);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}
