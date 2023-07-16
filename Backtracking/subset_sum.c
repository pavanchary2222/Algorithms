#include<stdio.h>
#include<stdlib.h>
void printn(int x[],int wt[],int n)
{
    for(int i=0;i<n;i++){
        if(x[i]==1)
            printf("%d ",wt[i]);
        else
            printf("0 ");
    }
    printf("\n");
    return;
}
void SS(int wt[],int x[],int W,int n,int rsum,int len)
{
    if(W==0){
        printn(x,wt,len);
        return;
    }
    if(n==0 || rsum<W)
        return;
    if(wt[n-1]<=W)
    
    {
        x[n-1]=1;
        SS(wt,x,W-wt[n-1],n-1,rsum-wt[n-1],len);
    }
    x[n-1]=0;
    SS(wt,x,W,n-1,rsum-wt[n-1],len);
}
int main()
{
    int n,W,rsum;
    printf("Enter array Size:");
    scanf("%d",&n);
    int wt[n],x[n],len=n;
    printf("Enter the array weights:");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
        x[i]=0;
        rsum+=wt[i];
    }
    printf("enter Weight:");
    scanf("%d",&W);
    printf("The weights are:\n");
    SS(wt,x,W,n,rsum,len);
}