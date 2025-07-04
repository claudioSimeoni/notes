#include <bits/stdc++.h> 
using namespace std; 

struct DSU{
    vector<int> dsu; 
    int sz; 

    DSU(int s) : sz(s){
        dsu.resize(sz, -1);  
    }

    int find(int k){
        if(dsu[k] < 0) return k; 
        return dsu[k] = find(dsu[k]); 
    }

    bool unite(int a, int b){
        a = find(a); b = find(b); 
        if(a == b) return false; 
        if(dsu[a] > dsu[b]) swap(a, b); 
        dsu[a] += dsu[b]; 
        dsu[b] = a; 
        return true; 
    }
};