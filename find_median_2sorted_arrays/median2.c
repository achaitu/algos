#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a,int b)
{
     if(a>b)
     return a;
     else
     return b;
}

int min(int a,int b)
{
     if(a<b)
     return a;
     else
     return b;
}

double median(int *a,int n)
{
    if (n%2 == 0){
        return ((float)(a[n/2 - 1]+ a[n/2])/2);
    }
    else return (float)a[n/2];
}


double findmedian(int *a,int *b,int n)
{
    if (n==0) return -1;
    if (n==1) return (a[0]+b[0] / 2);
    if (n==2) return (float)(max(a[0],b[0])+min(a[1],b[1]))/2;
    double med1 = median(a,n);
    double med2 = median(b,n);
    //printf("%.1f \t %.1f",med1,med2);
    if (med1 == med2) return med1; 

    if (med1 < med2 )
    {
        if (n%2 !=0)
        {
            int x[n/2+1],y[n/2+1],p;
            for (p=0;p<n/2+1;p++)
                {
                x[p]= a[n/2+p];
                y[p] = b[p];
                }
            findmedian(x,y,n/2+1);
        }
        else
        {
            int x[n/2],y[n/2],p;
            for (p=0;p<n/2;p++)
                {
                x[p]= a[n/2+p];
                y[p] = b[p];
                }
            
            findmedian(x,y,n/2);
        }
    }
    if (med1 > med2 )
    {
        if (n%2 !=0)
        {
            int x[n/2+1],y[n/2+1],p;
            for (p=0;p<n/2+1;p++)
                {
                x[p]= a[p];
                y[p] = b[n/2+p];
                }
            findmedian(x,y,n/2+1);
        }
        else
        {
            int x[n/2],y[n/2],p;
            for (p=0;p<n/2;p++)
                {
                x[p]= a[p];
                y[p] = b[n/2+p];
                }
            
             findmedian(x,y,n/2);
        }
    }
        
}


int main() {
    int i,n;
    scanf("%d\n",&n);
    int a[n],b[n];
    for (i=0;i<n;i++){
     scanf("%d ",&a[i]);
        //printf("%d ",a[i]);
    }
    for (i=0;i<n;i++){
        scanf("%d ",&b[i]);
    }
    double y =findmedian(a,b,n);
    //float y=median(a,n);
    printf("%.1f",y);
    
    //return 0;
}
