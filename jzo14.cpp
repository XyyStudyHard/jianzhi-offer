#include <iostream>
#include <vector>


using namespace std;

bool isEven(int n)
{
	return (n & 0x1) == 0;
}

void AdjustArray(vector<int> &arr, bool (*func)(int))
{
	int tmp;
	if (arr.empty())
		return ;
	vector<int>::iterator iterbeg = arr.begin(), iterend = arr.end() - 1;
	while (iterbeg < iterend)
	{
		while (iterbeg < iterend && !func(*iterbeg))
			iterbeg ++;
		while (iterbeg < iterend && func(*iterend))
			iterend --;
		if (iterbeg < iterend)
		{
			tmp = *iterbeg;
			*iterbeg = *iterend;
			*iterend = tmp;
		}
	}

	return ;
}


int main()
{
	int n, tmp;
	vector<int> arr;
	cin >> n;
	int i = n;
	while (n --)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	AdjustArray(arr, isEven);
	
	for (int j = 0; j < i; j ++)
		cout << arr[j] << " ";

	system("pause");
    return 0;
}