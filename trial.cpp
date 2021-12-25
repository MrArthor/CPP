#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

int BisectionMethod()
{

	auto Function = [&](double x)
	{
		return x * x * x - x * x + 2;
	};

	auto bisection = [&](double a, double b)
	{
		if (Function(a) * Function(b) >= 0)
		{
			cout << "You have not asSumed right a and b\n";
			return;
		}

		double c = a;
		while ((b - a) >= EPSILON)
		{

			c = (a + b) / 2;

			if (Function(c) == 0.0)
				break;

			else if (Function(c) * Function(a) < 0)
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
	auto Function = [&](double x)
	{
		return x * x * x - x * x + 2;
	};

	auto derivFunction = [&](double x)
	{
		return 3 * x * x - 2 * x;
	};

	auto NewtonRaphson = [&](double x)
	{
		double h = Function(x) / derivFunction(x);
		while (abs(h) >= EPSILON)
		{
			h = Function(x) / derivFunction(x);

			x = x - h;
		}

		cout << "The value of the root is : " << x;
	};

	double x0 = -20;
	NewtonRaphson(x0);
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

	// Function to evaluate the polynomial
	auto DividedDifferenceTable = [&](float x[], float y[][10], int n)
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

	auto applyFormula = [&](float value, float x[], float y[][10], int n)
	{
		float Sum = y[0][0];

		for (int i = 1; i < n; i++)
		{
			Sum = Sum + (proterm(i, value, x) * y[0][i]);
		}
		return Sum;
	};

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

	int n = 4;
	float value, Sum, y[10][10];
	float x[] = {5, 6, 9, 11};

	y[0][0] = 12;
	y[1][0] = 13;
	y[2][0] = 14;
	y[3][0] = 16;

	DividedDifferenceTable(x, y, n);

	printDiffTable(y, n);

	value = 7;

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

	auto fact = [&](int n)
	{
		int f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;
		return f;
	};




	int n = 4;
	float x[] = {45, 50, 55, 60};

	float y[n][n];
	y[0][0] = 0.7071;
	y[1][0] = 0.7660;
	y[2][0] = 0.8192;
	y[3][0] = 0.8660;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << x[i]
			 << "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j]
				 << "\t";
		cout << endl;
	}

	float value = 52;

	float Sum = y[0][0];
	float u = (value - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++)
	{
		Sum = Sum + (u_cal(u, i) * y[0][i]) /
						fact(i);
	}

	cout << "\n Value at " << value << " is "
		 << Sum << endl;
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

	auto fact = [&](int n)
	{
		int f = 1;
		for (int i = 2; i <= n; i++)
			f *= i;
		return f;
	};

	int n = 5;
	float x[] = {1891, 1901, 1911,
				 1921, 1931};

	float y[n][n];
	y[0][0] = 46;
	y[1][0] = 66;
	y[2][0] = 81;
	y[3][0] = 93;
	y[4][0] = 101;

	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << setw(4) << y[i][j]
				 << "\t";
		cout << endl;
	}

	float value = 1925;

	float Sum = y[n - 1][0];
	float u = (value - x[n - 1]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++)
	{
		Sum = Sum + (u_cal(u, i) * y[n - 1][i]) /
						fact(i);
	}

	cout << "\n Value at " << value << " is "
		 << Sum << endl;
	return 0;
}
int LagrangeInterpolationMethod()
{
	struct Data
	{
		int x, y;
	};

	auto interpolate = [&](Data f[], int xi, int n)
	{
		double result = 0;

		for (int i = 0; i < n; i++)
		{

			double term = f[i].y;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
					term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
			}

			result += term;
		}

		return result;
	};

	Data f[] = {{0, 2}, {1, 3}, {2, 12}, {5, 147}};

	cout << "Value of f(3) is : " << interpolate(f, 3, 5);

	return 0;
}
int Simpsons38Rule()
{
	auto Function = [&](float x)
	{
		return log(x);
	};

	auto calculate = [&](float lower_limit, float upper_limit,
						 int interval_limit)
	{
		float value;
		float interval_size = (upper_limit - lower_limit) / interval_limit;
		float Sum = Function(lower_limit) + Function(upper_limit);

		for (int i = 1; i < interval_limit; i++)
		{
			if (i % 3 == 0)
				Sum = Sum + 2 * Function(lower_limit + i * interval_size);
			else
				Sum = Sum + 3 * Function(lower_limit + i * interval_size);
		}
		return (3 * interval_size / 8) * Sum;
	};

	int interval_limit = 10;
	float lower_limit = 1;
	float upper_limit = 10;
	float integral_res = calculate(lower_limit, upper_limit,
								   interval_limit);

	cout << integral_res;
	return 0;
}
int Simpson13Rule()
{
	auto Function = [&](float x)
	{
		return log(x);
	};

	auto simpsons_ = [&](float ll, float ul, int n)
	{
		float h = (ul - ll) / n;

		float x[10], fx[10];

		for (int i = 0; i <= n; i++)
		{
			x[i] = ll + i * h;
			fx[i] = Function(x[i]);
		}

		float res = 0;
		for (int i = 0; i <= n; i++)
		{
			if (i == 0 || i == n)
				res += fx[i];
			else if (i % 2 != 0)
				res += 4 * fx[i];
			else
				res += 2 * fx[i];
		}
		res = res * (h / 3);
		return res;
	};

	float lower_limit = 4;
	float upper_limit = 5.2;
	int n = 6;
	cout << simpsons_(lower_limit, upper_limit, n);
	return 0;
}

