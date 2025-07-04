#include <bits/stdc++.h> 
using namespace std; 

// when dealing with selection of the max or of the min we can easily iterate through the array. 

// if we want to select the i-th element we have 2 options, the **first one** is using a modified version of quicksort, this will be 
// average O(n) while the worst case is O(n^2). The **second one** is the following: you divide the array in groups of five element
// then you sort the group with insertion sort, then you consider the median of each group and you recurr on this new array made 
// by the medians to find the median of this array and then you use it to pivot using a simil-quicksort approach. 

int main(){}