#include<stdio.h>
#include<math.h>
int febonacci(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return febonacci(n-1)+febonacci(n-2);
}
int main()
{
    int num;
    printf("enter the number:");
    scanf("%d",&num);
    for(int j=0;j<num;j++)
        printf("%d ",febonacci(j));
}