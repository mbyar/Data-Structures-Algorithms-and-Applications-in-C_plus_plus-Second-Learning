#include<iostream>

using namespace std;
template<class T>
struct binaryTreeNode
{
	T element;
	binaryTreeNode<T>* leftChild, * rightChild;
	binaryTreeNode() { leftChild = rightChild = NULL; }
	binaryTreeNode(const T& theElement)
	{
		element(theElement);
		leftChild = rightChild = NULL;
	}
	binaryTreeNode(const T& theElement, binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild)
	{
		element(theElement);
		leftChild = theLeftChild;
		rightChild = theRightChild;
	}
};
template<class T>
class binaryTree
{
public:
	virtual ~binaryTree(){}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual void preOrder(void(*)(T*)) = 0;
	virtual void inOrder(void(*)(T*)) = 0;
	virtual void postOrder(void(*)(T*)) = 0;
	virtual void levelOrder(void(*)(T*)) = 0;
};
template<class E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
	linkedBinaryTree() { root = NULL; treeSize = 0; }
	~linkedBinaryTree() { erase(); }
	bool empty()const { return treeSize == 0; }
	int size()const { return treeSize; }
	void preOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; preOrder(root);
	}
	void inOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; inOrder(root);
	}
	void postOrder(void(*theVisit)(binaryTreeNode<E>*))
	{
		visit = theVisit; postOrder(root);
	}
	void levelOrder(void(*)(binaryTreeNode<E>*));
	void erase()
	{
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}
	int height()const { return height(root); }
private:
	binaryTreeNode<E>* root;
	int treeSize;
	static void (*visit)(binaryTreeNode<E>*);
	static void preOrder(binaryTreeNode<E>* t);
	static void inOrder(binaryTreeNode<E>* t);
	static void postOrder(binaryTreeNode<E>* t);
	static void dispose(binaryTreeNode<E>* t) { delete t; }
	static int height(binaryTreeNode<E>* t);
};
struct booster
{
	int degradeToLeaf, degradeFromParent;
	bool boosterHere;
	void output(ostream& out)const
	{
		out << boosterHere << ' ' << degradeToLeaf << ' ' << degradeFromParent << ' ';
	}
};
ostream& operator<<(ostream& out, booster x)
{
	x.output(out); return out;
}
int tolerance;
void placeBoosters(binaryTreeNode<booster>* x)
{
	x->element.degradeToLeaf = 0;
	binaryTreeNode<booster>* y = x->leftChild;
	if (y != NULL)
	{
		int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
		if (degradation > tolerance)
		{
			y->element.boosterHere = true;
			x->element.degradeToLeaf = y->element.degradeFromParent;
		}
		else
			x->element.degradeToLeaf = degradation;
	}
	y = x->rightChild;
	if (y != NULL)
	{
		int degradation = y->element.degradeToLeaf + y->element.degradeFromParent;
		if (degradation > tolerance)
		{
			y->element.boosterHere = true;
			degradation = y->element.degradeFromParent;
		}
		if (x->element.degradeToLeaf < degradation)
			x->element.degradeToLeaf = degradation;
	}
}
int* parent;
void initialize(int numberOfElements)
{
	parent = new int[numberOfElements + 1];
	for (int e = 1; e <= numberOfElements; e++)
		parent[e] = 0;
}
int find(int theElement)
{
	while (parent[theElement] != 0)
		theElement = parent[theElement];
	return theElement;
}
void unite(int rootA, int rootB)
{
	parent[rootB] = rootA;
}
struct unionFindNode
{
	int parent;
	bool root;
	unionFindNode()
	{
		parent = 1; root = true;
	}
};
unionFindNode* node;
void initialize(int numberOfElements)
{
	node = new unionFindNode[numberOfElements];
}
int find(int theElement)
{
	while (!node[theElement].root)
		theElement = node[theElement].parent;
	return theElement;
}
void unite(int rootA, int rootB)
{
	if (node[rootA].parent < node[rootB].parent)
	{
		node[rootB].parent += node[rootA].parent;
		node[rootA].root = false;
		node[rootA].parent = rootB;
	}
	else
	{
		node[rootA].parent += node[rootB].parent;
		node[rootB].root = false;
		node[rootB].parent = rootA;
	}
}
int find(int theElement)
{
	int theRoot = theElement;
	while (!node[theRoot].root)
		theRoot = node[theRoot].parent;
	int currentNode = theElement;
	while (currentNode != theRoot)
	{
		int parentNode = node[currentNode].parent;
		node[currentNode].parent = theRoot;
		currentNode = parentNode;
	}
	return theRoot;
}
int main()
{

	return 0;
}