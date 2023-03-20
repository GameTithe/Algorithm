#include <iostream>
using namespace std;


#define NO false
#define FRIEND true

int cnt;
int member;
int num;
bool check[20][20] = { false };
bool taken[20] = { false };

int MakePair();

int main()
{
	
	cin >> cnt;

	
	int st, nd;
	int total = 0;

	for (int i = 0; i < cnt; i++)
	{
		cin >> member;
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cin >> st;
			cin >> nd;
			check[st][nd] = FRIEND;
			check[nd][st] = FRIEND;
		}

		cout << MakePair();

	}
}

int MakePair()
{
	int find;
	int total = 0;

	for (int i = 0; i < member; i++)
	{
		if (taken[i] == NO)
		{
			taken[i] = FRIEND;
			find = i;
			break;
		}
		if (i + 1 == member)
			return 0;
	}

	for (int i = find + 1; i < member; i++)
	{
		if (taken[i] == NO && check[i][find] == FRIEND && check[find][i] == FRIEND)
		{
			taken[i] = FRIEND;
			taken[find] = FRIEND;
			total++;
		}
	}
	return MakePair() + total;
}

/*
* 
3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
*/
