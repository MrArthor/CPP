#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

int BisectionMethod()
{
	// This declares a lambda, which can be called just like a function
	auto func = [&](double x)
	{
		return x * x * x - x * x + 2;
	};

	auto bisection = [&](double a, double b)
	{
		if (func(a) * func(b) >= 0)
		{
			cout << "You have not assumed right a and b\n";
			return;
		}

		double c = a;
		while ((b - a) >= EPSILON)
		{
			// Find middle point
			c = (a + b) / 2;

			// Check if middle point is root
			if (func(c) == 0.0)
				break;

			// Decide the side to repeat the steps
			else if (func(c) * func(a) < 0)
				b = c;
			else
				a = c;
		}
		cout << "The value of root is : " << c;
	};

	double a = -200, b = 300;
	bisection(a, b);
	return 0;
}

int NRMethod()
{
	auto func = [&](double x)
	{
		return x * x * x - x * x + 2;
	};

	// Derivative of the above function which is 3*x^x - 2*x
	auto derivFunc = [&](double x)
	{
		return 3 * x * x - 2 * x;
	};

	// Function to find the root
	auto newtonRaphson = [&](double x)
	{
		double h = func(x) / derivFunc(x);
		while (abs(h) >= EPSILON)
		{
			h = func(x) / derivFunc(x);

			// x(i+1) = x(i) - f(x) / f'(x)
			x = x - h;
		}

		cout << "The value of the root is : " << x;
	};

	// Driver program to test above
	double x0 = -20; // Initial values assumed
	newtonRaphson(x0);
	return 0;
}

int NewtonDividedDifferenceMethod()
{
	auto proterm = [&](int i, float value, float x[])
	{
		float pro = 1;
		for (int j = 0; j < i; j++)
		{
			pro = pro * (value - x[j]);
		}
		return pro;
	};

	// Function for calculating
	// divided difference table
	auto dividedDiffTable = [&](float x[], float y[][10], int n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				y[j][i] = (y[j][i - 1] - y[j + 1]
										  [i - 1]) /
						  (x[j] - x[i + j]);
			}
		}
	};

	// Function for applying Newton's
	// divided difference formula
	auto applyFormula = [&](float value, float x[], float y[][10], int n)
	{
		float sum = y[0][0];

		for (int i = 1; i < n; i++)
		{
			sum = sum + (proterm(i, value, x) * y[0][i]);
		}
		return sum;
	};

	// Function for displaying
	// divided difference table
	auto printDiffTable = [&](float y[][10], int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				cout << setprecision(4) << y[i][j] << "\t ";
			}
			cout << "\n";
		}
	};

	// Driver Function
	// number of inputs given
	int n = 4;
	float value, sum, y[10][10];
	float x[] = {5, 6, 9, 11};

	// y[][] is used for divided difference
	// table where y[][0] is used for input
	y[0][0] = 12;
	y[1][0] = 13;
	y[2][0] = 14;
	y[3][0] = 16;

	// calculating divided difference table
	dividedDiffTable(x, y, n);

	// displaying divided difference table
	printDiffTable(y, n);

	// value to be interpolated
	value = 7;

	// printing the value
	cout << "\nValue at " << value << " is "
		 << applyFormula(value, x, y, n) << endl;
	return 0;
}

int NewtonForwardInterpolation()
{
	auto u_cal = [&](float u, int n)
	{
		float temp = u;
		for (int i = 1; i < n; i++)
			temp = temp * (u - i);
		return temp;
	};

	// calculating factorial of given number n
	auto fact = [&](int n)
	{
		int f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;
		return f;
	};

	// Number of values given
	int n = 4;
	float x[] = {45, 50, 55, 60};

	// y[][] is used for difference table
	// with y[][0] used for input
	float y[n][n];
	y[0][0] = 0.7071;
	y[1][0] = 0.7660;
	y[2][0] = 0.8192;
	y[3][0] = 0.8660;

	// Calculating the forward difference
	// table
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}

	// Displaying the forward difference table
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << x[i]
			 << "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j]
				 << "\t";
		cout << endl;
	}

	// Value to interpolate at
	float value = 52;

	// initializing u and sum
	float sum = y[0][0];
	float u = (value - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++)
	{
		sum = sum + (u_cal(u, i) * y[0][i]) /
						fact(i);
	}

	cout << "\n Value at " << value << " is "
		 << sum << endl;
	return 0;
}

int NewtonBackwardInterpolationMethod()
{
	auto u_cal = [&](float u, int n)
	{
		float temp = u;
		for (int i = 1; i < n; i++)
			temp = temp * (u + i);
		return temp;
	};

	// Calculating factorial of given n
	auto fact = [&](int n)
	{
		int f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;
		return f;
	};

	// number of values given
	int n = 5;
	float x[] = {1891, 1901, 1911,
				 1921, 1931};

	// y[][] is used for difference
	// table and y[][0] used for input
	float y[n][n];
	y[0][0] = 46;
	y[1][0] = 66;
	y[2][0] = 81;
	y[3][0] = 93;
	y[4][0] = 101;

	// Calculating the backward difference table
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
	}

	// Displaying the backward difference table
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << setw(4) << y[i][j]
				 << "\t";
		cout << endl;
	}

	// Value to interpolate at
	float value = 1925;

	// Initializing u and sum
	float sum = y[n - 1][0];
	float u = (value - x[n - 1]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++)
	{
		sum = sum + (u_cal(u, i) * y[n - 1][i]) /
						fact(i);
	}

	cout << "\n Value at " << value << " is "
		 << sum << endl;
	return 0;
}
int LagrangeInterpolationMethod()
{
	struct Data
	{
		int x, y;
	};

	// function to interpolate the given data points using Lagrange's formula
	// xi corresponds to the new data point whose value is to be obtained
	// n represents the number of known data points
	auto interpolate = [&](Data f[], int xi, int n)
	{
		double result = 0; // Initialize result

		for (int i = 0; i < n; i++)
		{
			// Compute individual terms of above formula
			double term = f[i].y;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
					term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
			}

			// Add current term to result
			result += term;
		}

		return result;
	};

	// driver function to check the program

	// creating an array of 4 known data points
	Data f[] = {{0, 2}, {1, 3}, {2, 12}, {5, 147}};

	// Using the interpolate function to obtain a data point
	// corresponding to x=3
	cout << "Value of f(3) is : " << interpolate(f, 3, 5);

	return 0;
}
int main()
{
	LagrangeInterpolationMethod();
	return 0;
}