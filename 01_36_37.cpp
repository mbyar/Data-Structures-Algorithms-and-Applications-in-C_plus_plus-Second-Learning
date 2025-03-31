#include<iostream>
#include<cmath>
using namespace std;
void outputRoots(const double& a, const double& b, const double& c)
{
	double d = b * b - 4 * a * c;
	if (d > 0)
	{
		double sqrtd = sqrt(d);
		cout << "There are two real roots "
			<< (-b + sqrtd) / (2 * a) << " and "
			<< (-b - sqrtd) / (2 * a) << endl;
	}
	else if (d == 0)
		cout << "There is only one distinct root "
		<< -b / (2 * a) << endl;
	else
		cout << "The roots are complex"
		<< endl
		<< "The real part is "
		<< -b / (2 * a) << endl
		<< "The imaginary part is "
		<< sqrt(-d) / (2 * a) << endl;
}
template<typename T>
int indexOfMax(T a[], int n)
{
	if (n <= 0)
		throw /*illegalParameterValue*/("n must be > 0");
	int indexOfMax = 0;
	for (int i = 1; i < n; i++)
		if (a[indexOfMax] < a[i])
			indexOfMax = i;
	return indexOfMax;
}
int main()
{

	return 0;
}