#include <bits/stdc++.h>
using namespace std; 

#define ll long long 

constexpr ll mod = 1e9 + 7; 

void dfs(ll& k, vector<vector<ll>>& adj, vector<bool>& vis, ll& cntnodes, ll& cntedges, ll& self){
    if(vis[k]) return; 
    vis[k] = 1; 
    cntnodes++; 

    for(auto ad: adj[k]){
        if(ad == k){
            self++; 
            continue; 
        }
        cntedges++; 
        dfs(ad, adj, vis, cntnodes, cntedges, self); 
    }
}

ll manhattan(pair<ll, ll>& p1, pair<ll, ll>& p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int  main(){
    ll t; cin >> t; 
    while(t--){
        ll n, m, k; cin >> n >> m >> k;
        vector<pair<ll, ll>> pts(k + 1); 

        for(ll i=0; i<k+1; i++){
            ll a, b; cin >> a >> b; a--; b--; 
            pts[i].first = a;
            pts[i].second = b; 
        }

        vector<vector<ll>> adj(n * m); 
        vector<bool> vis(n * m); 
        
        bool poss = 1; 
        
        auto get = [&](ll i, ll j){
            return i * m + j; 
        }; 
        
        for(ll i=0; i<k; i++){
            if(manhattan(pts[i], pts[i+1]) != 2){
                poss = 0; 
                break;
            }
            
            if(pts[i].first == pts[i+1].first){
                ll ind = get(pts[i].first, (pts[i].second + pts[i+1].second) / 2);
                adj[ind].push_back(ind); 
            }
            else if(pts[i].second == pts[i+1].second){
                ll ind = get((pts[i].first + pts[i+1].first) / 2, pts[i].second);
                adj[ind].push_back(ind); 
            }
            else{
                ll ind1 = get(pts[i].first, pts[i+1].second); 
                ll ind2 = get(pts[i+1].first, pts[i].second); 
                
                adj[ind1].push_back(ind2); 
                adj[ind2].push_back(ind1); 
            }
        }

        ll ans = 1; 
        
        if(!poss) cout << 0 << "\n"; 
        else{
            for(ll i=0; i<n * m; i++){
                if(!vis[i]){
                    ll nodes = 0, edges = 0, self = 0; 
                    dfs(i , adj, vis, nodes, edges, self); 

                    edges = edges / 2 + self; 

                    if(edges == nodes - 1){
                        ans *= nodes;
                        ans %= mod;  
                    }
                    else if(edges == nodes){
                        if(self == 0) ans *= 2; 
                        ans %= mod; 
                    }
                    else{
                        ans = 0; 
                        break; 
                    }
                }
            }

            cout << ans << "\n"; 
        }
    }
}

// 