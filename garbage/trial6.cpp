#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

// `N Ã— N` matrix
#define N 10

// A queue node used in BFS
struct Node
{
	// `(x, y)` represents coordinates of a cell in the matrix
	int x, y;

	// `parent` stores the parent node of the current cell.
	// It will have only one entry, i.e., parent node
	vector<Node> parent;

	// As we are using struct as a key in a `std::set`,
	// we need to overload the below operators

	bool const operator==(const Node& ob) const {
		return x == ob.x && y == ob.y;
	}

	bool operator<(const Node& ob) const {
		return x < ob.x || (x == ob.x && y < ob.y);
	}
};

// Below arrays detail all four possible movements from a cell
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

// The function returns false if pt is not a valid position
bool isValid(int x, int y) {
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

// Function to print the complete path from source to destination
int printPath(vector<Node> const &path)
{
	if (path.size() == 0) {
		return 0;
	}

	int len = printPath(path[0].parent) + 1;
	cout << "(" << path[0].x << ", " << path[0].y << ") ";
	return len;
}

// Find the shortest route in a matrix from source cell `(x, y)` to
// destination cell `(N-1, N-1)`
int findPath(int matrix[][N], int x, int y)
{
	// create a queue and enqueue the first node
	queue<Node> q;
	Node src = {x, y};
	q.push(src);

	// set to check if the matrix cell is visited before or not
	set<Node> visited;
	visited.insert(src);

	// loop till queue is empty
	while (!q.empty())
	{
		// dequeue front node and process it
		Node curr = q.front();
		q.pop();

		int i = curr.x;
		int j = curr.y;

		// if the destination is found, print the shortest path and
		// return the shortest path length
		if (i == N - 1 && j == N - 1)
		{
			cout << "The shortest path is ";
			int len = printPath({curr});
			return len - 1;
		}

		// get the value of the current cell
		int n = matrix[i][j];

		// check all four possible movements from the current cell
		// and recur for each valid movement
		for (int k = 0; k < 4; k++)
		{
			// get next position coordinates using the value of the current cell
			int x = i + row[k] * n;
			int y = j + col[k] * n;

			// check if it is possible to go to the next position
			// from the current position
			if (isValid(x, y))
			{
				// construct the next cell node
				Node next = { x, y, {curr} };

				// if it isn't visited yet
				if (!visited.count(next))
				{
					// enqueue it and mark it as visited
					q.push(next);
					visited.insert(next);
				}
			}
		}
	}

	// return -1 if the path is not possible
	return 0;
}

int main()
{
	int matrix[N][N] =
	{
		{ 4, 4, 6, 5, 5, 1, 1, 1, 7, 4 },
		{ 3, 6, 2, 4, 6, 5, 7, 2, 6, 6 },
		{ 1, 3, 6, 1, 1, 1, 7, 1, 4, 5 },
		{ 7, 5, 6, 3, 1, 3, 3, 1, 1, 7 },
		{ 3, 4, 6, 4, 7, 2, 6, 5, 4, 4 },
		{ 3, 2, 5, 1, 2, 5, 1, 2, 3, 4 },
		{ 4, 2, 2, 2, 5, 2, 3, 7, 7, 3 },
		{ 7, 2, 4, 3, 5, 2, 2, 3, 6, 3 },
		{ 5, 1, 4, 2, 6, 4, 6, 7, 3, 7 },
		{ 1, 4, 1, 7, 5, 3, 6, 5, 3, 4 }
	};

	// Find a route in the matrix from source cell `(0, 0)` to
	// destination cell `(N-1, N-1)`
	int len = findPath(matrix, 0, 0);

	if (len != -1) {
		cout << "\nThe shortest path length is " << len;
	}
	else {
		cout << "Destination not possible";
	}

	return 0;
}