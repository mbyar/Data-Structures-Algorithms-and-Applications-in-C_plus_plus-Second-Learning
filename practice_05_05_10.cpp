#include<iostream>
#include<algorithm>
#include<sstream>
#include<iterator>
using namespace std;
template<class T>
void changeLengthID(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw /*illegalParameterValue*/("new length must be >= 0");
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[]a;
	a = temp;
}
template<class T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& get(int theIndex)const = 0;
	virtual int indexOf(const T& theElement)const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual void output(ostream& out)const = 0;
};
template<class T>
class iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	iterator(T* thePosition = 0) { position = thePosition; }
	T& operator*() const { return *position; }
	T* operator->() const { return &*position; }
	iterator& operator++()
	{
		++position; return *this;
	}
	iterator operator++(int)
	{
		iterator old = *this;
		++position;
		return old;
	}
	iterator& operator--()
	{
		--position; return*this;
	}
	iterator operator--(int)
	{
		iterator old = *this;
		--position;
		return old;
	}
	bool operator!=(const iterator right)const
	{
		return position != right.position;
	}
	bool operator==(const iterator right)const
	{
		return position == right.position;
	}
protected:
	T* position;
};
template<class T>
class arrayList : public linearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[]element; }
	bool empty() const { return listSize == 0 };
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	int capacity()const { return arrayLength; }
	iterator begin() { return iterator(element); }
	iterator end() { return iterator(element + listSize); }
	void setSize(int size);
	void trimToSize();
	T& operator[](int i)const { return element[i]; }
	bool operator==(const arrayList& y)const;
	bool operator!=(const arrayList& y)const { return !(*this == y); }
	bool operator<(const arrayList& y)const;
	
protected:
	void checkIndex(int theIndex)const;
	T* element;
	int arrayLength;
	int listSize;
};
template<typename T>
bool arrayList<T>::operator<(const arrayList<T>& y)const
{
	bool status;
	if (listSize < y.listSize) status = true;
	else status = false;
	for (int i = 0; i < min(listSize, y.listSize); i++)
		if (element[i] > y.element[i])
			return false;
	return status;
}
template<typename T>
bool arrayList<T>::operator==(const arrayList<T>& y)const
{
	if (listSize != y.listSize)
		return false;
	for (int i = 0; i < listSize; i++)
		if (element[i] != y.element[i])
			return false;
	return true;
}
template<typename T>
void arrayList<T>::trimToSize()
{
	setSize(max(1, listSize));
}
template<typename T>
void arrayList<T>::setSize(int size)
{
	if (size < 1)
	{
		cout << "There is a problem" << endl;
		return;
	}
	T* newElement = new T[size];
	arrayLength = size;
	listSize = min(listSize, size);
	copy(element, element + listSize, x.element);
	delete[]element;
	element = newElement;
}
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		//throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSizee, element);
}
template<class T>
void arrayList<T>::checkIndex(int theIndex)const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		//throw illegalIndex(s.str());
	}
}
template<class T>
T& arrayList<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	return element[theIndex];
}
template<class T>
int arrayList<T>::indexOf(const T& theElement)const
{
	int theIndex = (int)(find(element, element + listSize, theElement) - element);
	if (theIndex == listSize)
		return -1;
	else return theIndex;
}
template<class T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		//throw illegalIndex(s.str());
	}
	if (listSize == arrayLength)
	{
		changeLengthID(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	copy_backward(element + theIndex, element + listSize, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}
template<class T>
void arrayList<T>::output(ostream& out)const
{
	copy(element, element + listSize, ostream_iterator<T>(out, " "));
}
template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.output(out); return out;
}
int main()
{
 
	return 0;
}