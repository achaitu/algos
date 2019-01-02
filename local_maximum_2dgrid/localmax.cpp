#include <stdio.h>
#include <stdlib.h>

int findmax(int *arr,int size)
    {
        int i,index=0;
        for (i=0;i<size;i++)
        {
            if (arr[i] > arr[index]) index = i;
        }
        //printf("\nindex%d",index);
        return index;
    }


int findpeak(int **a,int r,int c, int low,int high)
{
    //int a[r][c];
    int b[r],i,j;
    // for (i=0;i<r;i++){
    //     for (j=0;j<c;j++)
    //         {
    //             a[i][j] = arr[i][j];
    //         }
    //     }
    int mid = low + (high-low)/2;
    for (i=0;i<r;i++)
    {
        b[i] = a[i][mid];
    }
    int maxindex = findmax(b,r);
    //printf("\nmaxis %d, maxleft is%d,maxright is %d,midleft is %d",a[maxindex][mid],a[maxindex][mid-1],a[maxindex][mid+1],mid-1);
    if (mid == 0 || mid  == c) return a[maxindex][mid];
    if(low == high )
    {
        //printf("\nlow is high");
        return a[maxindex][low];
    }

    //if (c/2==1 && a[maxindex][c/2] > a[maxindex-1][c/2] ) return a[maxindex][c/2];
    //if (c/2==1 && a[maxindex][c/2] < a[maxindex-1][c/2] ) return findpeak()


    if (a[maxindex][mid] > a[maxindex][mid-1] && a[maxindex][mid] > a[maxindex][mid+1])
    {

        //printf("\npeak occured");
        return a[maxindex][mid];
    }
    else if (a[maxindex][mid] < a[maxindex][mid+1] )
    {

        //printf("\nim going right");
        return findpeak(a,r,c,mid+1,high);
    }
    else {
            //printf("\nim going left");
            return findpeak(a,r,c,low,mid-1);
    }

}


int main()
{
    int r,c,i,j;
    scanf("%d %d",&r,&c);
    int **a = new int*[r];
    for(int k=0;k<r;k++)
    {
        a[k]=new int[c];
    }
    //printf("%d %d\n",r,c);
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            //printf("%d ",a[i][j]);
        }
    }
    int ans  =  findpeak(a,r,c,0,c-1);
    printf("%d",ans);
    return 0;
}
