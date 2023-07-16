#include<stdio.h>
int a[10][10];
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

int cc(int wt[],int n,int W)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0)
                a[i][j]=__INT_MAX__-10;
            else if(j==0)
                a[i][j]=0;
            else if(i==1)
            {
                if(j%wt[i-1]==0)
                    a[i][j]=j/wt[i-1];
                else
                    a[i][j]=__INT_MAX__-10;
            }
            else if(wt[i-1]<=j)
                a[i][j]=min(1+a[i][j-wt[i-1]],a[i-1][j]);
            else
                a[i][j]=a[i-1][j];
        }
    }
    return a[n][W];
}
int main()
{
    int wt[]={1,2,3};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    printf("The min no of ways of picking coins is:%d",cc(wt,n,S));
    printf("\n The table representation is:\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=S;j++){
            if(a[i][j]==__INT_MAX__-10)
                printf("%7s ","inf");
            else
                printf("%7d ",a[i][j]);
        }
        printf("\n");
    }
}