#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAX 50005

void Reverse(char *start, char *end)
{
	char tmp;
	if (start == NULL || end == NULL)
		return ;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start ++;
		end --;
	}

}

char *ReverseSentence(char *str)
{
	if (str == NULL)
		return NULL;
	char *start, *end;
	start = end = str;
	while(*end != '\0')
		end ++;
	end --;
	Reverse(start, end);
	
	start = end = str;
	while (*start != '\0')
	{
		if (*start == ' ')
		{
			start ++;
			end ++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			Reverse(start, --end);
			start = (++end);
		}
		else
			end ++;
	}
	puts(str);
	return str;
}

int main(void)
{
	char str[MAX];
	while (gets(str) != NULL)
	{
		ReverseSentence(str);
	}


	system("pause");
	return 0;
}

