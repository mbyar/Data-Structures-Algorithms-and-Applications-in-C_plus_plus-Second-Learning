#include<iostream>

using namespace std;
template<typename T>
class arrayStack
{
public:
	arrayStack();
	arrayStack(int n);
	void push(int i);
	T top();
	void pop();
	bool empty();
private:
};
class stackEmpty
{
public:
};
void printMatchedPairs(string expr)
{
	arrayStack<int> s;
	int length = (int)expr.size();
	for (int i = 0; i < length; i++)
		if (expr.at(i) == '(')
			s.push(i);
		else
			if(expr.at(i)==')')
				try
			{
				cout << s.top() << ' ' << i << endl;
				s.pop();
			}
	catch (stackEmpty)
	{
		cout << "No match for right parenthesis" << " at " << i << endl;
	}
	while (!s.empty())
	{
		cout << "No match for left parenthesis at " << s.top() << endl;
		s.pop();
	}
}
void towersOfHanoi(int n, int x, int y, int z)
{
	if (n > 0)
	{
		towersOfHanoi(n - 1, x, z, y);
		cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
		towersOfHanoi(n - 1, z, y, x);
	}
}
arrayStack<int> tower[4];
void moveAndShow(int, int, int, int);
void towersOfHanoi(int n)
{
	for (int d = n; d > 0; d--)
		tower[1].push(d);
	moveAndShow(n, 1, 2, 3);
}
void moveAndShow(int n, int x, int y, int z)
{
	if (n > 0)
	{
		moveAndShow(n - 1, x, z, y);
		int d = tower[x].top();
		tower[x].pop();
		tower[y].push(d);
		//showState();
		moveAndShow(n - 1, z, y, x);
	}
}
arrayStack<int>* track;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;
bool putInHoldingTrack(int c)
{
	int bestTrack = 0, bestTop = numberOfCars + 1;
	for (int i = 1; i <= numberOfTracks; i++)
		if (!track[i].empty())
		{
			int topCar = track[i].top();
			if (c < topCar && topCar < bestTop)
			{
				bestTop = topCar;
				bestTrack = i;
			}
		}
		else
			if (bestTrack == 0)bestTrack = i;
	if (bestTrack == 0)return false;
	track[bestTrack].push(c);
	cout << "Move car " << c << " from input track " << "to holding track " << bestTrack << endl;
	if (c < smallestCar)
	{
		smallestCar = c;
		itsTrack = bestTrack;
	}
	return true;
}
void outputFromHoldingTrack()
{
	track[itsTrack].pop();
	cout << "Move car " << smallestCar << " from holding " << "track " << itsTrack << " to output track" << endl;
	smallestCar = numberOfCars + 2;
	for(int i = 1;i<=numberOfTracks;i++)
		if (!track[i].empty() && (track[i].top() < smallestCar))
		{
			smallestCar = track[i].top();
			itsTrack = i;
		}
}
bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
{
	numberOfCars = theNumberOfCars;
	numberOfTracks = theNumberOfTracks;
	track = new arrayStack<int>[numberOfTracks + 1];
	int nextCarToOutput = 1;
	smallestCar = numberOfCars + 1;
	for (int i = 1; i <= numberOfCars; i++)
		if (inputOrder[i] == nextCarToOutput)
		{
			cout << "Move car " << inputOrder[i] << " from input track to output track" << endl;
			nextCarToOutput++;
			while (smallestCar == nextCarToOutput)
			{
				outputFromHoldingTrack();
				nextCarToOutput++;
			}
		}
		else
			if (!putInHoldingTrack(inputOrder[i]))
				return false;
	return true;
}
bool checkBox(int net[], int n)
{
	arrayStack<int>* s = new arrayStack<int>(n);
	for (int i = 0; i < n; i++)
		if (!s->empty())
			if (net[i] == net[s->top()])
				s->pop();
			else s->push(i);
		else s->push(i);
	if (s->empty())
	{
		cout << "Switch box is routable" << endl;
		return true;
	}
	cout << "Switch box is not routable" << endl;
	return false;
}
int test01()
{
	int n, r;
	cout << "Enter number of elements" << endl;
	cin >> n;
	if (n < 2)
	{
		cout << "Too few elements" << endl;
		return 1;
	}
	cout << "Enter number of relations" << endl;
	cin >> r;
	if (r < 1)
	{
		cout << "Too few relations" << endl;
		return 1;
	}
	arrayStack<int>* list = new arrayStack<int>[n + 1];
	int a, b;
	for (int i = 1; i <= r; i++)
	{
		cout << "Enter next relation/pair" << endl;
		cin >> a >> b;
		list[a].push(b);
		list[b].push(a);
	}
	arrayStack<int> unprocessedList;
	bool* out = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		out[i] = false;
	for(int i = 1; i <= n; i++)
		if (!out[i])
		{
			cout << "Next class is: " << i << " ";
			out[i] = true;
			unprocessedList.push(i);
			while (!unprocessedList.empty())
			{
				int j = unprocessedList.top();
				unprocessedList.pop();
				while (!list[j].empty())
				{
					int q = list[j].top();
					list[j].pop();
					if (!out[q])
					{
						cout << q << " ";
						out[q] = true;
						unprocessedList.push(q);
					}
				}
			}
			cout << endl;
		}
	cout << "End of list of equivalence classes" << endl;
	return 0;
}

int main()
{
	towersOfHanoi(4, 1, 2, 3);
	test01();
	return 0;
}