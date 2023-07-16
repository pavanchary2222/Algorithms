#include<stdio.h>
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}
int cc(int wt[],int n,int W)
{
    if(n==0)
        return __INT_MAX__-10;
    if(W==0)
        return 0;
    if(n==1)
    {
        if(W%wt[n-1]==0)
            return W/wt[n-1];
        else
            return __INT_MAX__-10;
    }
    if(wt[n-1]<=W)
        return min(1+cc(wt,n,W-wt[n-1]),cc(wt,n-1,W));
    else
        return cc(wt,n-1,W);
}
int main()
{
    int wt[]={1,2,3};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    printf("The min no of ways of picking coins to get sum is:%d",cc(wt,n,S));
}