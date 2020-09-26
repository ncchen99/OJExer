#include <stdio.h>
int main() 
{
    int i,n;
    long long int a[101];

    a[1] = 1;
    a[2] = 2;

    for(i=3;i<=100;i++)
        a[i] = a[i-1] + a[i-2];

    while(scanf("%d",&n)==1)
        printf("%lld\n",a[n]);

    return 0;
}
