#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tim=0;
void dfs(int x,int n,vector<int> A[],int* discovery,int* low,int* parent,int* visited,int* cutvertex)
{
    visited[x] = 1;
    int children = 0;
    discovery[x] = ++tim;
    low[x] = ++tim;
            
    for (int i=0;i<A[x].size();i++)
    {
        if (visited[A[x][i]] ==0)
        {
            //cout <<x << "-->" << A[x][i] << endl;
            children++;
            //visited[A[x][i]] =1;
            parent[A[x][i]] = x;
            dfs(A[x][i],n,A,discovery,low,parent,visited,cutvertex);
            low[x]  = min(low[x], low[A[x][i]]);
            if (parent[x] == -1 && children > 1) 
               cutvertex[x] = 1; 
            if (parent[x] != -1 && low[A[x][i]] >= discovery[x]) 
               cutvertex[x] = 1; 
        }
        else if (A[x][i] != parent[x]) 
            low[x]  = min(low[x], discovery[A[x][i]]); 
    }
    
    
    
}

int totalnoofbiconnectedcomp(vector<int> A[],int n)
{
    int discovery[n];
    int low[n];
    int parent[n];
    int visited[n];
    int cutvertex[n];
    fill_n(discovery,n,0);
    fill_n(cutvertex,n,0);
    fill_n(parent,n,-1);
    fill_n(visited,n,0);
    dfs(0,n,A,discovery,low,parent,visited,cutvertex);
    int count= 0;
    for (int i =0;i<n;i++)
    {
        if (cutvertex[i] == 1)
        count+=1;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i; i<t;i++)
    {
        int n,m;
        cin >> n >> m;
        vector<int> A[n];
        int u,v;
        for (int j=0;j<m;j++)
        {
            cin >> u >> v;
            A[u].push_back(v);
            A[v].push_back(u);  
        }
        int num =  totalnoofbiconnectedcomp(A,n);
        cout << num+1 << endl;
    }
    return 0;
}
