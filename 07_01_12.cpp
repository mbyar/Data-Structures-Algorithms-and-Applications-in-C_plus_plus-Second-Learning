#include<iostream>

using namespace std;
void test01()
{
	int numberOfRows = 5;
	int length[5] = { 6,3,4,2,7 };
	int** irregularArray = new int* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
		irregularArray[i] = new int[length[i]];
	irregularArray[2][3] = 5;
	irregularArray[4][6] = irregularArray[2][3] + 2;
	irregularArray[1][1] = 3;
	cout << irregularArray[2][3] << endl;
	cout << irregularArray[4][6] << endl;
	cout << irregularArray[1][1] << endl;
}
template<typename T>
class matrix
{
	friend ostream& operator<<(ostream&, const matrix<T>&);
public:
	matrix(int theRows = 0, int theColumns = 0);
	matrix(const matrix<T>&);
	~matrix() { delete[] element; }
	int rows()const { return theRows; }
	int columns()const { return theColumns; }
	T& operator()(int i, int j)const;
	matrix<T>& operator=(const matrix<T>&);
	matrix<T> operator+()const;
	matrix<T> operator+(const matrix<T>&)const;
	matrix<T> operator-()const;
	matrix<T> operator-(const matrix<T>&)const;
	matrix<T> operator*(const matrix<T>&)const;
	matrix<T>& operator+=(const T&);
private:
	int theRows, theColumns;
	T* element;
};
template<class T>
matrix<T>::matrix(int theRows, int theColumns)
{
	if (theRows < 0 || theColumns < 0)
		//throw illegalParameterValue("Rows and columns must be >= 0")
		;
	if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0))
		//throw illegalParameterValue("Either both or neigher rows and columns should be zero")
		;
	this->theRows = theRows;
	this->theColumns = theColumns;
	element = new T[theRows * theColumns];
}
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
	theRows = m.theRows;
	theColumns = m.theColumns;
	element = new T[theRows * theColumns];
	copy(m.element, m.element + theRows * theColumns, element);
}
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
	if (this != &m)
	{
		delete[]element;
		theRows = m.theColumns;
		theColumns = m.theColumns;
		element = new T[theRows * theColumns];
		copy(m.element, m.element + theRows * theColumns, element);
	}
	return *this;
}
template<class T>
T& matrix<T>::operator()(int i, int j)const
{
	if (i<1 || i>theRows || j<1 || j>theColumns)
		//throw matrixIndexOutOfBounds()
		;
	return element[(i - 1) * theColumns + j - 1];
}
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m)const
{
	if (theRows != m.theRows || theColumns != m.theColumns)
		//throw matrixSizeMismatch()
		;
	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < theRows * theColumns; i++)
		w.element[i] = element[i] + m.element[i];
	return w;
}
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m)const
{
	if (theColumns != m.theRows)
		//throw matrixSizeMismatch()
		;
	matrix<T> w(theRows, m.theColumns);
	int ct = 0, cm = 0, cw = 0;
	for (int i = 1; i <= theRows; i++)
	{
		for (int j = 1; j <= m.theColumns; j++)
		{
			T sum = element[ct] * m.element[cm];
			for (int k = 2; k <= theColumns; k++)
			{
				ct++;
				cm += m.theColumns;
				sum += element[ct] * m.element[cm];
			}
			w.element[cw++] = sum;
			ct -= theColumns - 1;
			cm = j;
		}
		ct += theColumns;
		cm = 0;
	}
	return w;
}
template<class T>
class diagonalMatrix
{
public:
	diagonalMatrix(int theN = 10);
	~diagonalMatrix() { delete[]element; }
	T get(int, int)const;
	void set(int, int, const T&);
private:
	int n;
	T* element;
};
template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{
	if (theN < 1)
		//throw illegalParameterValue("Matrix size must be > 0")
		;
	n = theN;
	element = new T[n];
}
template<class T>
T diagonalMatrix<T>::get(int i, int j)const
{
	if (i<1 || j<1 || i>n || j>n)
		//throw matrixIndexOutOfBounds()
		;
	if (i == j)
		return element[i - 1];
	else
		return 0;
}
template<class T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{
	if (i<1 || j<1 || i>n || j>n)
		//throw matrixIndexOutOfBounds()
		;
	if (i == j)
		element[i - 1] = newValue;
	else
		if (newValue != 0)
			//throw illegalParameterValue("nondiagonal elements must be zero")
			;
}
template<typename T>
class tridiagonalMatrix
{
public:
	T get(int i, int j)const;
protected:
	int n;
	T* element;
};
template<class T>
T tridiagonalMatrix<T>::get(int i, int j)const
{
	if (i<1 || j<1 || i>n || j>n)
		//throw matrixIndexOutOfBounds()
		;
	switch (i - j)
	{
	case 1:
		return element[i - 2];
	case 0:
		return element[n + i - 2];
	case -1:
		return element[2 * n + i - 2];
	default:
		return 0;
	}
}
template<typename T>
class lowerTriangularMatrix
{
public:
	void set(int i, int j, const T& newValue)
protected:
	int n;
	T* element;
};
template<class T>
void lowerTriangularMatrix<T>::set(int i, int j, const T& newValue)
{
	if (i<1 || j<1 || i>n || j>n)
		//throw matrixIndexOutOfBounds()
		;
	if (i >= j)
		element[i * (i - 1) / 2 + j - 1] = newValue;
	else
		if (newValue != 0)
			//throw illegalParameterValue("elements not in lower triangle must be zero")
			;
}
int main()
{
	test01();
	return 0;
}