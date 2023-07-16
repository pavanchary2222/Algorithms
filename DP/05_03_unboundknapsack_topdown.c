#include<stdio.h>
int a[5][10];
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int main()
{
    int n,W;
    int val[]={16,7,8,12};
    int wt[]={5,2,3,4};
    printf("Enter weight of knapsack bag:");
    scanf("%d",&W);
    n=sizeof(val)/sizeof(val[0]);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else if(wt[i-1]<=j)
                a[i][j]=max(val[i-1]+a[i][j-wt[i-1]],a[i-1][j]);
            else
                a[i][j]=a[i-1][j];  
        }
    }
    printf("The max value will be:%d",a[n][W]);

    printf("\n The table representation is:\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            printf("%3d ",a[i][j]);
        printf("\n");
    }
}