#include <bits/stdc++.h> 
using namespace std; 

constexpr int inf = 1e9; 

class BinaryIndexTree{
private: 
    vector<int> tr; 
    vector<int> arr; 
    int sz; 

    void build(const vector<int>& v){
        for(int i=1; i<sz; i++){
            tr[i] += v[i-1]; 
            int k = i + (i&-i); 
            if(k <= sz) tr[k] += tr[i]; 
        }
    }

public: 
    BinaryIndexTree(const vector<int>& vec) : sz(vec.size() + 1){
        tr.resize(sz); 
        build(vec); 
        arr = vec; 
    }

    void update(int k, int x){
        while(k <= sz){
            tr[k] += x; 
            k += k&-k; 
        }
    }

    int pref(int k){
        int s = 0; 
        while(k >= 1){
            s += tr[k];     
            k -= k&-k; 
        }
        return s; 
    }
};





















