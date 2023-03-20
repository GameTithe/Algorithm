#include <iostream>
#include <vector>
using namespace std;
int cnt;
int column;
int row;

const int coverType[4][3][2] =
{ { {0, 0}, {1, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} },
};

bool Set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;

	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;

		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int Cover(vector<vector<int>>& board)
{
	int x = -1, y = -1;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				x = j;
				y = i;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1 || y == -1)
		return 1;

	int rtn = 0;

	for (int i = 0; i < 4; i++)
	{
		if (Set(board, y, x, i, 1))
		{
			rtn += Cover(board);// 블럭이 잘 채워질 때
		}
		Set(board, y, x, i, -1);

	}

	return rtn;

}

int main()
{

	cin >> cnt;

	vector<vector<int>> board;
	int total = 0;
	char ch;

	for (int i = 0; i < cnt; i++)
	{
		cin >> column;
		cin >> row;

		for (int y = 0; y < column; y++)
		{
			vector<int> v;
			for (int x = 0; x < row; x++)
			{
				cin >> ch;

				if (ch == '#')
					v.push_back(1);
				if (ch == '.')
					v.push_back(0);

			}
			board.push_back(v);
		}

		cout << Cover(board);
		
		for (int j = 0; j < column; j++)
			board[j].clear();
		board.clear();

	}
}


/*
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
*/
