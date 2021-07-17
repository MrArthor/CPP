#include <bits/stdc++.h>

#define N 8
using namespace std;


struct Node
{
	int x, y;

	vector<Node> Par;

	bool const operator==(const Node &ob) const
	{
		return x == ob.x && y == ob.y;
	}

	bool operator<(const Node &ob) const
	{
		return x < ob.x || (x == ob.x && y < ob.y);
	}
};

int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

bool isValid(int x, int y)
{
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

int Printing(vector<Node> const &path)
{
	if (path.size() == 0)
	{
		return 0;
	}

	int Length = Printing(path[0].Par) + 1;
	cout << "(" << path[0].x << ", " << path[0].y << ") ";
	return Length;
}

int findPath(int matrix[][N], int x, int y, int a, int b)
{
	queue<Node> q;
	Node src = {x, y};
	q.push(src);

	set<Node> visited;
	visited.insert(src);

	while (!q.empty())
	{

		Node Current = q.front();
		q.pop();

		int i = Current.x;
		int j = Current.y;

		if (i == a && j == b)
		{
			cout << "The shortest path is ";
			//cout << i << " " << j << ", " << a << " " << b << endl;
			int Length = Printing({Current});
			return Length - 1;
		}

		int n = matrix[i][j];

		for (int k = 0; k < 4; k++)
		{

			int x = i + row[k] * n;
			int y = j + col[k] * n;

			if (isValid(x, y))
			{

				Node next = {x, y, {Current}};

				if (!visited.count(next))
				{

					q.push(next);
					visited.insert(next);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int Grid[][N] ={{5, 4, 3, 2, 1, 5, 3, 2}, {7, 3, 1, 3, 4, 5, 2, 1}, {6, 8, 3, 2, 5, 1, 7, 2}, {3, 4, 1, 4, 2, 5, 5, 4}, {4, 2, 5, 3, 2,
3, 2, 4}, {7, 1, 2, 8, 1, 4, 6, 5}, {6, 4, 5, 2, 4, 7, 5, 4}, {2, 1, 2, 4, 2, 2, 1, 5}};
	int Length = findPath(Grid, 5, 0, 5,5);
	if (Length == 0)
	{
		cout << "No path between given pair of source and destination Matrix";
	}
	else
	{
		cout <<endl<<"Length Of Path Is "<< Length << endl;
	}
	return 0;
}