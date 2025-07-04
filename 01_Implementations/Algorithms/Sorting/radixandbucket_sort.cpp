#include <bits/stdc++.h> 
#include "sort_utility.cpp"
using namespace std; 

void insertion_sort(vector<int>& v){
    for(int i=1; i<v.size(); i++){
        int index = i; 
        while(index > 0 && v[index] < v[index-1]){
            swap(v[index], v[index-1]); 
            index--; 
        }
    }
}

void radix_sort(vector<int>& a, int k){
    for(int i=0; i<k; i++){
        // sorts the numbers by the i'th digit from the right using a stable sorting method such as counting sort
    }
}

// bucket sort assumes that the elements of a are well distributed numbers in the interval 0-k
void bucket_sort(vector<int>& a, int k){
    int sz = a.size(); 
    vector<vector<int>> b(sz);
    
    for(int i=0; i<sz; i++){
        b[a[i] * sz / k].push_back(a[i]); 
    }

    for(int i=0; i<sz; i++){
        insertion_sort(b[i]); 
    }

    pair<int, int> ptr = {0, 0}; 
    for(int i=0; i<sz; i++){
        while(ptr.first < sz && b[ptr.first].size() <= ptr.second){
            ptr.first++; 
            ptr.second = 0; 
        } 
        if(ptr.first >= sz) break; 
        a[i] = b[ptr.first][ptr.second]; 
        ptr.second++;
    }
}

int main(){
    vector<int> v = {10, 5, 6, 2 , 1, 7, 5, 9, 32}; 

    bucket_sort(v, 33);  
    print_vector(v); 
}