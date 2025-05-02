#include<iostream>
#include<utility>
#include<cstdlib>
#include<cmath>
#include<sstream>
using namespace std;
template<class K, class E>
class dictionary
{
public:
	virtual ~dictionary(){}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual pair<const K, E>* find(const K&)const = 0;
	virtual void erase(const K&) = 0;
	virtual void insert(const pair<const K, E>&) = 0;
};
template<class K, class E>
class pairNode
{
public:
private:
	pair<const K, E> element;
	pairNode<K, E>* next;
};
template<class K, class E>
class sortedChain :dictionary<K, E>
{
public:
	pair<const K, E>* find(const K&)const;
	void insert(const pair<const K, E>&);
	void erase(const K&);
private:
	pairNode<K, E>* firstNode;
	int dSize;
};
template<class K, class E>
pair<const K, E>* sortedChain<K, E>::find(const K& theKey)const
{
	pairNode<K, E>* currentNode = firstNode;
	while (currentNode != NULL && currentNode->element.first != theKey)
		currentNode = currentNode->next;
	if (currentNode != NULL && currentNode->element.first == theKey)
		return &currentNode->element;
	return NULL;
}
template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E>& thePair)
{
	pairNode<K, E>* p = firstNode, * tp = NULL;
	while (p != NULL && p->element.first < thePair.first)
	{
		tp = p;
		p = p->next;
	}
	if (p != NULL && p->element.first == thePair.first)
	{
		p->element.second = thePair.second;
		return;
	}
	pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);
	if (tp == NULL)firstNode = newNode;
	else tp->next = newNode;
	dSize++;
	return
}
template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey)
{
	pairNode<K, E>* p = firstNode, * tp = NULL;
	while (p != NULL && p->element.first < theKey)
	{
		tp = p;
		p = p->next;
	}
	if (p != NULL && p->element.first == theKey)
	{
		if (tp == NULL)firstNode = p->next;
		else tp->next = p->next;
		delete p;
		dSize--;
	}
}
template<class K, class E>
struct skipNode
{
	typedef pair<const K, E> pairType;
	pairType element;
	skipNode<K, E>** next;
	skepNode(const pairType& thePair, int size) :element(thePair)
	{
		next = new skipNode<K, E>* [size];
	}
};
template<class K, class E>
class skipList
{
public:
	skipList(K, int, float);
	pair<const K, E>* find(const K& theKey)const;
	int level()const;
	skipNode<K, E>* search(const K& theKey)const;
	void insert(const pair<const K, E>& thePair);
	void erase(const K& theKey);
private:
	float cutOff;						//确定层数
	int levels;							//当前最大的非空链表
	int dSize;							//字典的数对个数
	int maxLevel;						//允许的最大链表层数
	K tailKey;							//最大关键字
	skipNode<K, E>* headerNode;			//头节点指针
	skipNode<K, E>* tailNode;			//尾节点指针
	skipNode<K, E>** last;				//last[i]表示i层的最后节点
};
template<class K, class E>
skipList<K, E>::skipList(K largeKey, int maxPairs, float prob)
{
	cutOff = prob * RAND_MAX;
	maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
	levels = 0;
	dSize = 0;
	tailKey = largeKey;
	pair<K, E>tailPair;
	tailPair.first = tailKey;
	headerNode = new skipNode<K, E>(tailPair, maxLevel + 1);
	tailNode = new skipNode<K, E>(tailPair, 0);
	last = new skipNode<K, E>* [maxLevel + 1];
	for (int i = 0; i <= maxLevel; i++)
		headerNode->next[i] = tailNode;
}
template<class K, class E>
pair<const K, E>* skipList<K, E>::find(const K& theKey)const
{
	if (theKey >= tailKey)
		return NULL;
	skipNode<K, E>* beforeNode = headerNode;
	for (int i = levels; i >= 0; i--)
		while (beforeNode->next[i]->element.first < theKey)
			beforeNode = beforeNode->next[i];
	if (beforeNode->next[0]->element.first == theKey)
		return &beforeNode->next[0]->element;
	return NULL;
}
template<class K, class E>
int skipList<K, E>::level()const
{
	int lev = 0;
	while (rand() <= cutOff)
		lev++;
	return (lev <= maxLevel) ? lev : maxLevel;
}
template<class K, class E>
skipNode<K, E>* skipList<K, E>::search(const K& theKey)const
{
	skipNode<K, E>* beforeNode = headerNode;
	for (int i = levels; i >= 0; i--)
	{
		while (beforeNode->next[i]->element.first < theKey)
			beforeNode = beforeNode->next[i];
		last[i] = beforeNode;
	}
	return beforeNode->next[0];
}
template<class K, class E>
void skipList<K, E>::insert(const pair<const K, E>& thePair)
{
	if (thePair.first >= tailKey)
	{
		ostringstream s;
		s << "Key = " << thePair.first << " Must be < " << tailKey;
		//throw illegalParameterValue(s.str());
	}
	skipNode<K, E>* theNode = search(thePair.first);
	if (theNode->element.first == thePair.first)
	{
		theNode->element.second = thePair.second;
		return;
	}
	int theLevel = level();
	if (theLevel > levels)
	{
		theLevel = ++levels;
		last[theLevel] = headerNode;
	}
	skipNode<K, E>* newNode = new skipNode<K, E>(thePair, theLevel + 1);
	for (int i = 0; i <= theLevel; i++)
	{
		newNode->next[i] = last[i]->next[i];
		last[i]->next[i] = newNode;
	}
	dSize++;
	return;
}
template<class K, class E>
void skipList<K, E>::erase(const K& theKey)
{
	if (theKey >= tailKey)
		return;
	skipNode<K, E>* theNode = search(theKey);
	if (theNode->element.first != theKey)
		return;
	for (int i = 0; i <= levels && last[i]->next[i] == theNode; i++)
		last[i]->next[i] = theNode->next[i];
	while (levels > 0 && headerNode->next[levels] == tailNode)
		levels--;
	delete theNode;
	dSize--;
}
long threeToLong(string s)
{
	long answer = s.at(0);
	answer = (answer << 8) + s.at(1);
	return (answer << 8) + s.at(2);
}
int stringToInt(string s)
{
	int length = (int)s.length();
	int answer = 0;
	if (length % 2 == 1)
	{
		answer = s.at(length - 1);
		length--;
	}
	for (int i = 0; i < length; i += 2)
	{
		answer += s.at(i);
		answer += ((int)s.at(i + 1)) << 8;
	}
	return (answer < 0) ? -answer : answer;
}
template<>
class hash<string>
{
public:
	size_t operator()(const string theKey)const
	{
		unsigned long hashValue = 0;
		int length = (int)theKey.length();
		for (int i = 0; i < length; i++)
			hashValue = 5 * hashValue + theKey.at(i);
		return size_t(hashValue);
	}
};
template<class K, class E>
class hashTable
{
public:
	template<class K, class E>
	hashTable<K, E>::hashTable(int theDivisor)
	{
		divisor = theDivisor;
		dSize = 0;
		table = new pair<const K, E>* [divisor];
		for (int i = 0; i < divisor; i++)
			table[i] = NULL;
	}
	int search(const K& theKey)const;
	pair<const K, E>* find(const K& theKey)const;
	void insert(const pair<const K, E>& thePair);
private:
	pair<const K, E>** table;
	hash<K> hash;
	int dSize;
	int divisor;
};
template<class K, class E>
int hashTable<K, E>::search(const K& theKey)const
{
	int i = (int)hash(theKey) % divisor;
	int j = i;
	do
	{
		if (table[j] == NULL || table[j]->first == theKey)
			return j;
		j = (j + 1) % divisor;
	} while (j != i);
	return j;
}
template<class K, class E>
pair<const K, E>* hashTable<K, E>::find(const K& theKey)const
{
	int b = search(theKey);
	if (table[b] == NULL || table[b]->first != theKey)
		return NULL;
	return table[b];
}
template<class K, class E>
void hashTable<K, E>::insert(const pair<const K, E>& thePair)
{
	int b = search(thePair.first);
	if (table[b] == NULL)
	{
		table[b] = new pair<const K, E>(thePair);
		dSize++;
	}
	else
	{
		if (table[b]->first == thePair.first)
			table[b]->second = thePair.second;
		else
			//throw hashTableFull()
			;
	}
}
template<class K, class E>
class hashChains
{
public:
	pair<const K, E>* find(const K& theKey)const
	{
		return table[hash(theKey) % divisor].find(theKey);
	}
	void insert(const pair<const K, E>& thePair)
	{
		int homeBucket = (int)hash(thePair.first) % divisor;
		int homeSize = table[homeBucket].size();
		table[homeBucket].insert(thePair);
		if (table[homeBucket].size() > homeSize)
			dSize++;
	}
	void erase(const K& theKey)
	{
		table[hash(theKey) % divisor].erase(theKey);
	}
private:

};
int main()
{

	return 0;
}