#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100006

bool valid = true;


int StrToInt(char *str)
{
	valid = true;
	if (str == NULL || *str == '\0')
	{
		valid = false;
		return 0;
	}
	int num = 0, i;
	bool minus = false;
	if (*str == '-')
	{
		minus = true;
		str ++;
	}
	if (*str == '+')
		str ++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (str[i] - '0');
			//±ß½çÖµÅÐ¶Ï
			if ((!minus && num > 0x7fffffff) || (minus && num < 0x80000000))
			{
				valid = false;
				num = 0;
				break;
			}
		}
		else
		{
			valid = false;
			num = 0;
			break;
		}

	}
	return num;

}



int main(void)
{
	char str[MAX];
	while (scanf("%s", str) != EOF)
	{
		int num = StrToInt(str);
		if (valid)
			printf("%d\n", num);
		else
			printf("My God\n");
	}


	system("pause");
	return 0;
}

