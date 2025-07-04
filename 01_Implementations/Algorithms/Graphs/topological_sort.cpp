#include <bits/stdc++.h> 
using namespace std; 

vector<vector<int>> adj; 
vector<int> vis;

// With bfs (Kahn's Algorithm)
void topsort(){
    vector<int> indegree; 
    queue<int> q;
    vector<int> topsort; 

    // Here we push all the elements with indegree 0
    for(int i=0; i<indegree.size(); i++) if(indegree[i] == 0) q.push(i); 

    while(!q.empty()){
        int f = q.front();
        q.pop();  
        topsort.push_back(f);

        for(auto k: adj[f]){
            if(--indegree[k] == 0) q.push(k); 
        }
    }
    // If the size of topsort is < n it means that the graph is not a dag
}

// With dfs 
void dfs_for_topsort(int k, vector<int>& revsort){
    if(vis[k]) return; 
    vis[k] = 1; 
    for(auto x: adj[k]){
        dfs_for_topsort(x, revsort); 
    }    
    revsort.push_back(k); 
}

void topsort2(){
    vector<int> revsort; 
    for(int i=0; i<adj.size(); i++){
        if(vis[i]) continue; 
        dfs_for_topsort(i, revsort); 
    }
    reverse(revsort.begin(), revsort.end()); 
}
