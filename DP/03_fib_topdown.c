#include<stdio.h>
int main()
{
    int n;
    printf("Enter the nth number:");
    scanf("%d",&n);
    int a[n];
    a[0]=1;
    a[1]=1;

    for(int i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];

    printf("the nth febonacci number is %d",a[n]);
}