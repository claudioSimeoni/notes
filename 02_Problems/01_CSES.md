## Missing Coin Sum 

Here the idea recalls [[00_PROBLEMS#Racing ~CF1400]], you greedily store the range of numbers you can build and you update it while you add new coins. 

---
## Nested Ranges Check

Here we have a set of segments and for each of them we want to find out whether it is a subsegment of some segment. Here the idea is to go through the segments sorted by the first coordinate and then storing the visited ones into a set sorted by the second coordinate. Same idea of [[00_PROBLEMS#Field Division (easy version)]].

---
## Nearest Smallest Value 

Just use a stack. 

---
## Subarray sum II 

This is a typical situation: you need to count how many subarrays have sum x, the idea is to use a map to keep track of how many prefixes have sum i and then if at a certain moment the pref has sum k you add to the answer k - x. An interesting problem about that is [Yamakasi](https://codeforces.com/contest/2121/problem/F)

---
## Sum of two values

By using two pointers you can easily compute how many couples have a certain sum x, but also how many of them have sum > x etc... You can also see [Coloring Game](https://codeforces.com/contest/2112/problem/C).

--- 
## Range Update Queries

Remember this simple trick of storing the diff array and then simply modifying the extremes to add or remove x to an entire range, then you simply query with a segment on the diff array. 