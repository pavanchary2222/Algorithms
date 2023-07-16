#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int ks(int val[],int wt[],int n,int W)
{
    if(n==0||W==0)
        return 0;
    if(wt[n-1]<=W)
        return max(val[n-1]+ks(val,wt,n,W-wt[n-1]),ks(val,wt,n-1,W));
    else
        return ks(val,wt,n-1,W);
}
int main()
{
    int val[]={16,7,8,12};
    int wt[]={5,2,3,4};
    int W,n;
    printf("Enter the weight of knapsack bag:");
    scanf("%d",&W);
    n=sizeof(wt)/sizeof(wt[0]);
    printf("The max value will be:%d",ks(val,wt,n,W));
}