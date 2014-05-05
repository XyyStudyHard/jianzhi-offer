#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 10002

int FirstNotRepeatChar(char *str)
{
	if (str == NULL)
		return -1;
	const int table_size = 256;
	unsigned int hash_table[table_size];
	for (int i = 0; i < table_size; i ++)
		hash_table[i] = 0;
	char *index = str;
	while(*index != '\0')
	{
		hash_table[*index] ++;
		index ++;
	}
	for (int i = 0;i < strlen(str); i ++)
	{
		if (hash_table[str[i]] == 1)
			return i;
	}
	
	return -1;
}

int main(void)
{
	char str[MAX];
	while (cin >> str)
	{
		int first_one;
		first_one = FirstNotRepeatChar(str);
		cout << first_one << endl;
	}


	system("pause");
	return 0;
}

