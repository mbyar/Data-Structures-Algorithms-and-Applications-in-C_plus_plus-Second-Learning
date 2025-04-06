#include<iostream>
#include<vector>
using namespace std;
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
class vectorList : public linearList<T>
{
public:
	vectorList(int initialCapacity = 10);
	vectorList(const vectorList<T>&);
	~vectorList() { delete element; }
	bool empty()const { return element->empty(); }
	int size()const { return (int)element->size(); }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	int capacity()const { return (int)element->capacity(); }
	typedef typename vector<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }
protected:
	void checkIndex(int theIndex)const;
	vector<T>* element;
};
template<class T>
vectorList<T>::vectorList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		//throw illegalParameterValue(s.str());
	}
	element = new vector<T>;
	element->reserve(initialCapacity);
}
template<class T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
	element = new vector<T>(*theList.element);
}
template<class T>
void vectorList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	element->erase(begin() + theIndex);
}
template<class T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex >size())
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << size();
		throw illegalIndex(s.str());
	}
	element->insert(element->begin() + theIndex, theElement);
}
int main()
{

	return 0;
}