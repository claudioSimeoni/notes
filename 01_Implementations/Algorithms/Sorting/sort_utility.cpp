#include <bits/stdc++.h> 
using namespace std; 

void print_vector(vector<int>& v){
    for(int i=0; i<v.size(); i++) cout << v[i] << " "; 
}

void merge(vector<int>& v, int l, int m, int r){ 
    int a = 0; 
    int b = 0; 
    int curr = l; 
    vector<int> v1; 
    vector<int> v2; 
    for(int i=l; i<=m; i++) v1.push_back(v[i]); 
    for(int i=m+1; i<=r; i++) v2.push_back(v[i]); 

    while(a < v1.size() && b < v2.size()){
        if(v1[a] < v2[b]){
            v[curr] = v1[a]; 
            a++; 
        }
        else{
            v[curr] = v2[b]; 
            b++; 
        }
        curr++; 
    }
    for(int i=a; i<v1.size(); i++){
        v[curr] = v1[i]; 
        curr++; 
    }
    for(int i=b; i<v2.size(); i++){
        v[curr] = v2[i]; 
        curr++; 
    }   
}

int partition(vector<int>& v, int l, int r){
    int pivot = v[r]; 

    int sec_block = l; 

    for(int i=l; i<r; i++){
        if(v[i] <= pivot){
            swap(v[i], v[sec_block]); 
            sec_block++; 
        }
    }
    swap(v[r], v[sec_block]); 
    return sec_block;
}