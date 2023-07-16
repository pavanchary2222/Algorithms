#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    char match[100];
    scanf("%s",match);
    int i=0,j=0,count=0;
    while(str[i]!='\0')
    {
        j=0;
        while(str[i]==match[j]){
            i++;
            j++;
            if(match[j]=='\0'){
                count++;
                j=0;
            }
        }
        i++;
    }
    if(count>0)
        printf("Matched %d times",count);
    else
        printf("No match");
}