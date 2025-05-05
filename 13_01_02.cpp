#include<iostream>

using namespace std;
template<class T>
class winnerTree
{
public:
	virtual ~winnerTree(){}
	virtual void initialize(T* thePlayer, int theNumberOfPlayers) = 0;
	virtual int winner()const = 0;
	virtual void rePlay(int thePlayer) = 0;
};
class binType
{
public:
	int unusedCapacity;
};
class completeWinnerTree
{
public:
	int winner(int);
	void rePlay(int);
};
completeWinnerTree winTree;
void firstFitPack(int* objectSize, int numberOfObjects, int binCapacity)
{
	int n = numberOfObjects;
	binType* bin = new binType[n + 1];
	for (int i = 1; i <= n; i++)
	{
		int child = 2;
		while (child < n)
		{
			int winner = winTree.winner(child);
			if (bin[winner].unusedCapacity < objectSize[i])
				child++;
			child *= 2;
		}
		int binToUse;
		child /= 2;
		if (child < n)
		{
			binToUse = winTree.winner(child);
			if (binToUse > 1 && bin[binToUse - 1].unusedCapacity >= objectSize[i])
				binToUse--;
		}
		else
			binToUse = winTree.winner(child / 2);
		cout << "Pack object " << i << " in bin " << binToUse << endl;
		bin[binToUse].unusedCapacity -= objectSize[i];
		winTree.rePlay(binToUse);
	}
}
int main()
{

	return 0;
}