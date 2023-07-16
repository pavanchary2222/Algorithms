#include <stdio.h>
float frac_knapsack(float vbw[],float wt[],float val[], int n, float W)
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        if(wt[i]<=W)
        {
            sum=sum+val[i];
            W=W-wt[i];
        }
        else{
            sum=sum+vbw[i]*W;
            break;
        }
    }
    return sum;
}
void swap(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}
void sorting(float vbw[], float wt[], float val[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vbw[j] <vbw[j + 1])
            {
                swap(&vbw[j], &vbw[j + 1]);
                swap(&wt[j], &wt[j + 1]);
                swap(&val[j], &val[j + 1]);
            }
        }
    }
}

int main()
{
    float wt[] = {1,3,5,2};
    float val[] = {5,4,2,3};
    int n = 4;
    float W = 8;
    float vbw[n];
    for(int i=0;i<n;i++){
        vbw[i]=val[i]/wt[i];
    }
    sorting(vbw, wt, val, n);

    printf("The maximum value will be:%.3f",frac_knapsack(vbw,wt,val,n,W));
    
    return 0;
}