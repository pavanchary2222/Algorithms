#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
    int x,y;
};
float distance(struct point p1,struct point p2)
{
    return sqrt(pow(p1.y-p2.y,2)+pow(p1.x-p2.x,2));
}

int brutforceapproach(struct point p[],int n)
{
    struct point P,Q;
    int min=__INT_MAX__;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(distance(p[i],p[j])<min)
            {
                min=distance(p[i],p[j]);
                P=p[i];
                Q=p[j];
            }
        }
    }
    printf("the closest pair is: (%d,%d)::(%d,%d) and the distance is:%d",P.x,P.y,Q.x,Q.y,min);
}
int main()
{
    struct point p[]={{2,4},{4,5},{5,6},{6,7},{8,9},{4,4},{3,3}};
    int size=sizeof(p)/sizeof(p[0]);
    printf("finding the closeset pair:",brutforceapproach(p,size));
}   