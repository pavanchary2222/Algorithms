#include<stdio.h>
int a[10][10];
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int ks(int wt[],int val[],int W,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else if(wt[i-1]<=j)
                a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
            else
                a[i][j]=a[i-1][j];  
        }
    }
    return a[n][W];
}
int main()
{
    int n,W;
    int val[]={8,12,16,17};//7,8,12,16
    int wt[]={3,4,5,2};//2,3,4,5
    printf("Enter weight of knapsack bag:");
    scanf("%d",&W);
    n=sizeof(val)/sizeof(val[0]);
    printf("The max value will be:%d",ks(wt,val,W,n));
    printf("\n The table representation is:\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            printf("%3d ",a[i][j]);
        printf("\n");
    }
    /*
           
  0   0   0   0   0   0   0   0   0 
  0   0   0   0   0  16  16  16  16 
  0   0   7   7   7  16  16  23  23 
  0   0   7   8   8  16  16  23  24 
  0   0   7   8  12  16  19  23  24  
*/

}