#include <bits/stdc++.h> 
using namespace std; 

// Order statistic tree with Segment

struct SegmentOST{
    vector<int> tr; 
    int sz; 
    
    SegmentOST(const vector<int>& v) : sz(v.size()){
        tr.resize(4*sz+1); 
        build(v, 1, 0, sz-1); 
    }
    
    void build(const vector<int>& a, int v, int l, int r){
        if(l == r){
            tr[v] = a[l]; 
            return; 
        }
        int m = (l + r) / 2; 
        build(a, 2*v, l, m); 
        build(a, 2*v + 1, m + 1, r);    
        tr[v] = tr[2*v] + tr[2*v + 1];  
    }

    void update(int v, int l, int r, int pos, int val){
        if(l == r){
            tr[v] += val;
            return;  
        }
        int m = (l + r) / 2; 
        if(pos <= m) update(2*v, l, m, pos, val); 
        else update(2*v + 1, m + 1, r, pos, val); 
        tr[v] = tr[2*v] + tr[2*v + 1]; 
    }

    int query(int v, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0; 
        if(l >= ql && r <= qr) return tr[v]; 
        int m = (l + r) / 2; 
        return query(2*v, l, m, ql, qr) + query(2*v + 1, m + 1, r, ql, qr); 
    }

    void del(int pos){
        update(1, 0, sz - 1, pos, 0); 
    }

    void insert(int pos){
        update(1, 0, sz - 1, pos, 1); 
    }

    int cnt(int pos){
        return query(1, 0, sz - 1, 0, pos); 
    }

    int kth(int v, int l, int r, int k){
        if(l == r){
            return l;  
        }
        int m = (l + r) / 2; 
        if(tr[2 * v] >= k) return kth(2 * v, l, m, k); 
        else if(tr[2 * v] + tr[2 * v + 1] >= k) return kth(2 * v + 1, m + 1, r,  k - tr[2 * v]); 
        else return -1; 
    }
};


int main(){
    int n; cin >> n; 
    vector<pair<char, int>> qr(n); 

    set<int> elems; 
    unordered_map<int, int> compress; 
    vector<int> uncompress; 

    for(int i=0; i<n; i++){
        cin >> qr[i].first >> qr[i].second;
        elems.insert(qr[i].first);
        
    }

    // coordinate compression
}