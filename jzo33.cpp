#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 101
#define MAX_NUM 10

char str_combine1[2 * MAX_NUM], str_combine2[2 * MAX_NUM];

int Compare(const void* str1, const void* str2)
{
	strcpy(str_combine1, *(const char**)str1);
	strcat(str_combine1, *(const char**)str2);

	strcpy(str_combine2, *(const char**)str2);
	strcat(str_combine2, *(const char**)str1);

	return strcmp(str_combine1, str_combine2);
}


int PrintMinNumberOfArray(int *num, int length)
{
	if (num == NULL || length <= 0)
		return 0;
	char *str_num[MAX];
	
	for (int i = 0;i < length; i++)
	{
		str_num[i] = new char[MAX_NUM];
		sprintf(str_num[i], "%d", num[i]);
	}

	//Ê¹ÓÃ¿âº¯Êýqsort()
	qsort(str_num, length, sizeof(char *), Compare);

	for (int i = 0; i < length; i++)
		printf("%s", str_num[i]);
	printf("\n");

	for (int i = 0;i < length; i++)
		delete[] str_num[i];
	return 0;
}



int main(void)
{
	int str[MAX], n;

	while (cin >> n)
	{
		for(int i = 0;i < n; i++)
			scanf("%d", &str[i]);
		PrintMinNumberOfArray(str, n);
	}

	system("pause");
	return 0;
}

