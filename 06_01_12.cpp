#include<iostream>
#include<sstream>
#include<string>
using namespace std;
template<class T>
struct chainNode
{
	T element;
	chainNode<T>* next;
	chainNode(){}
	chainNode(const T&element)
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
protected:
	void checkIndex(int theIndex)const;
	chainNode<T>* firstNode;
	int listSize;
};
template<class T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		//throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}
template<class T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}
template<class T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
template<class T>
T& chain<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
		currentNode = currentNode->next;
	return currentNode->element;
}
template<class T>
int chain<T>::indexOf(const T& theElement)const
{
	chainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != NULL && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}
	if (currentNode == NULL)
		return -1;
	else
		return index;
}
template<class T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			p = p->next;
		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex>listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		//throw illegalIndex(s.str());
	}
	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)p = p->next;
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}
template<class T>
void chain<T>::output(ostream& out)const
{
	for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
		out << currentNode->element << " ";
}
template<class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out); return out;
}
template<typename T>
class iterator
{
public:
	iterator(chainNode<T>* theNode = NULL)
	{
		node = theNode;
	}
	T& operator *()const { return node->element; }
	T* operator->()const { return &node->element; }
	iterator& operator++()
	{
		node = node->next;
		return *this;
	}
	iterator operator++(int)
	{
		iterator old = *this;
		node = node->next;
		return old;
	}
	bool operator!=(const iterator right)const
	{
		return node != right.node;
	}
	bool operator==(const iterator right)const
	{
		return node == right.node;
	}
protected:
	chainNode<T>* node;
};
template<class T>
class extendedLinearList :linearList<T>
{
public:
	virtual ~extendedLinearList(){}
	virtual void clear() = 0;
	virtual void push_back(const T& theElememt) = 0;
};
template<class T>
class extendedChain :public extendedChain<T>, public chain<T>
{
public:
	~extendedChain() { ; }
	void clear();
	void push_back(const T& theElement);
protected:
	chainNode<T>* lastNode;
};
template<class T>
void extendedChain<T>::clear()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
	listSize = 0;
}
template<class T>
void extendedChain<T>::push_back(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement, NULL);
	if (firstNode == NULL)
		firstNode = lastNode = newNode;
	else
	{
		lastNode->next = newNode;
		lastNode = newNode;
	}
	listSize++;
}
int main()
{

	return 0;
}