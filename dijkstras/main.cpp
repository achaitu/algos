#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


priority_queue < pair<int,int>, deque <pair<int,int>>, greater<pair<int,int>> > H;//min-heap

void constructminheap(int s,int n)
{
    H.push(make_pair(0,s));
    for (int i=0;i<n;i++)
    {
        if (i!=s)
        {
            H.push(make_pair(INT_MAX,i));
        }
    }
    
}

int Relax(int u,int v,int w,int shortest[])
{
    if (shortest[u] + w < shortest[v])
    {
        shortest[v] = shortest[u] + w;
        H.push(make_pair(shortest[v],v));
    }
    return shortest[v];
}

void Dijkstrass(int s,int n,vector<pair<int,int>> A[])
{
    constructminheap(s,n);
    int shortest[n];
    fill_n(shortest,n,INT_MAX);
    shortest[s] = 0;
    int visited[n] = {0};
    while(H.size()>=1)
    {
        int u;
        u = H.top().second;
        visited[u] = 1;
        shortest[u] = min(H.top().first, shortest[u]);
        //cout << shortest[u] << " ";
        H.pop();
        for (int i=0;i<A[u].size();i++)
        {
            if(visited[A[u][i].second] != 1)
            {
                shortest[A[u][i].second] = Relax(u,A[u][i].second,A[u][i].first,shortest);
                //cout << A[u][i].second << "-->" << shortest[A[u][i].second] << endl;
            }
        }
    }
//cout << n;
    for(int j = 0; j<n ; j++){
        if(shortest[j] == INT_MAX){
            cout << -1 << " ";
        }else{
            cout << shortest[j] << " ";
        }
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i; i<t;i++)
    {
        int n,m;
        cin >> n;
        cin >> m;
        vector<pair<int,int>> A[n];
        int u,v,w;
        for (int j=0;j<m;j++)
        {
            cin >> u >> v >> w;
            A[u].push_back(make_pair(w,v));
            A[v].push_back(make_pair(w,u));
            
        }
        int s;
        cin >> s;
        Dijkstrass(s,n,A);
      //  cout << a;
    }
    
    
    return 0;
}
