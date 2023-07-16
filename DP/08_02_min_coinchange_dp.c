#include<stdio.h>
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
int a[10][10];
int cc(int wt[],int n,int W)
{
    if(n==0)
        return a[n][W]=__INT_MAX__-10;
    if(W==0)
        return a[n][W]=0;
    if(n==1)
    {
        if(W%wt[n-1]==0)
            return a[n][W]=W/wt[n-1];
        else
            return a[n][W]=__INT_MAX__-10;
    }
    if(wt[n-1]<=W)
        return a[n][W]=min(1+cc(wt,n,W-wt[n-1]),cc(wt,n-1,W));
    else
        return a[n][W]=cc(wt,n-1,W);
}
int main()
{
    int wt[]={1,2,3};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=S;j++)
        a[i][j]=-1;
    }
    printf("The min no of ways of picking coins is:%d",cc(wt,n,S));
}