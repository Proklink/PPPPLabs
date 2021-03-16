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

struct Solution output_1(int A1, int A2, int A3) {
	double k, n;

	k = -A1 / A2;
	n = A3 / A2;
	cout << '1' << ' ' << k << ' ' << n;

	struct Solution solution = { '1', &k, &n };
	return solution;
}

struct Solution output_2(int a, int b, int c, int d, int e, int f) {
	double y = (a * f - c * e) / (a * d - c * b);
	double x = (d * e - b * f) / (d * a - b * c);

	struct Solution solution = { '2', &x, &y};
	return solution;
}

struct Solution output_3_1(int a, int c, int e, int f) {
	double x;

	if (a == 0)
		x = f / c;
	else if (c == 0)
		x = e / a;
	else if (e == 0 || f == 0)
		x = 0;


	struct Solution solution = { '3', &x, NULL };
	return solution;
}

struct Solution output_3_2(int a, int c, int e, int f) {
	double x;

	if (e == 0)
		x = f / c;
	else if (f == 0)
		x = e / a;
	else
		x = e / a;

	struct Solution solution = { '3', &x, NULL };
	return solution;
}

struct Solution output_4_1( int b, int d, int e, int f) {
	double y;

	if (b == 0)
		y = f / d;
	else if (d == 0)
		y = e / b;
	else if (e == 0 || f == 0)
		y = 0;


	struct Solution solution = { '4', NULL, &y};
	return solution;
}

struct Solution output_4_2(int b, int d, int e, int f) {
	double y;

	if (e == 0)
		y = f / d;
	else if (f == 0)
		y = e / b;
	else
		y = e / b;

	struct Solution solution = { '4', NULL, &y };
	return solution;
}

struct Solution output_5() {
	struct Solution solution = {'5', NULL, NULL};
	return solution;
}

struct Solution input_handler(int a, int b, int c, int d, int e, int f) {

	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		return output_1();
	}
	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		return output_2(a, b, c, d, e, f);
		
	}
	else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) || (a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) || (a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
		 {
			if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) || (c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
			{
				return output_4_1(b, d, e, f);

			}
			else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) || (c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
			{
				return output_3_1(a, c, e, f);
			}
			else
				return output_0();

		 }

	else if (a == 0 && c == 0)
	{
		return output_4_2(b, d, e, f);
	}
	else if (b == 0 && d == 0)
	{
		return output_3_2(a, e, c, f);
	}
	else if (b == 0 && e == 0)
	{
		return output_1(c, d, f);
	}
	else if (d == 0 && f == 0)
	{
		return output_1(a, b, e);
	}
	else if (a == 0 && e == 0)
	{
		return output_1(d, c, f);
	}
	else if (c == 0 && f == 0)
	{
		return output_1(b, a, e);
	}
	else if ((a / b == c / d))
	{
		return output_1(c, d, f);
	}
	else
	{
		cout << "Are you kidding me?";
		struct Solution solution = { '6', NULL, NULL };
		return solution;
	}

	
}

void output_formater(struct Solution sol) {



}

int main()
{
	double a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;
	
	output_formater(input_handler(a, b, c, d, e, f));

	return 0;

}