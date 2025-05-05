#include<iostream>

using namespace std;
template<class T>
class maxPriorityQueue
{
public:
	virtual ~maxPriorityQueue(){}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual const T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};
template<class T>
class maxHeap :public maxPriorityQueue<T>
{
public:
	void push(const T& theElement);
	void pop();
	void initialize(T* theHeap, int theSize);
private:
	T* heap;
	int arrayLength;
	int heapSize;
};
template<class T>
void maxHeap<T>::push(const T& theElement)
{
	if (heapSize == arrayLength - 1)
	{
		changeLength1D(heap, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < theElement)
	{
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = theElement;
}
template<class T>
void maxHeap<T>::pop()
{
	if (heapSize == 0)
		throw queueEmpty();
	heap[1].~T();
	T lastElement = heap[heapSize--];
	int currentNode = 1, child = 2;
	while (child <= heapSize)
	{
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;
		if (lastElement >= heap[child])
			break;
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}
	heap[currentNode] = lastElement;
}
template<class T>
void maxHeap<T>::initialize(T* theHeap, int theSize)
{
	delete[]heap;
	heap = theHeap;
	heapSize = theSize;
	for (int root = heapSize / 2; root >= 1; root--)
	{
		T rootElement = heap[root];
		int child = 2 * root;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;
			if (rootElement >= heap[child])
				break;
			heap[child / 2] = heap[child];
			child *= 2;
		}
		heap[child / 2] = rootElement;
	}
}
template<class T>
class arrayQueue
{
public:

private:

};
template<class T>
class binaryTreeNode
{
public:

private:

};
template<class T>
class maxHblt
{
public:
	void meld(binaryTreeNode<pair<int, T>>*& x, binaryTreeNode<pair<int, T>>*& y);
	void meld(maxHblt<T>& theHblt);
	void push(const T& theElement);
	void pop();
	void initialize(T* theElement, int theSize);
private:

};
template<class T>
void maxHblt<T>::meld(binaryTreeNode<pair<int, T>>*& x, binaryTreeNode<pair<int, T>>*& y)
{
	if (y == NULL)
		return;
	if(x==NULL)
	{
		x = y; return;
	}
	if (x->element.second < y->element.second)
		swap(x, y);
	meld(x->rightChild, y);
	if (x->leftChild == NULL)
	{
		x->leftChild = x->rightChild;
		x->rightChild = NULL;
		x->element.first = 1;
	}
	else
	{
		if (x->leftChild->element.first < x->rightChild->element.first)
			swap(x->leftChild, x->rightChild);
		x->element.first = x->rightChild->element.first + 1;
	}
}
template<class T>
void maxHblt<T>::meld(maxHblt<T>& theHblt)
{
	meld(root, theHblt.root);
	treeSize += theHblt.treeSize;
	theHblt.root = NULL;
	theHblt.treeSize = 0;
}
template<class T>
void maxHblt<T>::push(const T& theElement)
{
	binaryTreeNode<pair<int, T>>* q = new binaryTreeNode < pair<int, T>(1, theElement));
	meld(root, q);
	treeSize++;
}
template<class T>
void maxHblt<T>::pop()
{
	if (root == NULL)
		throw queueEmpty();
	binaryTreeNode<pair<int, T>>* left = root->leftChild, * right = root->rightChild;
	delete root;
	root = left;
	meld(root, right);
	treeSize--;
}
template<class T>
void maxHblt<T>::initialize(T* theElements, int theSize)
{
	arrayQueue<binaryTreeNode<pair<int, T>>*> q(theSize);
	erase();
	for (int i = 1; i <= theSize; i++)
		q.push(new binaryTreeNode<pair<int, T>>(pair<int, T>(1, theElements[i])));
	for (i = 1; i <= theSize - 1; i++)
	{
		binaryTreeNode<pair<int, T>>* b = q.front();
		q.pop();
		binaryTreeNode<pair<int, T>>* c = q.front();
		q.pop();
		meld(b, c);
		q.push(b);
	}
	if (theSize > 0)
		root = q.front();
	treeSize = theSize;
}
template<class T>
void heapSort(T a[], int n)
{
	maxHeap<T> heap(1);
	heap.initialize(a, n);
	for (int i = n - 1; i >= 1; i--)
	{
		T x = heap.top();
		heap.pop();
		a[i + 1] = x;
	}
	heap.deactivateArray();
}
//void makeSchedule(jobNode a[], int n, int m)
//{
//	if (n <= m)
//	{
//		cout << "Schedule each job on a different machine." << endl;
//		return;
//	}
//	heapSort(a, n);
//	minHeap<machineNode> machineHeap(m);
//	for (int i = 1; i <= m; i++)
//		machineHeap.push(machineNode(i, 0));
//	for (int i = n; i >= 1; i--)
//	{
//		machineNode x = machineHeap.top();
//		machineHeap.pop();
//		cout << "Schedule job " << a[i].id << " on machine " << x.id << " form " << x.avail << " to " << (x.avail + a[i].time) << endl;
//		x.avail += a[i].time;
//		machineHeap.push(x);
//	}
//}
template<class T>
linkedBinaryTree<int>* huffmanTree(T weight[], int n)
{
	huffmanNode<T>* hNode = new huffmanNode<T>[n + 1];
	linkedBinaryTree<int> emptyTree;
	for (int i = 1; i <= n; i++)
	{
		hNode[i].weight = weight[i];
		hNode[i].tree = new linkedBinaryTree<int>;
		hNode[i].tree->makeTree(i, emptyTree, emptyTree);
	}
	minHeap<huffmanTree<T>> heap(1);
	heap.initialize(hNode, n);
	huffmanTree<T> w, x, y;
	linkedBinaryTree<int>* z;
	for (i = 1; i < n; i++)
	{
		x = heap.top(); heap.pop();
		y = heap.top(); heap.pop();
		z = new linkedBinaryTree<int>;
		z->makeTree(0, *x.tree, *y.tree);
		w.weight = x.weight + y.weight;
		w.tree = z;
		heap.push(w);
		delete x.tree;
		delete y.tree;
	}
	return heap.top().tree;
}
int main()
{

	return 0;
}