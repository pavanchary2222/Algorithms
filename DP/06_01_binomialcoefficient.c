#include<stdio.h>
int Binomial(int n,int k)
{
    if(k==0||n==k)
        return 1;
    else
        return Binomial(n-1,k-1)+Binomial(n-1,k);
}
int main()
{
    int n,k;
    printf("Enter n value:");
    scanf("%d",&n);
    printf("Enter k value:");
    scanf("%d",&k);
    printf("The value of %dC%d is:%d",n,k,Binomial(n,k));
}