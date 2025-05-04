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
void visit(binaryTreeNode<T>* x)
{
	cout << x->element << ' ';
}
template<class T>
void preOrder(binaryTreeNode<T>* t)
{
	if (t != NULL)
	{
		visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}
template<class T>
void inOrder(binaryTreeNode<T>* t)
{
	if (t != NULL)
	{
		inOrder(t->leftChild);
		visit(t);
		inOrder(t->rightChild);
	}
}
template<class T>
void postOrder(binaryTreeNode<T>* t)
{
	if (t != NULL)
	{
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		visit(t);
	}
}
template<class T>
void infix(binaryTreeNode<T>* t)
{
	if (t != NULL)
	{
		cout << '(';
		infix(t->leftChild);
		cout << t->element;
		infix(t->rightChild);
		cout << ')';
	}
}
template<class T>
void levelOrdr(binaryTreeNode<T>* t)
{
	arrayQueue<binaryTreeNode<T>*> q;
	while (t != NULL)
	{
		visit(t);
		if (t->leftChild != NULL)
			q.push(t->leftChild);
		if (t->rightChild != NULL)
			q.push(t->rightChild);
		try { t = q.front(); }
		catch (queueEmpty) { return; }
		q.pop();
	}
}
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
template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E>* t)
{
	if (t != NULL)
	{
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}
template<class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E>* t)
{
	if (t == NULL)
		return 0;
	int hl = height(t->leftChild);
	int hr = height(t->rightChild);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

int main()
{

	return 0;
}