
#include <stdio.h>

int main()
{
   // printf("Hello World");
    char a[] = "string";
    int b[6] = {0};
    int i;
    int len = strlen(a);
    for (i=0;i<len;i++)
    {//printf("%c %c ",a[0],a[i]);
    if (a[i] <= a[0])
    {
        b[i] = 1;
    }
    else
    {
        b[i] = 0;
    }
    }
    int sum=0;
    for (i=0;i<len;i++)
    {   //printf("%d ",b[i]);
        if (b[i] == 1)
        {
            sum+= (len-i);
        }
    }
    printf("%d",sum);
        
    
    
    
    return 0;
}
