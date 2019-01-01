#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

findspecial(int a[],int low, int high)
{
    if (high - low < 5)
     {  int 
            return low;
	int n = (low+high+1);
	int row = ceil((float)n/5);
    //printf("%dh\n",row);
        int array5[row][5];
	int sorted[row][5];
	int i,j,B[row];
	for (i=0;i<row;i++){
		for (j=0;j<5;j++){
		if (5*i+j < n)
		array5[i][j] = a[(5*i+j)];
		//printf ("%d ",array5[i][j]);
		}
		//printf("%dh ",sizeof(array5[i])/sizeof(int));
		if(i==row-1)
            quick_sort(array5[i],0,n%5-1);
        else
		quick_sort(array5[i],0,4);
         B[i]=array5[i][2];
		}
		//quick_sort(B,0,row);
		return findithsmallest(B,0,row,ith);
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
int findithsmallest(int a[],int low,int high, int i)
{
	int x = findspecial(a, low,high);
	//int k = partition(int a,low,high,x);
	//if (i==k) return a[i];
	//else if (i<=k-1) return findithsmallest(a,low,k-1,i);
	//else return findithsmallest(a,k+1,help,i-k);
}

int main() {
    int i,j,n;
    scanf("%d\n",&n);
    int a[n];
    for (j=0;j<n;j++){
     scanf("%d ",&a[j]);
        //printf("%d ",a[i]);
    }
    scanf("\n%d",&i);
    findithsmallest(a,0,n-1,i);
    return 0;
}

