#include <bits/stdc++.h> 
using namespace std; 

struct edge{
    int a, b, w; 
}; 

void BellmanFord(){
    int x; 
    int n; 
    const int inf = 1e18; 
    vector<edge> edges; 
    vector<int> dis(n, inf); 

    dis[x] = 0; 
    for(int i=0; i<n-1; i++){
        int done = 0; 
        for(auto e: edges){
            if(dis[e.a] + e.w < dis[e.b]){
                dis[e.b] = dis[e.a] + e.w;
                done = 1; 
            }
        }
        if(!done) break; 
    }
}

// SPFA
void spfa(int k, vector<vector<pair<int, int>>> adj){
    int n; 
    const int inf = 1e18; 
    vector<int> dis(n, inf); 
    vector<int> cnt(n, 0); 
    vector<bool> inqueue(n, 0); 
    queue<int> q; 

    q.push(k); 
    inqueue[k] = 1; 
    dis[k] = 0; 
    // you update cnt every time you relax a vertex 

    while(!q.empty()){ 
        int f = q.front(); 
        q.pop(); 
        inqueue[k] = 0; 

        for(auto [x, y]: adj[f]){
            if(dis[f] + y < dis[x]){
                dis[x] = dis[f] + y; 
                if(!inqueue[x]){
                    cnt[x]++; 
                    q.push(x); 
                    inqueue[x] = 1; 
                    if(cnt[x] == n); // it exists a negative cycle
                }
            }
        }
    }
}

// FLOYD-WARSHALL
void fw(){
    int n; 
    const int inf = 1e18; 
    vector<vector<int>> dis;
    vector<vector<int>> adj;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) dis[i][j] = 0; 
            if(adj[i][j]) dis[i][j] = adj[i][j]; 
            else dis[i][j] = inf; 
        }
    }
    

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
            }
        }
    }
}

// DIJKSTRA (DENSE GRAPHS)
void dijkstra(int k){
    int n; 
    const int inf = 1e9;
    vector<bool> used(n, 0); 
    vector<int> dist(n, inf); 
    vector<vector<pair<int, int>>> adj; 

    dist[k] = 0; 

    for(int i=0; i<n; i++){
        int x = -1; 
        for(int j=0; j<n; j++){
            if(!used[j] && (x == -1 || dist[j] < dist[x])) x = j; 
        }

        if(dist[x] == inf) break; // distinct connected component

        used[x] = 1; 

        for(auto [a, b]: adj[x]){
            if(dist[a] > dist[x] + b){
                dist[a] = dist[x] + b; 
            }
        }
    }
}

// DIJKSTRA (SPARSE GRAPHS)
void dijkstra(int k){
    int n;
    const int inf = 1e9;
    vector<bool> used(n, 0);
    vector<int> dist(n, inf);
    vector<vector<pair<int, int>>> adj;

    dist[k] = 0;

    priority_queue<pair<int, int>> q; 
    q.push({0, k}); 


    while(!q.empty()){
        int f = q.top().second; 
        q.pop(); 

        if(used[f]) continue; 
        used[f] = 1; 

        for(auto [x, y]: adj[f]){
            if(dist[x] > dist[f] + y){
                dist[x] = dist[f] + y; 
                q.push({-dist[x], x}); 
            }
        }
    }
}


