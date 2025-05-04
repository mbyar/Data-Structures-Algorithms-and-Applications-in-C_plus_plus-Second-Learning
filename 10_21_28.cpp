#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int DIVISOR = 4099,
MAX_CODES = 4096,
BYTE_SIZE = 8,
EXCESS = 4,
ALPHA = 256,
MASK = 15,
MASK1 = 255,
MASK2 = 15;
typedef pair<const long, int>pairType;
template<class K, class E>
class hashChains
{
public:
	hashChains(int num);
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
int leftOver;
bool bitsLeftOver = false;
ifstream in; 
ofstream out;
void setFiles(int argc, char* argv[])
{
	char inputFile[50], outputFile[54];
	if (argc >= 2)
		strcpy(inputFile, argv[1]);
	else
	{
		cout << "Enter name of file to compress" << endl;
		cin >> inputFile;
	}
	in.open(inputFile, ios::binary);
	if (in.fail())
	{
		cerr << "Cannot open " << inputFile << endl;
		exit(1);
	}
	strcpy(outputFile, inputFile);
	strcat(outputFile, ".zzz");
	out.open(outputFile, ios::binary);
}
void output(long pcode)
{
	int c, d;
	if (bitsLeftOver)
	{
		d = int(pcode & MASK1);
		c = int((leftOver << EXCESS) | (pcode >> BYTE_SIZE));
		out.put(c);
		out.put(d);
		bitsLeftOver = false;
	}
	else
	{
		leftOver = pcode & MASK2;
		c = int(pcode >> EXCESS);
		out.put(c);
		bitsLeftOver = true;
	}
}
void compress()
{
	hashChains<long, int> h(DIVISOR);
	for (int i = 0; i < ALPHA; i++)
		h.insert(pairType(i, i));
	int codesUsed = ALPHA;
	int c = in.get();
	if (c != EOF)
	{
		long pcode = c;
		while ((c = in.get()) != EOF)
		{
			long theKey = (pcode << BYTE_SIZE) + c;
			pairType* thePair = h.find(theKey);
			if (thePair == NULL)
			{
				output(pcode);
				if (codesUsed < MAX_CODES)
					h.insert(pairType((pcode << BYTE_SIZE) | c, codesUsed++));
				pcode = c;
			}
			else pcode = thePair->second;
		}
		output(pcode);
		if (bitsLeftOver)
			out.put(leftOver << EXCESS);
	}
	out.close();
	in.close();
}
const int MAX_CODES = 4096,
BYTE_SIZE = 8,
EXCESS = 4,
ALPHA = 256,
MASK = 15;
typedef pair<int, char>pairType;
pairType ht[MAX_CODES];
char s[MAX_CODES];
int size;
int leftOver;
bool btsLeftOver = false;
ifstream in;
ofstream out;
void output(int code)
{
	::size = -1;
	while (code >= ALPHA)
	{
		s[++::size] = ht[code].second;
		code = ht[code].first;
	}
	s[++::size] = code;
	for (int i = ::size; i >= 0; i--)
		out.put(s[i]);
}
bool getCode(int& code)
{
	int c, d;
	if ((c = in.get()) == EOF)
		return false;
	if (bitsLeftOver)
		code = (leftOver << BYTE_SIZE) | c;
	else
	{
		d = in.get();
		code = (c << EXCESS) | (d >> EXCESS);
		leftOver = d & MASK;
	}
	bitsLeftOver = !bitsLeftOver;
	return true;
}
void decompress()
{
	int codesUsed = ALPHA;
	int pcode, ccode;
	if (getCode(pcode))
	{
		s[0] = pcode;
		out.put(s[0]);
		::size = 0;
		while (getCode(ccode))
		{
			if (ccode < codesUsed)
			{
				output(ccode);
				if (codesUsed < MAX_CODES)
				{
					ht[codesUsed].first = pcode;
					ht[codesUsed++].second = s[::size];
				}
			}
			else
			{
				ht[codesUsed].first = pcode;
				ht[codesUsed++].second = s[::size];
				output(ccode);
			}
			pcode = ccode;
		}
	}
	out.close();
	in.close();
}
void main(int argc, char* argv[])
{
	setFiles(argc, argv);
	compress();
}