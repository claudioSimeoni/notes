#include <bits/stdc++.h> 
using namespace std; 

constexpr int inf = 1e9; 

class MinSegment{
private: 
    vector<int> tr; 
    int sz; 

    void build(const vector<int>& a, int v, int l, int r){
        if(l == r){
            tr[v] = a[l]; 
            return; 
        }
        int m = (l + r) / 2; 
        build(a, 2*v, l, m); 
        build(a, 2*v + 1, m + 1, r); 
        tr[v] = min(tr[2*v], tr[2*v + 1]);
    }

    void update(int v, int l, int r, int ind, int val){
        if(r == l){
            tr[v] = val; 
            return; 
        }
        int m = (r + l) / 2; 
        if(ind <= m) update(2*v, l, m, ind, val); 
        else update(2*v + 1, m + 1, r, ind, val); 
        tr[v] = min(tr[2*v], tr[2*v + 1]);
    }

    int query(int v, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return inf; 
        if(l >= ql && r <= qr) return tr[v]; 
        int m = (l + r) / 2; 
        return min(query(2*v, l, m, ql, qr), query(2*v + 1, m + 1, r, ql, qr));  
    }

public: 
    MinSegment(int s){
        sz = s; 
        tr.resize(s * 4, inf); 
    }

    MinSegment(const vector<int>& a) : sz(a.size()){
        tr.resize(sz * 4, inf); 
        build(a, 1, 0, sz - 1); 
    }

    void update(int ind, int val){
        update(1, 0, sz-1, ind, val); 
    }

    int query(int ql, int qr){
        return query(1, 0, sz-1, ql, qr); 
    }
};

class seg{
private: 
    vector<int> tr; 
    int sz; 

    void build(const vector<int>& a, int v, int l, int r){
        if(l == r){
            tr[v] = a[l]; 
            return; 
        }
        int m = (l + r) / 2; 
        build(a, 2*v, l, m); 
        build(a, 2*v + 1, m + 1, r); 
        tr[v] = tr[2*v] +tr[2*v + 1];
    }

    void update(int v, int l, int r, int ind, int val){
        if(r == l){
            tr[v] = val; 
            return; 
        }
        int m = (r + l) / 2; 
        if(ind <= m) update(2*v, l, m, ind, val); 
        else update(2*v + 1, m + 1, r, ind, val); 
        tr[v] = tr[2*v] + tr[2*v + 1];
    }

    int query(int v, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0; 
        if(l >= ql && r <= qr) return tr[v]; 
        int m = (l + r) / 2; 
        return query(2*v, l, m, ql, qr) + query(2*v + 1, m + 1, r, ql, qr);  
    }

public: 
    seg(int s){
        sz = s; 
        tr.resize(s * 4, inf); 
    }

    seg(const vector<int>& a) : sz(a.size()){
        tr.resize(sz * 4); 
        build(a, 1, 0, sz - 1); 
    }

    void update(int ind, int val){
        update(1, 0, sz-1, ind, val); 
    }

    int query(int ql, int qr){
        return query(1, 0, sz-1, ql, qr); 
    }
};