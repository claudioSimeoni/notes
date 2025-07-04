## MOST POPULAR SORTING ALGORITHMS 

In the context of competitive programming (CP), it usually isn't required to implement a sorting algorithm manually, but it is interesting to know how sorting is generally implemented.

- **Bubble Sort**:  
Consists in iterating through the array and swapping each pair that is not ordered.  
You do this n times, and in $O(n^2)$ you sort the array.

- **Selection Sort**:  
Iterates through the array, picks the smallest element, and places it at the beginning.  
Time complexity is $O(n^2)$.

- **Merge Sort**:  
A recursive sorting algorithm in $O(n log n)$.  You divide the array into two halves, recursively sort them, and then merge the sorted halves in $O(n)$ by always picking the smallest element from either half.

- **Insertion sort**: 
You iterate through the array and let every element cross all the previous ones until it is in the right place. $O(n^2)$

- **Quick sort**: 
You pick a pivotal element and divide all the elements in smaller than it and bigger ones, then you recur. Worse case $O(n^2)$, average case $O(nlogn)$, pretty efficient in practice, it is widely used, especially with randomization of the elements. 

- **Heap sort:**
Quite simple, you just use an heap end every time you pick the element from the top and swap it with the end of the heap. $O(nlogn)$

- **Counting Sort:**
It runs in $O(n + k)$ where k is the maximum number in the array and it is very useful if k is small, you count how many times every element appears and then reconstruct the array. 

- **Bucket Sort:** 
You pick a dimension for each bucket and put every number in a bucket, then you recurr.

- **Radix Sort:**
Runs in $O(d(n + k))$, sorts a list of numbers with d digits, using counting sort you sort by each digit starting from the units. 


---
##  TWO POINTERS

In the two pointers method, two pointers are used to iterate through the array values. Both pointers can move in one direction only, which ensures that the algorithm works efficiently.

#### Applications:

- **Subarray Sum**:  
  If we are looking for a subarray with sum `x` in an array of positive integers, we can use two pointers, both starting from the left, to solve the problem.

- **2SUM**:  
  Given a sorted array, we want to find two elements with sum `x`.  
  We can use two pointers, one starting from the right and the other from the left.

---
## COMPLETE SEARCH WITH RECURSION

Using this technique you can both compute all the permutations and all the subsets. The most used trick for generating subset is actually by bitwise operations. 

---
## BINARY SEARCH

Binary search is useful to find a number in a sorted array (though this is often handled by built-in C++ functions).  But more importantly, **if you have a function $f(x)$$ that is true up to a point and then false**, binary search can find the **last value for which it is true**, or the **first for which it is false**.

We have a function $f$ of the type described above.  We choose a value $x$ where $f(x) = true$, and a value $y$ where $f(y) = false$.  Then we check $f((x + y) / 2)$. If it is true, we set $x = (x + y) / 2$. Else, we set $y = (x + y) / 2$.  We loop until $b - a > 1$.
 
> **IMPORTANT**:  
    Whenever you have to find the **minimum or maximum value** that satisfies a certain property, probably you will have to use **binary search**.  The important thing is that checking the "value of the function" takes `O(n)` at most.
    
>**IMPORTANT 2**:  
    Whenever your goal is to find the minimum (or maximum) value that satisfies a property, but you **cannot directly compute** if a precise value satisfies it, you may be able to check whether a **lower** (or higher) value satisfies it.  Here you can do the **exact same thing** as a classic binary search.
    
> **IMPORTANT 3**:  
    Before using binary search, ensure that the property you're checking is actually: true true true, false false false. 