int SecantMethod()
{
	auto f = [&](float x)
	{
		float f = pow(x, 3) + x - 1;
		return f;
	};

	auto secant = [&](float x1, float x2, float E)
	{
		float n = 0, xm, x0, c;
		if (f(x1) * f(x2) < 0)
		{
			do
			{

				x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

				c = f(x1) * f(x0);

				x1 = x2;
				x2 = x0;

				n++;

				if (c == 0)
					break;
				xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
			} while (fabs(xm - x0) >= E);

			cout << "Root of the given equation=" << x0 << endl;
			cout << "No. of iterations = " << n << endl;
		}
		else
			cout << "Can not find a root in the given interval";
	};

	float x1 = 0, x2 = 1, E = 0.0001;
	secant(x1, x2, E);
	return 0;
}

int StirlingMethod()
{
	auto Stirling = [&](float x[], float fx[], float x1,
						int n)
	{
		float h, a, u, y1 = 0, N1 = 1, d = 1,
					   N2 = 1, d2 = 1, temp1 = 1, temp2 = 1,
					   k = 1, l = 1, delta[n][n];

		int i, j, s;
		h = x[1] - x[0];
		s = floor(n / 2);
		a = x[s];
		u = (x1 - a) / h;

		for (i = 0; i < n - 1; ++i)
		{
			delta[i][0] = fx[i + 1] - fx[i];
		}
		for (i = 1; i < n - 1; ++i)
		{
			for (j = 0; j < n - i - 1; ++j)
			{
				delta[j][i] = delta[j + 1][i - 1] - delta[j][i - 1];
			}
		}

		y1 = fx[s];

		for (i = 1; i <= n - 1; ++i)
		{
			if (i % 2 != 0)
			{
				if (k != 2)
				{
					temp1 *= (pow(u, k) -
							  pow((k - 1), 2));
				}
				else
				{
					temp1 *= (pow(u, 2) -
							  pow((k - 1), 2));
				}
				++k;
				d *= i;
				s = floor((n - i) / 2);
				y1 += (temp1 / (2 * d)) *
					  (delta[s][i - 1] +
					   delta[s - 1][i - 1]);
			}
			else
			{
				temp2 *= (pow(u, 2) -
						  pow((l - 1), 2));
				++l;
				d *= i;
				s = floor((n - i) / 2);
				y1 += (temp2 / (d)) *
					  (delta[s][i - 1]);
			}
		}

		cout << y1;
	};

	int n;
	n = 5;
	float x[] = {0, 0.5, 1.0, 1.5, 2.0};
	float fx[] = {0, 0.191, 0.341, 0.433,
				  0.477};

	float x1 = 1.22;

	Stirling(x, fx, x1, n);
	return 0;
}
int main()

{
	cout << "\t\t\t\tBNM Project\n";
	cout << "The following Methods has been used \n";
	cout << "1.Bisection Method\n";
	cout << "2.Secant Method\n";
	cout << "3.Newton Forward Interpolation Method\n";
	cout << "4.Newton Backward Interpolation Method\n";
	cout << "5.Newton Divided Difference Interpolation Method\n";
	cout << "6.Newton Raphson Method\n";
	cout << "7.Lagrange Method\n";
	cout << "8.Stirling Interpolation Method\n";
	cout << "9.Simpson 1/3 Method\n";
	cout << "10.Simpson 3/8 Method\n";
	cout << " Select desired option[1-10] for choosing appropriate method\n";
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout<<endl;
		BisectionMethod();
		break;
	case 2:
		cout <<endl;
		 SecantMethod();
		break;
	case 3:
		cout<<endl;
		NewtonForwardInterpolation();
		break;
	case 4:
		cout<<endl;
		NewtonBackwardInterpolationMethod();
		break;
	case 5:
		cout<<endl;
		NewtonDividedDifferenceMethod();
		break;
	case 6:
		cout<<endl;
		NRMethod();
		break;
	case 7:
		cout<<endl;
		LagrangeInterpolationMethod();
		break;
	case 8:
		cout<<endl;
		cout<<"Value of f(x) at 1.22= ";
		StirlingMethod();
		break;
	case 9:
		cout<<endl;
		cout<<"Integral of logx from 4 to 5.2 = \n";
		Simpson13Rule();
		break;
	case 10:
		cout<<endl;
		cout<<"Integral of logx from 1 to 10 = \n";
		Simpsons38Rule();
		break;
	default:
		cout<<"Wrong number selected\n";
	}

	return 0;
}