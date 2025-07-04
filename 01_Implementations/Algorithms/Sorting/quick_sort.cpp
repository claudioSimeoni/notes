#include <bits/stdc++.h> 
#include "sort_utility.cpp"
using namespace std; 

void quicksort(vector<int>& v, int l, int r){
    if(r - l <= 0) return; 
    int pivot = partition(v, l, r); 
    quicksort(v, l, pivot - 1); 
    quicksort(v, pivot + 1, r); 
}

int main(){
    vector<int> vec = {10, 2, 5, 2, 3, 5, 6, 7, 4}; 
    quicksort(vec, 0, vec.size()-1); 
    print_vector(vec); 
}
