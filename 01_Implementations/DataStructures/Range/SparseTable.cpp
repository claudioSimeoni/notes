#include <bits/stdc++.h> 
using namespace std; 

// A sparse table is a static data structure that is built in O(n * log n) that supports range 
// queries in O(1), it can only be used with idempotent operations such as min, max, gcd, lcm. 

struct MinSparseTable{
    vector<vector<int>> table;  
    vector<int> mp2; 

    int sz; 
    int max_mp2; 

    MinSparseTable(vector<int>& v) : sz(v.size()) {
        max_mp2 = max_pow2(sz); 
    
        mp2.resize(sz + 1);
        for(int i=2; i<=sz; i++){
            mp2[i] = mp2[i/2] + 1; 
        }
        
        table.resize(sz, vector<int> (max_mp2 + 1)); 
        for(int i=0; i<=max_mp2; i++){
            for(int j=0; j<sz; j++){
                if(i == 0){
                    table[j][i] = v[j]; 
                    continue; 
                }
                table[j][i] = table[j][i - 1]; 
                if(j + (1 << (i - 1)) < sz) table[j][i] = min(table[j + (1 << (i - 1))][i - 1], table[j][i]); 
            }
        } 
    }

    int query(int a, int b){
        int l = b - a + 1; 
        int l_mp2 = mp2[l]; 
        return min(table[a][l_mp2], table[b - (1 <<l_mp2) + 1][l_mp2]); 
    }

    // utility 

    // returns the max power of two less or equal of k
    int max_pow2(int k){
        int mp2 = 0; 
        int val = 1; 
        while(val <= k){
            val *= 2; 
            mp2++; 
        }
        return mp2-1; 
    }
}; 

int main(){
    int n, q; cin >> n >> q;
    vector<int> v(n); 

    for(int i=0; i<n; i++) cin >> v[i]; 

    MinSparseTable mst(v);
    
    while(q--){
        int a, b; cin >> a >> b; b--; 
        cout << mst.query(a, b) << "\n"; 
    }
}

// Static Range Minimum Queries CSES 