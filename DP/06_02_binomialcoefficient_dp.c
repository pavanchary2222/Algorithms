#include<stdio.h>
int Binomial(int n,int k,int a[n][k])
{
    if(k==0||n==k)
        return a[n][k]=1;
    else
        return a[n][k]=Binomial(n-1,k-1,a)+Binomial(n-1,k,a);
}
int main()
{
    int n,k;
    printf("Enter n value:");
    scanf("%d",&n);
    printf("Enter k value:");
    scanf("%d",&k);
    int a[n][k];
    for (int i = 0; i <=n; i++)
    {
        for(int j=0;j<=k;j++)
            a[i][j]=-1;
    }    
    printf("The value of %dC%d is:%d",n,k,Binomial(n,k,a));
}