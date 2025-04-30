#include<iostream>
#include<queue>
using namespace std;
queue<int>* track;
int numberOfCars;
int numberOfTracks;
int smallestCar;
int itsTrack;
void outputFromHoldingTrack()
{
	track[itsTrack].pop();
	cout << "Move car " << smallestCar << " from holding track " << itsTrack << " to output track" << endl;
	smallestCar = numberOfCars + 2;
	for (int i = 1; i <= numberOfTracks; i++)
		if (!track[i].empty() && track[i].front() < smallestCar)
		{
			smallestCar = track[i].front();
			itsTrack = i;
		}
}
bool putInHoldingTrack(int c)
{
	int bestTrack = 0, bestLast = 0;
	for (int i = 1; i <= numberOfTracks; i++)
		if (!track[i].empty())
		{
			int lastCar = track[i].back();
			if (c > lastCar && lastCar > bestLast)
			{
				bestLast = lastCar;
				bestTrack = i;
			}
		}
		else
			if (bestTrack == 0)
				bestTrack = i;
	if (bestTrack == 0)
		return false;
	track[bestTrack].push(c);
	cout << "Move car " << c << " from input track " << "to holding track " << bestTrack << endl;
	if (c < smallestCar)
	{
		smallestCar = c;
		itsTrack = bestTrack;
	}
	return true;
}
template<class T>
bool findPath()
{
	if ((start.row == finish.row) && (start.col == finish.col))
	{
		pathLength = 0;
		return true;
	}
	position offset[4];
	offset[0].row = 0; offset[0].col = 1;
	offset[1].row = 1; offset[1].col = 0;
	offset[2].row = 0; offset[2].col = -1;
	offset[3].row = -1; offset[3].col = 0;
	for (int i = 0; i <= size + 1; i++)
	{
		grid[0][i] = grid[size + 1][i] = 1;
		grid[i][0] = grid[i][size + 1] = 1;
	}
	position here = atart;
	grid[start.row][start.col] = 2;
	int numOfNbrs = 4;
	arrayQueue<position> q;
	position nbr;
	do
	{
		for (int i = 0; i < numOfNbrs; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == 0)
			{
				grid[nbr.row][nbr.col] = grid[here.row][here.col] + 1;
				if ((nbr.row == finish.row) && (finish.col))break;
				q.push(nbr);
			}
		}
		if ((nbr.row == finish.row) && (nbr.col == finish.col))break;
		if (q.empty())
			return false;
		here = q.front();
		q.pop();
	} while (true);
	pathLength = grid[finish.row][finish.col] - 2;
	path = new position[pathLength];
	here = finish;
	for (int j = pathLength - 1; j >= 0; j--)
	{
		path[j] = here;
		for (int i = 0; i < numOfNbrs; i++)
		{
			nbr.row = here.row + offset[i].row;
			nbr.col = here.col + offset[i].col;
			if (grid[nbr.row][nbr.col] == j + 2)break;
		}
		here = nbr;
	}
	return true;
}
template<class T>
void labelComponents()
{
	position offset[4];
	offset[0].row = 0; offset[0].col = 1;
	offset[1].row = 1; offset[1].col = 0;
	offset[2].row = 0; offset[2].col = -1;
	offset[3].row = -1; offset[3].col = 0;
	for (int i = 0; i <= size + 1; i++)
	{
		pixel[0][i] = pixel[size + 1][i] = 0;
		pixel[i][0] = pixel[i][size + 1] = 0;
	}
	int numOfNbrs = 4;
	arrayQueue<position> q;
	position here, nbr;
	int id = 1;
	for(int r = 1;r<=size;r++)
		for(int c= 1;c<=size;c++)
			if (pixel[r][c] == 1)
			{
				pixel[r][c] = ++id;
				here.row = r;
				here.col = c;
				while (true)
				{
					for (int i = 0; i < numOfNbrs; i++)
					{
						nbr.row = here.row + offset[i].row;
						nbr.col = here.col + offset[i].col;
						if (pixel[nbr.row][nbr.col] == 1)
						{
							pixel[nbr.row][nbr.col] = id;
							q.push(nbr);
						}
					}
					if (q.empty())break;
					here = q.front();
					q.pop();
				}
			}
}
struct task
{
	int machine;
	int time;
	task(int theMachine = 0, int theTime = 0)
	{
		machine = theMachine;
		time = theTime;
	}
};
template<typename T>
class arrayQueue
{
public:
	void push(T value);
	T front();
	void pop();
	bool empty();
};
struct job
{
	arrayQueue<task> taskQ;
	int length;
	int arrivalTime;
	int id;
	job(int theId = 0)
	{
		id = theId;
		length = 0;
		arrivalTime = 0;
	}
	void addTask(int theMachine, int theTime)
	{
		task theTask(theMachine, theTime);
		taskQ.push(theTask);
	}
	int removeNextTask()
	{
		int theTime = taskQ.front().time;
		taskQ.pop();
		length += theTime;
		return theTime;
	}
};
struct machine
{
	arrayQueue<job*> jobQ;
	int changeTime;
	int totalWait;
	int numTasks;
	job* activeJob;
	machine()
	{
		totalWait = 0;
		numTasks = 0;
		activeJob = NULL;
	}
};
class eventList
{
public:
	eventList(int theNumMachines, int theLargeTime)
	{
		if (theNumMachines < 1)
			//throw illegalParameterValue("number of machines must be >= 1")
			;
		numMachines = theNumMachines;
		finishTime = new int[numMachines + 1];
		for (int i = 1; i <= numMachines; i++)
			finishTime[i] = theLargeTime;
	}
	int nextEventMachine()
	{
		int p = 1;
		int t = finishTime[1];
		for(int i = 2; i <= numMachines; i++)
			if (finishTime[i] < t)
			{
				p = i;
				t = finishTime[i];
			}
		return p;
	}
	int nextEventTime(int theMachine)
	{
		return finishTime[theMachine];
	}
	void setFinishTime(int theMachine, int theTime)
	{
		finishTime[theMachine] = theTime;
	}
private:
	int* finishTime;
	int numMachines;
};
int timeNow;
int numMachines;
int numJobs;
eventList* eList;
machine* mArray;
int largeTime = 10000;
void inputData()
{
	cout << "Enter number of machines and jobs" << endl;
	cin >> numMachines >> numJobs;
	if (numMachines < 1 || numJobs < 1)
		//throw illegalInputData("number of machines and jobs must be >= 1")
		;
	eList = new eventList(numMachines, largeTime);
	mArray = new machine[numMachines + 1];
	cout << "Enter change-over times for machines" << endl;
	int ct;
	for (int j = 1; j <= numMachines; j++)
	{
		cin >> ct;
		if (ct < 0)
			//throw illegalInputData("change-over time must be >= 0")
			;
		mArray[j].changeTime = ct;
	}
	job* theJob;
	int numTasks, firstMachine, theMachine, theTaskTime;
	for (int i = 1; i <= numJobs; i++)
	{
		cout << "Enter number of tasks for job " << i << endl;
		cin >> numTasks;
		firstMachine = 0;
		if (numTasks < 1)
			//throw illegalInputData("each job must have > 1 task")
			;
		theJob = new job(i);
		cout << "Enter the tasks (machine, time)" << " in process order" << endl;
		for (int j = 1; j <= numTasks; j++)
		{
			cin >> theMachine >> theTaskTime;
			if (theMachine < 1 || theMachine > numMachines || theTaskTime < 1)
				//throw illegalInputData("bad machine number or task time")
				;
			if (j == 1)
				firstMachine = theMachine;
			theJob->addTask(theMachine, theTaskTime);
		}
		mArray[firstMachine].jobQ.push(theJob);
	}
}
job* changeState(int theMachine)
{
	job* lastJob;
	if (mArray[theMachine].activeJob == NULL)
	{
		lastJob = NULL;
		if (mArray[theMachine].jobQ.empty())
			eList->setFinishTime(theMachine, largeTime);
		else
		{
			mArray[theMachine].activeJob = mArray[theMachine].jobQ.front();
			mArray[theMachine].jobQ.pop();
			mArray[theMachine].totalWait += timeNow - mArray[theMachine].activeJob->arrivalTime;
			mArray[theMachine].numTasks++;
			int t = mArray[theMachine].activeJob->removeNextTask();
			eList->setFinishTime(theMachine, timeNow + t);
		}
	}
	else
	{
		lastJob = mArray[theMachine].activeJob;
		mArray[theMachine].activeJob = NULL;
		eList->setFinishTime(theMachine, timeNow + mArray[theMachine].changeTime);
	}
	return lastJob;
}
void startShop()
{
	for (int p = 1; p <= numMachines; p++)
		changeState(p);
}
bool moveToNextMachine(job* theJob)
{
	if (theJob->taskQ.empty())
	{
		cout << "Job " << theJob->id << " has complated at "
			<< timeNow << " Total wait was" << (timeNow - theJob->length) << endl;
		return false;
	}
	else
	{
		int p = theJob->taskQ.front().machine;
		mArray[p].jobQ.push(theJob);
		theJob->arrivalTime = timeNow;
		if (eList->nextEventTime(p) == largeTime)
			changeState(p);
		return true;
	}
}
void simulate()
{
	while (numJobs > 0)
	{
		int nextToFinish = eList->nextEventMachine();
		timeNow = eList->nextEventTime(nextToFinish);
		job* theJob = changeState(nextToFinish);
		if (theJob != NULL && !moveToNextMachine(theJob))
			numJobs--;
	}
}
void outputStatistics()
{
	cout << "Finish time = " << timeNow << endl;
	for (int p = 1; p <= numMachines; p++)
	{
		cout << "Machine " << p << " completed " << mArray[p].numTasks << " tasks" << endl;
		cout << "The total wait time was " << mArray[p].totalWait << endl;
		cout << endl;
	}
}
void test01()
{
	inputData();
	startShop();
	simulate();
	outputStatistics();
}
int main()
{

	return 0;
}