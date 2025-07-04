#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; 
vector<int> vis;
vector<int> dis; 
vector<vector<int>> grid; 
vector<vector<bool>> gridvis; 
vector<int> ct; 
vector<int> toleaf; 
vector<int> maxlength; 

int r; 
int c; 
int color; 

void dfs(int a){
    if(vis[a]) return; 
    vis[a] = true; 
    for(auto x: adj[a]){
        dfs(x); 
    }
}

void bfs(int x){
    queue<int> q; 
    vis[x] = true; 
    dis[x] = 0; 
    q.push(x);  

    while(!q.empty()){
        int head = q.front(); 
        q.pop(); 
        
        for(auto k: adj[head]){
            if(vis[k]) continue; 
            dis[k] = dis[head] + 1; 
            q.push(k);
            vis[k] = true;  
        }
    }
}

// ---FLOODFILL---

void floodfill(int a, int b){
    if(a >= r || a < 0 || b >= c || b < 0 || gridvis[a][b] || grid[a][b] != color) return; 
    gridvis[a][b] = true; 

    floodfill(a - 1, b); 
    floodfill(a + 1, b); 
    floodfill(a, b - 1); 
    floodfill(a, b + 1); 
}

// with bfs
void bfs(){
    // lets say we start from a 
    int rw, cl; 
    pair<int, int> a; 
    pair<int, int> dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q; 

    vector<vector<int>> dis(r, vector<int> (c)); 
    vector<vector<pair<int, int>>> parent(r, vector<pair<int, int>> (c));
    dis[a.first][a.second] = 0;
    q.push(a); 
      
    while(!q.empty()){
        pair<int, int> f = q.front(); 
        q.pop(); 
        for(auto x: dir){
            int r = f.first + x.first, c = f.second + x.second; 
            if(r >= rw || r < 0 || c >= cl || c < 0 || dis[r][c] != 1001 || grid[r][c] == '#') continue; 
            dis[r][c] = dis[f.first][f.second] + 1; 
            parent[r][c] = f; 
            q.push({r, c});
        }
    }
}

// ---Tree dfs--- 
void treedfs(int x, int y){
    for(auto k: adj[x]){
        if(k != y) treedfs(k, x); 
    }
}
