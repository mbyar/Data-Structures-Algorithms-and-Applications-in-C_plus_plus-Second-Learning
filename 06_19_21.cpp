#include<iostream>
#include<algorithm>
using namespace std;
int* equivClass, n;
void initialize(int numberOfElements)
{
	n = numberOfElements;
	equivClass = new int[n + 1];
	for (int e = 1; e <= n; e++)
		equivClass[e] = e;
}
void unite(int classA, int classB)
{
	for (int k = 1; k <= n; k++)
		if (equivClass[k] == classB)
			equivClass[k] = classA;
}
int find(int theElement)
{
	return equivClass[theElement];
}
struct equivNode
{
	int equivClass, size, next;
};
equivNode* node;
int n;
void initialize(int numberOfElements)
{
	n = numberOfElements;
	node = new equivNode[n + 1];
	for (int e = 1; e <= n; e++)
	{
		node[e].equivClass = e;
		node[e].next = 0;
		node[e].size = 1;
	}
}
void unite(int classA, int classB)
{
	if (node[classA].size > node[classB].size)
		swap(classA, classB);
	int k;
	for (k = classA; node[k].next != 0; k = node[k].next)
		node[k].equivClass = classB;
	node[k].equivClass = classB;
	node[classB].size += node[classA].size;
	node[k].next = node[classB].next;
	node[classB].next = classA;
}
int find(int theElement)
{
	return node[theElement].equivClass;
}
int main()
{
	
	return 0;
}