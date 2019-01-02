#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = 0,j;
    for (j = 0; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            //swap(&arr[i], &arr[j]);
            i++;
        }
    }
    int temp2 = arr[i];
    arr[i] = arr[r];
    arr[r] = temp2;
    //swap(&arr[i], &arr[r]);
    return i;
}

int findithsmallest(int a[],int low,int high, int k)
{
    if (k>0 && k <= high-low+1){
    //int x = findspecial(a, low,high);
    int i = partition(a,low,high);
    //printf("%d\t",i+1);
    if (i+1==k) return a[i];
    else if (k<i+1) return findithsmallest(a,low,i-1,k);
    else return findithsmallest(a+i+1,low,high-i-1,k-(i+1));
    }
    return 0;
}

int main() {
    int i,j,n;
    scanf("%d\n",&n);
    int a[n];
    for (j=0;j<n;j++){
     scanf("%d ",&a[j]);
        //printf("%d ",a[i]);
    }
    //scanf("\n%d",&i);
    scanf("\n%d",&i);
    int y = findithsmallest(a,0,n-1,i);
    printf("%d",y);

    return 0;
}

//7
//5 4 6 7 2 9 3

15 15
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
10 14 5 8 9 10 14 5 8 9 10 14 5 8 9
29 23 8 9 27 29 23 8 9 27 29 23 8 9 27
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
25 20 19 18 17 25 20 19 18 17 25 20 19 18 17
29 23 8 9 27 29 23 8 9 27 29 23 8 9 27
3 6 9 7 41 3 6 9 7 41 3 6 9 7 41
2 48 9 37 2 2 48 9 37 02 2 48 9 37 02
39 78 91 54 36 39 78 91 54 36 39 78 91 54 36
35 81 64 92 73 35 81 64 92 73 34 81 64 92 73
6 4 7 3 8 9 6 4 7 3 8 9 6 4 7
12 8 92 37 02 12 8 92 37 02 12 8 92 37 02
25 20 19 18 17 25 20 19 18 17 25 20 19 18 17

