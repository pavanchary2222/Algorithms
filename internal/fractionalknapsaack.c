#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int fracks(int wt[],int val[],int n,int W)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(wt[i]<=W)
        {
            sum=sum+val[i];
            W=W-wt[i];
        }
        else
        {
            sum=sum+W*(val[i]/wt[i]);
        }
    }
    return sum;
}
void sort(int wt[],int val[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((val[j]/wt[j])>(val[j+1]/wt[j+1])){
                swap(&wt[j],&wt[j+1]);
                swap(&val[j],&val[j+1]);
            }
        }
    }
}
int main()
{
    int wt[]={1,2,3};
    int val[]={2,5,6};
    int n=3;
    int W;
    printf("Enter weight of knapsack bag:");
    scanf("%d",&W);
    sort(wt,val,n);
    printf("The max val would be:%d\n",fracks(wt,val,n,W));
}