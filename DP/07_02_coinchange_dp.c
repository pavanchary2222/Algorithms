#include<stdio.h>
int a[20][20];
int cc(int wt[],int n,int S)
{
    if(n==0)
        return a[n][S]=0;
    if(S==0)
        return a[n][S]=1;
    if(wt[n-1]<=S)
        return a[n][S]=cc(wt,n,S-wt[n-1])+cc(wt,n-1,S);
    else
        return a[n][S]=cc(wt,n-1,S);
}
int main()
{
    int wt[]={1,2,3};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    for (int i =0; i <=n; i++){
        for (int j =0; j<=S; j++)
            a[i][j]=-1;
    }
    printf("The no of ways of picking coins is:%d",cc(wt,n,S));
}