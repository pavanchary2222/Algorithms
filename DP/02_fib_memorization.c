#include<stdio.h>
#include<math.h>
int feb(int n,int a[])
{
    if(n==0||n==1){
        return a[n]=1;
    }
    if(a[n]!=-1)
        return a[n];
    else{
        return a[n]=(feb(n-2,a)+feb(n-1,a));
    }
}
int main()
{
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=-1;
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    //for(int j=0;j<num;j++)
        printf("%d",feb(num,a));
}