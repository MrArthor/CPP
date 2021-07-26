// C++ program to count squares
// in a rectangle of size m x n
#include <iostream>
using namespace std;

// Returns count of all squares
// in a rectangle of size m x n
int countSquares(int m, int n)
{

	// If n is smaller, swap m and n
	if (n < m) {
		int temp = m;
		m = n;
		n = temp;
	}

	// Now n is greater dimension,
	// apply formula
	return n * (n + 1) * (3 * m - n + 1) / 6;
}

// Driver Code
int main()
{
	int m = 10, n = 9;
	cout << "Count of squares is " << countSquares(m, n);
}

// This code is contributed by 29AjayKumar
