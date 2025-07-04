#include <bits/stdc++.h> 
#include "sort_utility.cpp"
using namespace std; 

constexpr int inf = 1e9; 

// Algorithm like insertion sort or bubble sort are called "in-place" because they don't need extra memory to work.

// O(n^2) 
void insertion_sort(vector<int>& v){
    for(int i=1; i<v.size(); i++){
        int index = i; 
        while(index > 0 && v[index] < v[index-1]){
            swap(v[index], v[index-1]); 
            index--; 
        }
    }
}

// O(nlogn)
void merge_sort(vector<int>& v, int l, int r){
    if(r <= l) return; 
    int m = (l+r) / 2; 
    merge_sort(v, l, m); 
    merge_sort(v, m+1, r); 
    merge(v, l, m, r); 
}
// If we define an inversion a, b : a < b && v[a] > v[b] we can count the inversions of an array by slightly modifying
// the merge function, while we merge we count inversions. 

// O(n^2)
void bubble_sort(vector<int>& v){
    for(int i=0; i<v.size()-1; i++){
        for(int j=v.size()-1; j>i; j--){
            if(v[j-1] > v[j]){
                swap(v[j], v[j-1]); 
            }
        }
    }
}

// O(logn)
int binary_search(int x, vector<int>& v){
    int l = 0, r = v.size();
    while(r - l > 1){
        int m = (l + r) / 2; 
        if(v[m] > x) r = m; 
        else l = m; 
    }
    if(v[l] == x) return l; 
    else return -1; 
}

// For the problem: maximum subarray sum there exist many solution, one example is iterating through all the possibilities in O(n^2),
// you could also use divide and conquer to find it in O(nlogn) but actually the easiest implementation is O(n), it keeps track of the 
// current maximum subarray ending at index i and when it advances currmax = max(currmax + v[i], v[i]).

int max_subarray_sum(vector<int>& v){
    int currmax = -inf; 
    int max_sum = -inf; 
    for(int i=0; i<v.size(); i++){
        currmax = max(currmax + v[i], v[i]); 
        max_sum = max(max_sum, currmax); 
    }
    return max_sum; 
}

// Strassen's algorithm for matrix moltiplications runs in O(n^(lg7 =~ 2.81)), it consists in partitioning the original matrix in four new 
// matrices and from there you sum and multiply many times these matrices and then combine them to reach the final result.

int main(){
    vector<int> vec = {10, 9, 8, 2, 7, 5, 4, 3, 2, 1, 0}; 
    bubble_sort(vec); 

    cout << binary_search(15, vec) << " " << binary_search(0, vec) << "\n"; 
    print_vector(vec); 
}   

