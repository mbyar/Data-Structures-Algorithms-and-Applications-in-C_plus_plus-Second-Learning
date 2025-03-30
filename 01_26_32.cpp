#include<iostream>
using namespace std;
class illegalParameterValue
{
public:
	illegalParameterValue():
		message("Illegal parameter value"){}
	illegalParameterValue(const char* theMessage)
	{
		message = theMessage;
	}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};
int abc(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		throw illegalParameterValue("All parameters should be > 0");
	return a + b * c;
}
int factorial(int n)
{
	if (n <= 1)return 1;
	else return n * factorial(n - 1);
}
template<typename T>
T sum(T a[], int n)
{
	T theSum = 0;
	for (int i = 0; i < n; i++)
		theSum += a[i];
	return theSum;
}
template<typename T>
T rSum(T a[], int n)
{
	if (n > 0)
		return rSum(a, n - 1) + a[n - 1];
	return 0;
}
template<typename T>
void permutations(T list[], int k, int m)
{
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	}
	else
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
}
void test01()
{
	int a[3] = { 3,2,1 };
	permutations(a, 0, 2);
}
int main()
{
	/*try { cout << abc(2, 0, 4) << endl; }
	catch (illegalParameterValue e)
	{
		cout << "The parameters to abc were 2, 0, and 4" << endl;
		cout << "illegalParameterValue exception thrown" << endl;
		e.outputMessage();
		return 1;
	}*/
	test01();
	return 0;
}