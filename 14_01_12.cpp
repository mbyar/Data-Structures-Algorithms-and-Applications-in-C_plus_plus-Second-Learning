#include<iostream>

using namespace std;
template<class K, class E>
class dictionary
{
public:
	virtual ~dictionary() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual pair<const K, E>* find(const K&)const = 0;
	virtual void erase(const K&) = 0;
	virtual void insert(const pair<const K, E>&) = 0;
};
template<class E>
class linkedBinaryTree
{
public:

private:
};
template<class K, class E>
class bsTree : public dictionary<K, E>
{
public:
	virtual void ascend() = 0;
};
template<class K, class E>
class indexedBSTree : public bsTree<K, E>
{
public:
	virtual pair<const K, E>* get(int)const = 0;
	virtual void delete(int) = 0;
};
template<class K, class E>
class binarySearchTree :public bsTree, public linkedBinaryTree
{
public:
	pair<const K, E>* find(const K& theKey)const;
	void insert(const pair<const K, E>& thePair);
	void erase(const K& theKey);
private:

};
template<class K, class E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey)const
{
	binaryTreeNode < pair<const K, E.>* p = root;
	while (p != NULL)
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			if (theKey > p->element.first)
				p = p->rightChild;
			else
				return &p->element;
	return NULL;
}
template<class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E>& thePair)
{
	binaryTreeNode<pair<const K, E>>* p = root, * pp = NULL;
	while (p != NULL)
	{
		pp = p;
		if (thePair.first < p->element.first)
			p = p->leftChild;
		else
			if (thePair.first > p->element.first)
				p = p->rightChild;
			else
			{
				p->element.second = thePair.second;
				return;
			}
	}
	binaryTreeNode<pair<const K, E>>* newNode = new binaryTreeNode<pair<const K, E>>(thePair);
	if (root != NULL)
		if (thePair.first < pp->element.first)
			pp->leftChild = newNode;
		else
			pp->rightChild = newNode;
	else
		root = newNode;
	treeSize++;
}
template<class K, class E>
void binarySearchTree<K, E>::erase(const K& theKey)
{
	binaryTreeNode<pair<const K, E>>* p = root, * pp = NULL;
	while (p != NULL && p->element.first != theKey)
	{
		pp = p;
		if (theKey < p->element.first)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if (p == NULL)
		return;
	if (p->leftChild != NULL && p->rightChild != NULL)
	{
		binaryTreeNode<pair<const K, E>>* s = p->leftChild, * ps = p;
		while (s->rightChild != NULL)
		{
			ps = s;
			s = s->rightChild;
		}
		binaryTreeNode<pair<const K, E>>* q = new binaryTreeNode<pair<const K, E>>(s->element, p->leftChild, p->rightChild);
		if (pp == NULL)
			root = q;
		else if (p == pp->leftChild)
			pp->leftChild = q;
		else
			pp->rightChild = q;
		if (ps == p)pp = q;
		else pp = ps;
		delete p;
		p = s;
	}
	binaryTreeNode > pair<const K, E >> *c;
	if (p->leftChild != NULL)c = p->leftChild;
	else c = p->rightChild;
	if (p == root)
		root = c;
	else
	{
		if (p == pp->leftChild)
			pp->leftChild = c;
		else pp->rightChild = c;
	}
	treeSize--;
	delete p;
}
//while (p != NULL)
//{
//	pp = p;
//	if (thePair.first < p->element.first)
//		p = p->leftChild;
//	else
//		p = p->rightChild;
//}
//void main(void)
//{
//	int n, r;
//	cout << "Enter number of elements and range" << endl;
//	cin >> n >> r;
//	int* h = new int[r + 1];
//	for (int i = 0; i <= r; i++)
//		h[i] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int key;
//		cout << "Enter element " << i << endl;
//		cin >> key;
//		h[key]++;
//	}
//	cout << "Distinct elements and frequencies are" << endl;
//	for (int i = 0; i <= r; i++)
//		if (h[i] != 0)
//			cout << i << "   " << h[i] << endl;
//}
template<class K, class E>
class binarySearchTreeWithVisit :public binarySearchTree<K, E>
{
public:
	void insert(const pair<const K, E>& thePair, void(*visit)(E&));
private:
};
//int main(void)
//{
//	int n;
//	cout << "Enter number of elements" << endl;
//	cin >> n;
//	binarySearchTreeWithVisit<int, int>theTree;
//	for (int i = 1; i <= n; i++)
//	{
//		pair<int, int>thePair;
//		cout << "Enter element " << i << endl;
//		cin >> thePair.first;
//		thePair.second = 1;
//		//theTree.insert(thePair, add1);
//	}
//	cout << "Distinct elements and frequencies are" << endl;
//	//theTree.ascend();
//}
template<class K, class E>
class dBinarySearchTreeWithGE
{
public:
	pair<const K, E>* findGE(const K& theKey)const;
	void erase(K theKey);
	void insert(pair<K, E> x);
private:
};
template<class K, class E>
pair<const K, E>* dBinarySearchTreeWithGE<K, E>::findGE(const K& theKey)const
{
	binaryTreeNode<pair<const K, E>>* currentNode = root;
	pair<const K, E>* bestElement = NULL;
	while (currentNode != NULL)
		if (currentNode->element.first >= theKey)
		{
			bestElement = &currentNode->element;
			currentNode = currentNode->leftChild;
		}
		else
			currentNode = currentNode->rightChild;
	return bestElement;
}
void bestFitPack(int* objectSize, int numberOfObjects, int binCapacity)
{
	int n = numberOfObjects;
	int binsUsed = 0;
	dBinarySearchTreeWithGE<int, int>theTree;
	pair<int, int>theBin;
	for (int i = 1; i <= n; i++)
	{
		pair<const int, int>* bestBin = theTree.findGE(objectSize[i]);
		if (bestBin == NULL)
		{
			theBin.first = binCapacity;
			theBin.second = ++binsUsed;
		}
		else
		{
			theBin = *bestBin;
			theTree.erase(bestBin->first);
		}
		cout << "Pack object " << i << " in bin " << theBin.second << endl;
		theBin.first -= objectSize[i];
		if (theBin.first > 0)
			theTree.insert(theBin);
	}
}
template<class T>
void main(void)
{
	int theC[] = { 0, 8, 7, 4, 2, 5, 1, 9, 8, 10, 6 };
	int k[] = { 0, 7, 6, 3, 1, 2, 0, 2, 0, 1, 0 };
	int n = 10;
	int theK = 22;
	arrayList<int> theList(n);
	int* theA = new int[n + 1],
		* theB = new int[n + 1],
		* theX = new int[n + 1];
	int crossingsNeeded = theK / 2;
	int currentWire = n;
	while (crossingsNeeded > 0)
	{
		if (k[currentWire] < crossingsNeeded)
		{
			theList.insert(k[currentWire], currentWire);
			crossingsNeeded -= k[currentWire];
		}
		else
		{
			theList.insert(crossingsNeeded, currentWire);
			crossingsNeeded = 0;
		}
		currentWire--;
	}
	for (int i = 1; i <= currentWire; i++)
		theX[i] = i;
	for (int i = currentWire + 1; i <= n; i++)
		theX[i] = theList.get(i - currentWire - 1);
	for (int i = 1; i <= n; i++)
		theA[theX[i]] = i;
	for (int i = 1; i <= n; i++)
		theB[i] = theC[theX[i]];
	cout << "A is ";
	for (int i = 1; i <= n; i++)
		cout << theA[i] << " ";
	cout << endl;
	cout << "B is ";
	for (int i = 1; i <= n; i++)
		cout << theB[i] << " ";
	cout << endl;
}