#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
#define pb push_back
#define nl << "\n"
#define _ << " " <<
    
constexpr ll inf = 1e18 + 1;
constexpr ll mod = 1e9 + 7;
    
class SumSegment{
private: 
    vector<ll> tr; 
    ll sz; 
    
    void build(const vector<ll>& a, ll v, ll l, ll r){
        if(l == r){
            tr[v] = a[l]; 
            return; 
        }
        ll m = (l + r) / 2; 
        build(a, 2*v, l, m);
        build(a, 2*v + 1, m + 1, r); 
        tr[v] = tr[2*v] + tr[2*v + 1]; 
    }
    
    void update(ll v, ll l, ll r, ll pos, ll val){
        if(l == r){
            tr[v] = val; 
            return; 
        }
        ll m = (l + r) / 2; 
        if(pos <= m) update(2*v, l, m, pos, val); 
        else update(2*v + 1, m + 1, r, pos, val); 
        tr[v] = tr[2*v] + tr[2*v + 1]; 
    }
    
    ll query(ll v, ll l, ll r, ll ql, ll qr){
        if(l > qr || r < ql) return 0; 
        if(ql <= l && qr >= r) return tr[v];
        ll m = (l + r) / 2;  
        return query(2*v, l, m, ql, qr) + query(2*v + 1, m + 1, r, ql, qr);
    }
    
public: 
    SumSegment(const vector<ll>& v) : sz(v.size()){
        tr.resize(v.size() * 4); 
        build(v, 1, 0, v.size() - 1); 
    }
    
    void update(ll pos, ll val){
        update(1, 0, sz-1, pos, val); 
    }
    
    ll query(ll ql, ll qr){
        return query(1, 0, sz-1, ql, qr); 
    }
};
    
bool swaps_parity(vector<ll>& v, int n){
    bool ret = 0; 
    vector<ll> rng(n + 1); 
    SumSegment sg(rng); 
    
    for(ll i=0; i<v.size(); i++){
        int pr = sg.query(v[i], n) % 2; 
        ret ^= pr; 
        sg.update(v[i], 1); 
    } 
    return ret; 
}
    
int main() {
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n; 
        vector<ll> v(n); 
        vector<ll> even; 
        vector<ll> odd; 
    
        for(ll i=0; i<n; i++){
            ll a; cin >> a; 
            v[i] = a; 
            if(i % 2) odd.push_back(a); 
            else even.push_back(a); 
        }
    
        bool pe = swaps_parity(even, n); 
        bool po = swaps_parity(odd, n); 
    
        sort(even.begin(), even.end()); 
        sort(odd.begin(), odd.end()); 
        
        vector<int> ans; 
        for(int i=0; i<n; i+=2){
            ans.push_back(even[i / 2]);
            if(i / 2 < odd.size()) ans.push_back(odd[i / 2]); 
        }
    
        if(pe != po) swap(ans[n-1], ans[n-3]); 
        
        for(int i=0; i<n; i++) cout << ans[i] << " "; 
        cout << "\n"; 
    }   
}

// This problems is nice because i found out that a great way to **count inversions** given a set of numbers is to use (coordinate compression
// if needed and) range queries, you iterate on the set of numbers and you query each time how many numbers bigger than x you have already 
// visited. 