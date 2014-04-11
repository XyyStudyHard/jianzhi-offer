#include <stdlib.h>
#include <stdio.h>
 
#define MAX  1000001
 
int MinInOrder(int *numbers, int index1, int index2)
{
    int i, result;
    result = numbers[index1];
    for (i = index1 + 1; i <= index2; i ++)
    {
        if (result > numbers[i])
            result = numbers[i];
    }
    return result;
}
 
int Min(int *numbers, int length, int *min_num)
{
    int index1, index2, indexMid;
    if (numbers == NULL || length <= 0)
        return -1;
    index1 = 0;
    index2 = length - 1;
    indexMid = index1;
    while (numbers[index1] >= numbers[index2])
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[indexMid] && numbers[index2] == numbers[indexMid])
        {
            *min_num = MinInOrder(numbers, index1, index2);
            return 0;
        }
        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
    }
    *min_num = numbers[indexMid];
    return 0;
}
 
int main(void)
{
    int numbers[MAX];
    int n, tmp, len, min_num;
    while(scanf("%d", &n) != EOF)
    {
        len = 0;
        while (len < n)
        {
            scanf("%d", &tmp);
            numbers[len] = tmp;
            len ++;
        }
        tmp = Min(numbers, n, &min_num);
        if (tmp == -1)
            continue;
        else
            printf("%d\n", min_num);
    }
 
    return 0;
}