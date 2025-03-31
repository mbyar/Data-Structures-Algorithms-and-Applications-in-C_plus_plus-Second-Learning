#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
template<typename T>
T my_accumulate3(T* s, T* e, T init)
{
	T count = init;
	for (T* i = s; i != e; i++)
		count += *i;
	return count;
}
template<typename T, typename F>
T my_accumulate4(T* s, T* e, T init, F func)
{
	T count = init;
	for (T* i = s; i != e; i++)
		func(count, *i);
	return count;
}
template<typename T>
void my_copy(T* s, T* e, T* t)
{
	for (T* i = s; i != e; i++,t++)
		*t = *i;
}
template<class T>
//void permutations(T list[], int k, int m)
//{
//	sort(list, list + m + 1);
//	do
//	{
//		copy( list, list + m + 1,ostream_iterator<T>(cout, "") );
//		cout << endl;
//	} while (next_permutation(list, list + m + 1));
//}
//void permutations(T list[], int k, int m)
//{
//	T* a = new T[m + 1 - k];
//	my_copy(list, list + m + 1, a);
//	do
//	{
//		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
//		cout << endl;
//	} while (next_permutation(list, list + m + 1));
//	prev_permutation(a, a + m + 1);
//	do
//	{
//		copy(a, a + m + 1, ostream_iterator<T>(cout, ""));
//		cout << endl;
//	} while (prev_permutation(a, a + m + 1));
//	delete[]a;
//}
void permutations(T list[], int k, int m)
{
	T* a = new T[m + 1 - k];
	my_copy(list, list + m + 1, a);
	do
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m + 1));
	do
	{
		copy(a, a + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m + 1) && !equal(list, list + m + 1, a));
	delete[]a;
}
int main()
{
	int a[4] = { 2,1,4,3 };
	permutations(a, 0, 3);
	return 0;
}