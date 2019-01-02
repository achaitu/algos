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

double median(int a[],int n)
{
    if (n%2 == 0){
        return (float)(a[n/2-1]+ a[n/2])/2;
    }
    else return (float)(a[n/2]);
}

double findmedian(int a[],int b[],int n)
{
    if (n==1) return (float)(a[0]+b[0])/ 2;
    else if (n==2) return (float) (max(a[0],b[0])+min(a[1],b[1]))/2;
    else {
    float med1 = median(a,n);
    float med2 = median(b,n);
   // printf("%.1f \t %.1f\n",med1,med2);
    if (med1 == med2) return med1;

    else if (med1 < med2 )
    {
        if (n%2 !=0)
        {
          return  findmedian(a+n/2,b,n/2+1);
        }
        else
        {
           return findmedian(a+n/2-1,b,n/2+1);
        }
    }
    else
    {
        if (n%2 !=0)
        {
           return findmedian(a,b+n/2,n/2+1);
        }
        else
        {
           return  findmedian(a,b+n/2-1,n/2+1);
        }
    }
    }
}


int main() {
    int i,n;
    scanf("%d",&n);
    int a[n],b[n];
    for (i=0;i<n;i++){
     scanf("%d",&a[i]);
        //printf("%d ",a[i]);
    }
    for (i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    double y =findmedian(a,b,n);
    int temp = ceil(y);
    if (temp == (int)y) printf("%d",temp);
    //float y=median(a,n);
    else printf("%.1f",y);

    return 0;
}
