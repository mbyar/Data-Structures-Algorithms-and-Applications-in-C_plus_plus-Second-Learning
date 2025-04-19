#include<iostream>

using namespace std;
template<class T>
class arrayList
{
public:

private:
};
template<class T>
class stack
{
public:
	virtual ~stack(){}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};
template<class T>
class derivedArrayStack :private arrayList<T>, public stack<T>
{
public:
	derivedArrayStack(int initialCapacity = 10):arrayList<T>(initialCapacity){}
	bool empty()const { return arrayList<T>::empty(); }
	int size() const { return arrayList<T>::size(); }
	T& top()
	{
		if (arrayList<T>::empty())
			throw stackEmpty();
		return get(arrayList<T>::size() - 1);
	}
	T& top()
	{
		try { return get(arrayList<T>::size() - 1); }
		catch(illegalIndex)
		{
			throw stackEmpty();
		}
	}
	void pop()
	{
		if (arrayList<T>::empty())
			throw stackEmpty();
		erase(arrayList<T>::size() - 1);
	}
	void push(const T& theElement)
	{
		insert(arrayList<T>::size(), theElement);
	}
};
template<class T>
class arrayStack :public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() { delete[]stack; }
	bool empty()const { return stackTop == -1; }
	int size()const { return stackTop + 1; }
	T& top()
	{
		if (stackTop == -1)
			//throw stackEmpty()
			;
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			//throw stackEmpty()
			;
		stack[stackTop--].~T()£»
	}
	void push(const T& theElement);
private:
	int stackTop;
	int arrayLength;
	T* stack;
};
template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}
template<class T>
void arrayStack<T>::push(const T& theElement)
{
	if (stackTop == arrayLength - 1)
	{
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	stack[++stackTop] = theElement;
}
template<class T>
class linkedStack :public stack<T>
{
public:
	linkedStack(int initialCapacity = 10) { stackTop = NULL; stackSize = 0; }
	~linkedStack();
	bool empty()const { return stackSize == 0; }
	int size()const { return stackSize; }
	T& top()
	{
		if (stackSize == 0)
			throw stackEmpty();
		return stackTop->element;
	}
	void pop();
	void push(const T& theElement)
	{
		stackTop = new chainNode<T>(theElement, stackTop);
		stackSize++;
	}
private:
	chainNode<T>* stackTop;
	int stackSize;
};
template<class T>
linkedStack<T>::~linkedStack()
{
	while (stackTop != NULL)
	{
		chainNode<T>* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}
template<class T>
void linkedStack<T>::pop()
{
	if (stackSize == 0)
		throw stackEmpty();
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}
int main()
{

	return 0;
}