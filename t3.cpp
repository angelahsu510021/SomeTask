#include<stdio.h>
//嚴謹的三位數反轉
int main()
{
    int n, m;
    scanf("%d", &n);
    m = (n%10)*100 + (n/10%10)*10 + (n/100);
    printf("%03d\n", m);
    return 0;
}