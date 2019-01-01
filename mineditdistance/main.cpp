#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;
string fs1,fs2;
    
void printfinals1s2(string s1,string s2,int **arr,int i,int j)
{
    if (i==0 || j ==0)
    {
        //cout << s1 << "\n" << s2;
        if (i==0)
        {
            for (int x=j-1;x>=0;x--)
            {
                fs2.append(s2,x,1);
                fs1.append("_");
            }
        }
        else
        {
            for (int x=i-1;x>=0;x--)
            {
                fs1.append(s1,x,1);
                fs2.append("_");
            }
        }
        reverse(fs1.begin(),fs1.end());
        reverse(fs2.begin(),fs2.end());
        cout << fs1<< endl;
        cout << fs2<< endl;
        fs1.clear();
        fs2.clear();
        return ;
    }
    if (s1[i-1] == s2[j-1])
    {
        fs1.append(s1,i-1,1);
        fs2.append(s2,j-1,1);
        printfinals1s2(s1,s2,arr,i-1,j-1);
    }
    else
    {
    int m = min(min(arr[i-1][j-1],arr[i][j-1]),arr[i-1][j]);
    if (m==arr[i-1][j-1])
    {
        fs1.append(s1,i-1,1);
        fs2.append(s2,j-1,1);
        printfinals1s2(s1,s2,arr,i-1,j-1);
    }
    else if (m==arr[i][j-1])
    {
        fs1.append("_");
        fs2.append(s2,j-1,1);
        printfinals1s2(s1,s2,arr,i,j-1);
    }
    else{
        fs1.append(s1,i-1,1);
        fs2.append("_");
        printfinals1s2(s1,s2,arr,i-1,j);
    }
    }
}


void findeditdistance(string s1,string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **arr = new int*[m+1];
    for (int i=0;i<m+1;i++)
    {
        arr[i] = new int[n+1];
    }
    
    for (int i=0;i<m+1;i++)
    {
        arr[i][0] = i;
    }
    for (int j=0;j<n+1;j++)
    {
        arr[0][j] = j;
    }

    
    for (int i=1;i<m+1;i++)
    {
        for (int j=1;j<n+1;j++)
        {
            if (s1[i-1] == s2[j-1]) 
            {
                arr[i][j] = arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = 1+min(min(arr[i-1][j-1],arr[i-1][j]),arr[i][j-1]);
            }
        }
    }
    
    /*for (int i=0;i<m+1;i++)
    {
        for (int j=0;j<n+1;j++)
        {
            cout << arr[i][j];
        }
        cout << "\n" ;
    }*/

    cout  << arr[m][n] << endl;
    printfinals1s2(s1,s2,arr,m,n);
    
}




int main() {
    int n;
    cin >> n;
    for (int i=0; i<n;i++)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        findeditdistance(s1,s2);
        
    }
    return 0;
}