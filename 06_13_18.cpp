#include<iostream>
#include<string>
using namespace std;
template<class T>
struct chainNode
{
	T element;
	chainNode<T>* next;
	chainNode() {}
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};
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
class chain :public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out)const;
	void binSort(int range);
protected:
	void checkIndex(int theIndex)const;
	chainNode<T>* firstNode;
	int listSize;
};
template<class T>
void chain<T>::binSort(int range)
{
	chainNode<T>** bottom, ** top;
	bottom = new chainNode<T>*[range + 1];
	top = new chainNode<T>*[range + 1];
	for (int b = 0; b <= range; b++)
		bottom[b] = NULL;
	for (; firstNode != NULL; firstNode = firstNode->next)
	{
		int theBin = firstNode->element;
		if (bottom[theBin] == NULL)
			bottom[theBin] = top[theBin] = firstNode;
		else
		{
			top[theBin]->next = firstNode;
			top[theBin] = firstNode;
		}
	}
	chainNode<T>* y = NULL;
	for(int theBin = 0;theBin <= range;theBin++)
		if (bottom[theBin] != NULL)
		{
			if (y == NULL)
				firstNode = bottom[theBin];
			else
				y->next = bottom[theBin];
			y = top[theBin];
		}
	if (y != NULL)
		y->next = NULL;
	delete[]bottom;
	delete[]top;
}
template<typename T>
class circularListWithHeader
{
public:
	circularListWithHeader();
	int indexOf(const T& theElement)const;
protected:
	chainNode<T>* headerNode;
	int listSize;
};
template<class T>
circularListWithHeader<T>::circularListWithHeader()
{
	headerNode = new chainNode<T>();
	headerNode->next = headerNode;
	listSize = 0;
}
template<class T>
int circularListWithHeader<T>::indexOf(const T& theElement)const
{
	headerNode->element = theElement;
	chainNode<T>* currentNode = headerNode->next;
	int index = 0;
	while (currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == headerNode)
		return -1;
	else
		return index;
}
struct studentRecord
{
	int score;
	string* name;
	int operator != (const studentRecord&x)const
	{
		return (score != x.score);
	}
};
ostream& operator<<(ostream& out, const studentRecord& x)
{
	out << x.score << ' ' << *x.name << endl; return out;
}
struct studentRecord
{
	int score;
	string* name;
	operator int() const { return score; }
};
ostream& operator<<(ostream& out, const studentRecord& x)
{
	out << x.score << ' ' << *x.name << endl; return out;
}
struct studentRecord
{
	int score;
	string* name;
	int operator !=(const studentRecord& x)const
	{
		return (score != x.score);
	}
	operator int()const { return score; }
};
ostream& operator<<(ostream& out, const studentRecord& x)
{
	out << x.score << ' ' << *x.name << endl; return out;
}
void binSort(chain<studentRecord>& theChain, int range)
{
	chain<studentRecord>* bin;
	bin = new chain<studentRecord>[range + 1];
	int numberOfElements = theChain.size();
	for (int i = 1; i <= numberOfElements; i++)
	{
		studentRecord x = theChain.get(0);
		theChain.erase(0);
		bin[x.score].insert(0, x);
	}
	for (int j = range;j>=0;j--)
		while (!bin[j].empty())
		{
			studentRecord x = bin[j].get(0);
			bin[j].erase(0);
			theChain.insert(0, x);
		}
	delete[]bin;
}
int main()
{

	return 0;
}