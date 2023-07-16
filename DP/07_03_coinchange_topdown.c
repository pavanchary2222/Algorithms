#include<stdio.h>
int a[20][20];
int cc(int wt[],int n,int S)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=S;j++)
        {
            if(i==0)
                a[i][j]=0;
            else if(j==0)
                a[i][j]=1;
            else if(wt[i-1]<=j)
                a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];
            else
                a[i][j]=a[i-1][j];
        }
    }
    return a[n][S];
}
int main()
{
    int wt[]={1,2,3,4};
    int S,n;
    n=sizeof(wt)/sizeof(wt[0]);
    printf("Enter the sum/weight:");
    scanf("%d",&S);
    printf("The no of ways of picking coins is:%d",cc(wt,n,S));

    printf("\n The table representation is:\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=S;j++)
            printf("%3d ",a[i][j]);
        printf("\n");
    }
}