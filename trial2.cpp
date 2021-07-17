#include <iostream>
using namespace std;
struct Position
{

	int row, col;
};

int main()
{
	int N = 5;
	//cin>>N;
	Position Source = {0, 0}, Destination = {4, 4};
	int Array[N][N] = {{3, 5, 7, 4, 6}, {5, 3, 1, 5, 3}, {2, 8, 3, 1, 4}, {4, 5, 7, 2, 3}, {3, 3, 3, 2, 8}};
	int StepCount = -1;
	for (int i = Source.row; i < N; i++)
	{

		for (int j = Source.col; j < N; j++)
		{
			if (i == Destination.row && j == Destination.col)
			{
				break;
			}
			else if (i == Destination.row && j > Destination.col)
			{
				if (j + Array[i][j] < N)
				{
					j += Array[i][j];
					StepCount++;
				}
			}
			else if (i> Destination.row && j== Destination.col)
			{
				if (i + Array[i][j] < N)
				{
					i += Array[i][j];
					StepCount++;
				}
			}
		}
	}
	return 0;
}