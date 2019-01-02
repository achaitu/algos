#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int array[100000],stack[100000];
int top  = -1;
int c =0,x,N,j;
int temp = 0;
    void push(int x)
    {
        top =  top + 1;
        array[top] = x;
    }

    void jeevan(int c)
    {
        stack[top] = c;
    }
    void delete()
    {
        if(top>-1)
        /*{
            if (c == x){
                c =temp;}
        }*/
        top = top -1;
        c = stack[top];

    }
    void max(int x)
    {
        if(top > -1 ){
            //temp = c;
            if(c < x ){
                c = x;
            }
        }

    }

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int type,i;
    scanf("\n%d",&N);
    for (i=0;i<N;i++)
    {
        scanf("\n%d",&type);
        if (type == 1)
        {
            scanf("\n%d",&x);
            //printf("\nh%d",x);
            push(x);
            max(x);
            jeevan(c);
        }
        else if (type ==2)
        {
            delete();

        }
        else if (type ==3)
        {

            printf("%d\n",c);
        }
        //printf("top is %d\n",top);
//printf("%d\n",c);
    }


    return 0;
}
