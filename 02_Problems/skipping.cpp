#include <bits/stdc++.h> 
using namespace std; 

#define ll long long 

constexpr ll inf = 1e18; 

int main(){
    ll t; cin >> t; 
    while(t--){
        ll n; cin >> n; 
        vector<ll> wh(n);
        vector<vector<pair<ll, ll>>> adj(n); 
        vector<ll> dis(n, inf); 

        priority_queue<pair<ll, ll>> pr; 

        for(ll i=0; i<n; i++){
            cin >> wh[i]; 
        }

        for(ll i=0; i<n; i++){
            ll a; cin >> a; a--; 
            if(a > i) adj[i].push_back({a, wh[i]}); 
            
            if(i > 0){
                adj[i].push_back({i-1, 0}); 
                wh[i] += wh[i-1];  
            }  
        }

        pr.push({0, 0}); 
        dis[0] = 0; 

        while(!pr.empty()){
            ll topnode = pr.top().second; 
            ll topdist = -pr.top().first; 

            pr.pop(); 

            if(topdist != dis[topnode]) continue; 

            for(auto ad: adj[topnode]){
                if(dis[topnode] + ad.second < dis[ad.first]){
                    dis[ad.first] = dis[topnode] + ad.second; 
                    pr.push({-dis[ad.first], ad.first}); 
                }
            }
        }

        ll ans = 0; 
        for(ll i=0; i<n; i++){
            ans = max(ans, wh[i]-dis[i]); 
        }

        cout << ans << "\n"; 
    }
}


// This problem present a pattern that is really popular in cp problems: you have a statement that seems to have nothing to do with 
// graphs and you transform it into such a problem. In this case as soon as you have a few intuitions, the fact that from a problem with 
// a certain cost you can move to another one should immediately recall weighted directed graphs. 