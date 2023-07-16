#include<stdio.h>
int SS(int wt[],int n,int sum)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    if(wt[n-1]<=sum)
        return SS(wt,n-1,sum-wt[n-1]) || SS(wt,n-1,sum);
    else 
        return SS(wt,n-1,sum);
}
int main()
{
    int n,W;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int wt[n];
    printf("Enter weights into array:");
    for(int i=0;i<n;i++)
        scanf("%d",&wt[i]);
    printf("Enter Weight:");
    scanf("%d",&W);
    
    if(SS(wt,n,W))
        printf("The sum can be made :)");
    else
        printf("Sorry:(");

}