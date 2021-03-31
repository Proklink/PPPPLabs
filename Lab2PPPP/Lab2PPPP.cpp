#include <iostream>
#include <cmath>

using namespace std;

struct Solution {
	char ans;
	double* x;
	double* y;
};

struct Solution output_0() {
	struct Solution solution = {'0', NULL, NULL};
	return solution;
}

struct Solution output_1(double A1, double A2, double A3) {
	double* k = new double;
	double* n = new double;

	*k = -A1 / A2;
	*n = A3 / A2;

	struct Solution solution = { '1', k, n };
	return solution;
}

struct Solution output_2(double a, double b, double c, double d, double e, double f) {
	double* x = new double;
	double *y = new double;
	*y = (a * f - c * e) / (a * d - c * b);
	*x = (d * e - b * f) / (d * a - b * c);

	struct Solution solution = { '2', x, y };
	return solution;


}

struct Solution output_3_1(double a, double c, double e, double f) {
	double *x = new double;

	if (a == 0)
		*x = f / c;
	else if (c == 0)
		*x = e / a;
	else if (e == 0 || f == 0)
		*x = 0;


	struct Solution solution = { '3', x, NULL };
	return solution;
}

struct Solution output_3_2(double a, double c, double e, double f) {
	double *x = new double;

	if (e == 0)
		*x = f / c;
	else if (f == 0)
		*x = e / a;
	else
		*x = e / a;

	struct Solution solution = { '3', x, NULL };
	return solution;
}

struct Solution output_4_1(double b, double d, double e, double f) {
	double *y = new double;

	if (b == 0)
		*y = f / d;
	else if (d == 0)
		*y = e / b;
	else if (e == 0 || f == 0)
		*y = 0;


	struct Solution solution = { '4', NULL, y};
	return solution;
}

struct Solution output_4_2(double b, double d, double e, double f) {
	double *y = new double;

	if (e == 0)
		*y = f / d;
	else if (f == 0)
		*y = e / b;
	else
		*y = e / b;

	struct Solution solution = { '4', NULL, y };
	return solution;
}

struct Solution output_5() {
	struct Solution solution = {'5', NULL, NULL};
	return solution;
}

struct Solution input_handler(double a, double b, double c, double d, double e, double f) {

	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		return output_5();
	}
	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		return output_2(a, b, c, d, e, f);
		
	}
	else if ( ((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)) ) || 
				(a == 0 && c == 0 && e / b != f / d) ||
				(b == 0 && d == 0 && e / a != f / c) || 
				(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))

		 {			
			if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) || (c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
			{
				cout << "4_1 is executing\n";
				return output_4_1(b, d, e, f);

			}
			else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) || (c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
			{
				cout << "3_1 is executing\n";
				return output_3_1(a, c, e, f);
			}
			else
				return output_0();

		 }

	else if (a == 0 && c == 0)
	{
		cout << "4_2 is executing\n";
		return output_4_2(b, d, e, f);
	}
	else if (b == 0 && d == 0)
	{
		cout << "3_2 is executing\n";
		return output_3_2(a, e, c, f);
	}
	else if (b == 0 && e == 0)
	{
		cout << "1_1 is executing\n";
		return output_1(c, d, f);
	}
	else if (d == 0 && f == 0)
	{
		cout << "1_2 is executing\n";
		return output_1(a, b, e);
	}
	else if (a == 0 && e == 0)
	{
		cout << "1_3 is executing\n";
		return output_1(d, c, f);
	}
	else if (c == 0 && f == 0)
	{
		cout << "1_4 is executing\n";
		return output_1(b, a, e);

		
	}
	else if ((a / b == c / d))
	{
		cout << "1_5 is executing\n";
		return output_1(c, d, f);
	}
	else
	{
		cout << "Are you kidding me?";
		struct Solution solution = { '6', NULL, NULL };
		return solution;
	}

	
}

void source_code(double a, double b, double c, double d, double e, double f) {

	
	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		cout << '5' << endl;
	}
	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		double y = (a * f - c * e) / (a * d - c * b);
		double x = (d * e - b * f) / (d * a - b * c);

		cout << "2 " << x << ' ' << y << endl;
	}
	else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
	{
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{
			double y;
			if (b == 0)
				y = f / d;
			else if (d == 0)
				y = e / b;
			else if (e == 0 || f == 0)
				y = 0;
			cout << '4' << ' ' << y << endl;
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x;
			if (a == 0)
				x = f / c;
			else if (c == 0)
				x = e / a;
			else if (e == 0 || f == 0)
				x = 0;
			cout << '3' << ' ' << x << endl;
		}
		else
			cout << '0' << endl;
	}
	else if (a == 0 && c == 0)
	{
		double y;
		if (e == 0)
			y = f / d;
		else if (f == 0)
			y = e / b;
		else
			y = e / b;
		cout << '4' << ' ' << y << endl;
	}
	else if (b == 0 && d == 0)
	{
		double x;
		if (e == 0)
			x = f / c;
		else if (f == 0)
			x = e / a;
		else
			x = e / a;
		cout << '3' << ' ' << x << endl;
	}
	else if (b == 0 && e == 0)
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n << endl;
	}
	else if (d == 0 && f == 0)
	{
		double k, n;
		k = -a / b;
		n = e / b;
		cout << '1' << ' ' << k << ' ' << n << endl;
	}
	else if (a == 0 && e == 0)
	{
		double k, n;
		k = -d / c;
		n = f / c;
		cout << '1' << ' ' << k << ' ' << n << endl;
	}
	else if (c == 0 && f == 0)
	{
		double k, n;
		k = -b / a;
		n = e / a;
		cout << '1' << ' ' << k << ' ' << n << endl;
	}
	else if ((a / b == c / d))
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n << endl;
	}
	else
	{
		cout << "Are you kidding me?";
	}
	
}



void output_formater(struct Solution *sol) {

	cout << sol->ans << " ";
	if (sol->x != NULL)
		cout << *sol->x << " ";
	if (sol->y != NULL)
		cout << *sol->y;
	cout << endl;

}

int main()
{
	double a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	source_code(a, b, c, d, e, f);
	
	struct Solution sol = input_handler(a, b, c, d, e, f);
	output_formater(&sol);

	delete sol.x, sol.y;

	return 0;

}