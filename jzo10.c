#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main(void)
{
    int n, num, count;
     
    scanf("%d", &n);
    while (n --)
    {
        count = 0;
        scanf("%d", &num);
        while(num)
        {
            num  = (num - 1) & num;
            count ++;
        }
        printf("%d\n", count);
    }
 
    return 0;
}