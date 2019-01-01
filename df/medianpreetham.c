..preetam
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double median(int a[],int s,int e)
{
//printf( "%f %d",s,e);
    if ((s+e)%2 != 0){
        
        
        return (float)(a[(s+e)/2]+ a[(s+e)/2+1])/2;
    }
    else return (float)a[(s+e)/2];
}

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
double findmedian(int a[],int b[],int s, int e,int s1, int e1)
    {
    
    
    if (s+e==0) return (a[0]+b[0] / 2);
    if(e-s==1)
    {
        return(float)(max(a[s],b[s1])+min(a[e],b[e1]))/2;
    }
   // printf("%d %d ",s,e);
    double med1 = median(a,s,e);
    double med2 = median(b,s1,e1);
    printf("%f\t %f\n",med1,med2);
    if (med1 == med2) return med1; 
    else if (med1 < med2 )
    {
       findmedian(a,b,(s+e+1)/2,e,s1,(s1+e1)/2); 
    }
    else
    {
        findmedian(a,b,s,(s+e)/2,(s1+e1+1)/2,e1);
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
    
    double y =findmedian(a,b,0,n-1,0,n-1);
    //float y=median(a,n);
    printf("%f",y);
    
    //return 0;
}
