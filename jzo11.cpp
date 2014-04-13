#include <iostream>
#include <iomanip>

using namespace std;

bool g_InvalidInput = false;

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent(double base, unsigned int absexponent)
{
	double result = 1.0;
	/* this solution is not good enough. O(n)
	int i = 0;
	for (i = 0; i < absexponent; i ++)
		result = result * base;
	return result;
	*/

	// O(lgn)
	if (absexponent == 0)
		return 1;
	if (absexponent == 1)
		return base;
	result = PowerWithUnsignedExponent(base, absexponent >> 1);
	result *= result;
	if ((absexponent & 0x1) == 1)
		result = base * result;
	return result;
}

double Power(double base, int exponent)
{
	double result;
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent;
	absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

int main()
{
	int T, exponent;
	double base, result;
	cin >> T;
	while (T--)
	{
		cin >> base;
		cin >> exponent;
		result = Power(base, exponent);
		if (g_InvalidInput == 1)
			cout << "INF" << endl;
		else
		{
			//g++ doesn't use this format, there is two digits of the exponent. 
			// while in VS, there is 3, so we have to set this.
			// according to the requests, exponent have to be two digits
			unsigned int format = _set_output_format(_TWO_DIGIT_EXPONENT);
			//printf("%.2e\n", result);
			cout << setiosflags(ios::scientific) << setprecision(2) << result << "f" << endl;
		}
	}

	system("pause");
    return 0;
}