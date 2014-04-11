#include <iostream>


using namespace std;



int main(void)
{
	unsigned long long  FB1, FB2, tmp;
	int i, n;

	while (cin >> n)
	{
		if (n < 0)
			continue;
		if (n == 0 || n == 1)
			cout << n << endl;
		else
		{
			FB1 = 0;
			FB2 = 1;
			for (i = 2; i <= n; i ++)
			{
				tmp = FB2;
				FB2 = FB1 + FB2;
				FB1 = tmp;
			}
			cout << FB2 << endl;
		}

			
	}
	
	system("pause");
	return 0;
}