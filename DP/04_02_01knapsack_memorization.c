#include<stdio.h>
#include<math.h>
int a[5][10];
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int ks(int val[],int wt[],int n,int W)
{
    if(n==0||W==0)
        return a[n][W]=0;
    if(a[n][W]!=-1)
        return a[n][W];
    if(wt[n-1]<=W)
        return a[n][W]=max(val[n-1]+ks(val,wt,n-1,W-wt[n-1]),ks(val,wt,n-1,W));
    else
        return a[n][W]=ks(val,wt,n-1,W);
}
int main()
{
    int val[]={16,7,8,12};
    int wt[]={5,2,3,4};
    int W,n;
    printf("Enter the weight of knapsack bag:");
    scanf("%d",&W);
    n=sizeof(wt)/sizeof(wt[0]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            a[i][j]=-1;}
    printf("The max value will be:%d\n",ks(val,wt,n,W));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}