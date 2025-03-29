#include<iostream>
using namespace std;
int abc(int a, int b, int c)
{
	return a + b * c;
}
float abc(float a, float b, float c)
{
	return a + b * c;
}
template<class T>
T abc(T a, T b, T c)
{
	return a + b * c;
}
template<class T>
T abc(T& a, T& b, T& c)
{
	return a + b * c;
}
template<class T>
T abc(const T& a, const T& b, const T& c)
{
	return a + b * c;
}
template<class Ta,class Tb,class Tc>
Ta abc(const Ta& a, const Tb& b, const Tc& c)
{
	return a + b * c;
}
int main()
{

	return 0;
}