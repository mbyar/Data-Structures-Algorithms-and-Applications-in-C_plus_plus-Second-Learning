#include<iostream>

using namespace std;
template<class T>
class queue
{
public:
	virtual ~queue(){}
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};
template<class T>
class arrayQueue :queue<T>
{
public:
	void push(const T& theElement)
private:
	
};
template<class T>
void nonName()
{
	T* newQueue = new T[2 * arrayLength];
	int start = (theFront + 1) % arrayLength;
	if (start < 2)
		copy(queue + start, queue + start + arrayLength - 1, newQueue);
	else
	{
		copy(queue + start, queue + arrayLength, newQueue);
		copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
	}
	theFront = 2 * arrayLength - 1;
	theBack = arrayLength - 2;
	arrayLength *= 2;
	delete[]queue;
	queue = newQueue;
}
template<class T>
void pop() 
{
	if (theFront == theBack)
		throw queueEmpty();
	theFront = (theFront + 1) % arrayLength;
	queue[theFront].~T();
}
template<class T>
void arrayQueue<T>::push(const T& theElement)
{
	if ((theBack + 1) % arrayLength == theFront)
	{
		;
	}
	queueBack = (queueBack + 1) % arrayLength;
	queue[queueBack] = theElement;
}
template<class T>
class linkedQueue :queue<T>
{
public:
	void push(const T& theElement);
	void pop();
private:

};
template<class T>
void linkedQueue<T>::push(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement, NULL);
	if (queueSize == 0)
		queueFront = newNode;
	else
		queueBack->next = newNode;
	queueBack = newNode;
	queueSize++;
}
template<class T>
void linkedQueue<T>::pop()
{
	if (queueFront == NULL)
		throw queueEmpty();
	chainNode<T>* nextNode = queueFront->next;
	delete queueFront;
	queueFront = nextNode;
	queueSize--;
}
int main()
{

	return 0;
}