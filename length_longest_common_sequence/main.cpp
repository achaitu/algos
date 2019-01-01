#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int findmax(int *a,int n)
{
    int Max = a[0];
    for (int i=0;i<n;i++)
    {
        if (Max  < a[i])
        {
            Max = a[i];
        }
    }
    return Max;
}


void findlcs(int *arr,int n)
{
    int *lcsuptoi = new int[n];
    for (int i=0;i<n;i++)
    {
        lcsuptoi[i] = 1;
    }

    for (int i=0;i<n;i++)
    {
        int tempmax = 1;
        for (int j=0;j<i;j++)
            {
                if (arr[i] > arr[j])
                {
                    tempmax = max(tempmax,lcsuptoi[j]+1);
                }
            }
        lcsuptoi[i] = tempmax;
    }


    cout << findmax(lcsuptoi,n) << endl;

}


int main() {
    int q;
    cin >> q;
    for (int i; i<q;i++)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int j=0;j<n;j++)
        {
            cin >> arr[j];
        }
        findlcs(arr,n);
    }
    return 0;
}
