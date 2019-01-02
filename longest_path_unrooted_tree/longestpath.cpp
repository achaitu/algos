#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


void getmaxheight(int *height,int n,int *pos,int *maxxheight)
{
    for (int i = 0; i < n; i++) 
    {
        if (height[i] > *maxxheight) 
        { 
            *pos = i;
            *maxxheight = height[i];   
        }
    }
    //cout << *pos << *maxxheight << endl;
}

void dobfsandgivemaxheight(vector<int> A[],int n,int x,int *pos,int *maxxheight)
{
    queue<int> bfsq;
    bfsq.push(x); 
    int height[n];
    fill_n(height,n,-1);
    height[x] = 0;
    int visited[n] = {0};
    while (bfsq.empty()==false) 
    { 
        int node;
        node = bfsq.front();
        //cout << "got node : "<< node<<endl;
        visited[node] = 1;
        bfsq.pop();
        for (int i = 0;i<A[node].size();i++) 
        {
            if(visited[A[node][i]] != 1)
            {
                //cout << "Push : "<< A[node][i] <<endl;
                bfsq.push(A[node][i]);  
                height[A[node][i]] = height[node] + 1; 
            } 
        } 
    } 
    getmaxheight(height,n,pos,maxxheight);
    //cout << *pos << *maxxheight << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i; i<t;i++)
    {
        int n;
        cin >> n;
        vector<int> A[n];
        int u,v;
        for (int j=0;j<n-1;j++)
        {
            cin >> u >> v;
            A[u].push_back(v);
            A[v].push_back(u);  
        }
        int firstleaf=0,h1=0,secondleaf=0,h2=0;
        int z = 0;
        dobfsandgivemaxheight(A,n,z,&firstleaf,&h1);
        //cout << firstleaf << h1 << endl;
        dobfsandgivemaxheight(A,n,firstleaf,&secondleaf,&h2);
        cout << h2 << endl;        
    }
    return 0;
}
