#include <iostream>
#include <cmath>

using namespace std;



int main(void)
{
	int n;
	
	while (cin >> n)
	{
		if (n < 1)
			continue;
		else
			cout << (long long)pow(2, n - 1) << endl;
	}
	
	system("pause");
	return 0;
}