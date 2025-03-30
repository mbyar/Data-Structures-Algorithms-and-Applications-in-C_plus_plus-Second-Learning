#include<iostream>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
template<class T>
T sum(T a[], int n)
{
	T theSum = 0;
	return accumulate(a, a + n, theSum);
}
template<class T>
T product(T a[], int n)
{
	T theProduct = 1;
	return accumulate(a, a + n, theProduct, multiplies<T>());
}
template<class T>
void permutations(T list[], int k, int m)
{
	do
	{
		copy{ list, list + m + 1,ostream_iterator<T>(cout, "") };
		cout << endl;
	} while (next_permutation(list, list + m + 1));
}
int main()
{

	return 0;
}