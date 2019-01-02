#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> iPair;
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<iPair >  adj[], int V, int src)
{

    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V,INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0; i < V; ++i)
        printf("%d ",dist[i]);
}
int main()
{
    int iter;
    cin >> iter;
    for(int i = 0;i<iter;i++){
    int m,n,sou;
    cin>>m >> n;
    //cin>>n;
    int V = m;
    vector<iPair > adj[V];
    for(int j=0;j<n;j++){
    int temp1,temp2,temp3;
    cin>>temp1;
    cin>>temp2;
    cin>>temp3;
    addEdge(adj, temp1, temp2, temp3);
    }
    cin >> sou;
    shortestPath(adj, V, sou);
    printf("\n");
    }

    return 0;
}
