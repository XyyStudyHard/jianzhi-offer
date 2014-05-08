#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 1002

void Reverse(char *start, char *end)
{
	if (start == NULL || end == NULL)
			return ;
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start ++;
		end --;
	}
}


void LeftRotateString(char *str, int n)
{
	if (str == NULL || n < 0)
		return;
	char *start1, *end1, *start2, *end2;
	int length = strlen(str);
	n = n % length;
	start1 = str;
	end1= str + n - 1;
	start2 = str + n;
	end2 = str + length - 1;
	
	Reverse(start1, end1);
	Reverse(start2, end2);
	Reverse(start1, end2);
	printf("%s\n", str);
}


int main(void)
{
	char str[MAX];
	int n;
	while (scanf("%s", str) != EOF)
	{
		scanf("%d", &n);
		LeftRotateString(str, n);
	}


	system("pause");
	return 0;
}

