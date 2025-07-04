#include <bits/stdc++.h> 
using namespace std; 

// this ds is a tree with a single property, each node has greater value than all the nodes in its subtree
struct heap{
    vector<int> tr; 
    int sz; 

    heap(vector<int>& v) : sz(v.size()){
        tr.resize(sz + 1); 

        for(int i=0; i<sz; i++) tr[i + 1] = v[i]; 
        buildheap(); 
    }

    // O(n) (unexpected)
    void buildheap(){
        for(int i=sz/2; i>=1; i--) maxheapify(i);
    }

    // this metod assumes that the subtrees of the children of node i already satisfy the heap property and fixes node i
    // if it is not the largest among i, l, r. 

    // O(logn)
    void maxheapify(int i){
        int maximum = i; 
        int l = 2 * i; 
        int r = 2 * i + 1; 
        
        if(l <= sz && tr[l] > tr[maximum]) maximum = l; 
        if(r <= sz && tr[r] > tr[maximum]) maximum = r; 

        if(maximum != i){
            swap(tr[i], tr[maximum]); 
            maxheapify(maximum); 
        }
    }

    int top(){
        if(sz > 0) return tr[1]; 
        return -1; 
    }

    // O(logn)
    bool pop(){
        if(sz <= 0) return false; 
        swap(tr[1], tr[sz]); 
        sz--; 
        maxheapify(1); 
        return true; 
    }

    // O(logn)
    void insert(int q){
        sz++; 
        if(tr.size() <= sz) tr.push_back(0); 

        tr[sz] = q; 

        int ind = sz; 
        while(ind > 1 && tr[ind/2] < tr[ind]){
            swap(tr[ind/2], tr[ind]); 
            ind /= 2; 
        }
    }

    // SORT AND UTILITY 

    // heapsort uses the heap to sort an array: you take the root of the tree and put it at the end of the array, then
    // you reduce heapsize and call maxheapify to fix the first element that is not the largest anymore. After this procedure
    // clearly the heap won't be an heap anymore. 
    void heapsort(){
        while(sz > 1){
            swap(tr[1], tr[sz]); 
            sz--; 
            maxheapify(1); 
        }
    }

    void printheap(){
        for(int i=1; i<sz; i++) cout << tr[i] << " "; 
    }
}; 

int main(){
    vector<int> v = {1, 7, 4, 9, 8, 1, 2, 6, 9, 2}; 

    heap h(v);
    h.insert(43); 
    cout << h.top(); 
}   