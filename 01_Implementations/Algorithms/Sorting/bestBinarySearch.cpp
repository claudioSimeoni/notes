#include <bits/stdc++.h> 
using namespace std; 

vector<int> fun; 

// the best bs implementation
int binarysearch(int a, int b){
    while(b - a > 1){
        int k = (a+b) / 2; 
        if(fun[k]) a = k; 
        else b = k; 
    }
    // returns a or b depending on what we need
}