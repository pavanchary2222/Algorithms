#include<stdio.h>
#include<math.h>
int a[10][10];
int bc(int n,int k)
{
    if(k<=n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(i==0||i==j)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    }
    return a[n][k];   
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)
            a[i][j]=-1;}
            
    printf("The value is:%d",bc(n,k));
}