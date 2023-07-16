#include<stdio.h>
int cc(int wt[],int n,int S)
{
    if(n==0)
        return 0;
    if(S==0)
        return 1;
    if(wt[n-1]<=S)
        return cc(wt,n,S-wt[n-1])+cc(wt,n-1,S);
    else
        return cc(wt,n-1,S);
}
int main()
{
    int wt[]={5,2,3,4};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    printf("The no of ways of picking coins is:%d",cc(wt,n,S));
}