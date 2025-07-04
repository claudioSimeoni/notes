#include <bits/stdc++.h> 
using namespace std; 

constexpr int inf = 1e9; 

void dfs(int k, int prev, vector<vector<int>>& adj, vector<int>& euler, vector<int>& subtree){
    euler.push_back(k); 
    for(auto ad: adj[k]){
        if(ad == prev) continue;
        dfs(ad, k, adj, euler, subtree); 
        subtree[k] += subtree[ad]; 
    }
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<vector<int>> adj(n);  
        vector<int> subtree(n, 1); 
        vector<pair<int, int>> v(n); 
        vector<int> eul; 
        vector<int> eul_ind(n); 

        for(int i=0; i<n; i++){
            int a; cin >> a;
            v[i] = {a, i}; 
        }

        for(int i=0; i<n-1; i++){
            int a, b; cin >> a >> b; a--; b--; 
            adj[a].push_back(b); 
            adj[b].push_back(a); 
        }

        dfs(0, -1, adj, eul, subtree);
        for(int i=0; i<n; i++) eul_ind[eul[i]] = i; 

        // building max prefix and postfix 
        vector<int> max_pref(n); 
        vector<int> max_post(n); 

        max_pref[0] = v[eul[0]].first; 
        max_post[n-1] = v[eul[n-1]].first; 

        for(int i=1; i<n; i++) max_pref[i] = max(max_pref[i-1], v[eul[i]].first);
        for(int i=n-2; i>=0; i--) max_post[i] = max(max_post[i+1], v[eul[i]].first);

        sort(v.begin(), v.end()); 

        for(int i=n-1; i>=0; i--){
            int nd = v[i].second; 
            int val = v[i].first; 

            int mx = -1; 
            if(eul_ind[nd] > 0) mx = max(mx, max_pref[eul_ind[nd] - 1]); 
            if(eul_ind[nd] + subtree[nd] < n) mx = max(mx, max_post[eul_ind[nd] + subtree[nd]]);  

            if(mx > val){
                cout << nd + 1 << "\n"; 
                break; 
            }

            if(i == 0 && mx <= val) cout << 0 << "\n"; 
        }
        
    }
}