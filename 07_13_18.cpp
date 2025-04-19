#include<iostream>

using namespace std;
template<class T>
class arrayList
{
public:

private:

};
template<class T>
class sparseMatrix
{
public:
	void transpose(sparseMatrix<T>& b);
	void add(sparseMatrix<T>& b, sparseMatrix<T>& c);
private:
	int rows, cols;
	arrayList<sparseMatrix<T>> terms;
};
template<class T>
ostream& operator<<(ostream& out, sparseMatrix<T>& x)
{
	out << "rows = " << x.rows << " columns = " << x.cols << endl;
	out << "nonzero terms = " << x.terms.size() << endl;
	for (arrayList<sparseMatrix<T>>::iterator i = x.terms.begin(); i != x.terms.end(); i++)
		out << "a(" << (*i).row << ',' << (*i).col << ") = " << (*i).value << endl;
	return out;
}
template<class T>
istream& operator>>(istream& in, sparseMatrix<T>& x)
{
	int numberOfTerms;
	cout << "Enter number of rows, columns, and #terms" << endl;
	in >> x.rows >> x.cols >> numberOfTerms;
	x.terms.reSet(numberOfTerms);
	sparseMatrix<T> mTerm;
	for (int i = 0; i < numberOfTerms; i++)
	{
		cout << "Enter row, column, and value of term " << (i + 1) << endl;
		in >> mTerm.row >> mTerm.col >> mTerm.value;
		x.terms.set(i, mTerm);
	}
	return in;
}
template<class T>
void sparseMatrix<T>::transpose(sparseMatrix<T>& b)
{
	b.cols = rows;
	b.rows = cols;
	b.terms.reSet(terms.size());
	int* colSize = new int[cols + 1];
	int* rowNext = new int[cols + 1];
	for (int i = 1; i <= cols; i++)
		colSize[i] = 0;
	for (arrayList<matrixTerm<T>>::iterator i = terms.begin(); i != terms.end(); i++)
		colSize[(*i).col]++;
	rowNext[1] = 0;
	for (int i = 2; i <= cols; i++)
		rowNext[i] = rowNext[i - 1] + colSize[i - 1];
	matrixTerm<T> mTerm;
	for (arrayList<matrixTerm<T>>::iterator i = terms.begin(); i != terms.end(); i++)
	{
		int j = rowNext[(*i).col]++;
		mTerm.row = (*i).col;
		mTerm.col = (*i).row;
		mTerm.value = (*i).value;
		b.terms.set(j, mTerm);
	}
}
template<class T>
void sparseMatrix<T>::add(sparseMatrix<T>& b, sparseMatrix<T>& c)
{
	if (rows != b.rows || cols != b.cols)
		//throw matrixSizeMismatch()
		;
	c.rows = rows;
	c.cols = cols;
	c.terms.clear();
	int cSize = 0;
	arrayList<matrixTerm<T>>::iterator it = terms.begin();
	arrayList<matrixTerm<T>>::iterator ib = b.terms.begin();
	arrayList<matrixTerm<T>>::iterator itEnd = terms.end();
	arrayList<matrixTerm<T>>::iterator ibEnd = b.terms.end();
	while (it != itEnd && ib != ibEnd)
	{
		int tIndex = (*it).row * cols + (*it).col;
		int bIndex = (*ib).row * cols + (*ib).col;
		if (tIndex < bIndex)
		{
			c.terms.insert(cSize++, *it);
			it++;
		}
		else 
		{
			if (tIndex == bIndex)
			{
				if ((*it).value + (*ib).value != 0)
				{
					matrixTerm<T> mTerm;
					mTerm.row = (*it).row;
					mTerm.col = (*it).col;
					mTerm.value = (*it).value + (*ib).value;
					c.terms.insert(cSize++, mTerm);
				}
				it++;
				ib++;
			} 
			else
			{
				c.terms.insert(cSize++, *ib);
				ib++;
			}
		}
	}
	for (; it != itEnd; it++)
		c.terms.insert(cSize++, *it);
	for (; ib != ibEnd; ib++)
		c.terms.insert(cSize++, *ib);
}
template<typename T>
class extendedChain
{
public:
private:
	T* firstNode;
};
template<typename T>
struct rowElement
{
	int col;
	T value;
	rowElement<T>* next;
};
template<typename T>
struct headerElement
{
	headerElement<T>* next;
	int row;
	rowElement<T>* rowChain;
};
template<typename T>
class linkedMatrix
{
public:
	void transpose(linkedMatrix<T>& b);
private:
	extendedChain<headerElement<rowElement>>** headerChain;
};
template<class T>
void linkedMatrix<T>::transpose(linkedMatrix<T>& b)
{
	b.headerChain.clear();
	extendedChain<rowElement<T>>* bin;
	bin = new extendedChain<rowElement<T>>[cols + 1];
	extendedChain<headerElement<T>>::iterator ih = headerChain.begin(), ihEnd = headerChain.end();
	while (ih != ihEnd)
	{
		int r = ih->row;
		extendedChain<rowElement<T>>::iterator ir = ih->rowChain.begin(), irEnd = ih->rowChain.end();
		rowElement<T> x;
		x.col = r;
		while (ir != irEnd)
		{
			x.value = ir->value;
			bin[ir->col].push_back(x);
			ir++;
		}
		ih++;
	}
	b.rows = cols;
	b.cols = rows;
	headerElement<T> h;
	for(int i = 1;i<=cols;i++)
		if (!bin[i].empty())
		{
			h.row = i;
			h.rowChain = bin[i];
			b.headerChain.push_back(h);
			bin[i].zero();
		}
	h.rowChain.zero();
	delete[]bin;
}

int main()
{

	return 0;
}