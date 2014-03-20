#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replace_black(char strs[], int length)
{
	int i, j, count = 0, original_length = 0;

	if (strs == NULL || length <= 0)
		return ;

	
	for (i = 0; strs[i] != '\0'; i ++)
	{
		original_length ++;
		if (strs[i] == ' ')
			count ++;
	}
	//cout << length << endl;

	int newlength = count * 2 + original_length;
	if (newlength > length)
		return ;


	i = original_length - 1;
	j = newlength - 1;
	strs[newlength] = '\0';
	while (i <= j && i >= 0)
	{
		if (strs[i] == ' ')
		{
			strs[j --] = '0';
			strs[j --] = '2';
			strs[j --] = '%';
		}
		else
			strs[j --] = strs[i];
		i --;
	}
	cout << strs << endl;
	return;
}


int main(void)
{
	const size_t array_size = 1000;
	char strs[array_size];
	//gets_s(strs, array_size - 1);
	int i = 0;
	char tmp;
	tmp = cin.get();
	while(tmp != '\n')
	{
		strs[i] = tmp;
		tmp = cin.get();
		i ++;
	}
	strs[i] = '\0';
	replace_black(strs, array_size);

	system("pause");
	return 0;
}