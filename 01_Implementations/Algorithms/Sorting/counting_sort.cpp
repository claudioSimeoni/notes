#include <bits/stdc++.h> 
#include "sort_utility.cpp"
using namespace std; 

// This algorithm assumes that the values in vector "a" lie within the range 0-k and count the occurencies of each number,
// then it place each number in it's position in vector "b". Counting sort is a stable sorting method: this means that whenever two numbers 
// in "a" have the same value they mantain their reciprocal order in the sorted array. 

// O(n)
void counting_sort(vector<int>& a, vector<int> & b, int k){
    vector<int> c(k+1);

    for(int i=0; i<a.size(); i++){
        c[a[i]]++; 
    }

    for(int i=1; i<=k; i++){
        c[i] = c[i] + c[i-1]; 
    }

    for(int i=a.size()-1; i>=0; i--){
        b[c[a[i]]-1] = a[i]; 
        c[a[i]]--;  
    }   
}

int main(){
    vector<int> v = {10, 5, 6, 2 , 1, 7, 5, 9, 32}; 
    vector<int> sv(9); 

    counting_sort(v, sv, 32); 
    print_vector(sv); 
}