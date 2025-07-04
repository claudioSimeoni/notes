>the notes here are not delving that much, to understand everything just open the problem
## [Racing ~CF1400](https://codeforces.com/contest/2110)

Greedily keeping a range while updating it might be a good idea, see also [[01_CSES#Missing Coin Sum]].

---
## [Field Division (easy version) ~CF1900](https://codeforces.com/contest/1980)

In this problem there is the idea of finding given a set of points on the plan, the set of points such that no point has both of the coordinates bigger than its. We can find this idea also in [[01_CSES#Nested Ranges Check]].

---
## [Swap Dilemma ~CF1700](https://codeforces.com/problemset/problem/1983/D)

Here you can find a typical trick, it is used to **count  inversions**, you can do it by using a segment tree, you iterate through the elements and query how many elements you already visited are bigger than the current. See also [Quartet Swapping](https://codeforces.com/contest/2102/problem/D)

---
## [Magnitude (Hard Version) ~CF1700](https://codeforces.com/problemset/problem/1984/C2)

Really good problem, you can solve it both by dp and being a genius. 

---
## [Running Miles ~CF1700](https://codeforces.com/contest/1826) 

This is such a good problem, you are given an array, you wanna take a range and you wanna maximize x1 + x2 + x3 - (r - l), the sum of the three biggest numbers to which you subtract the length of the range, here the key observation is that you necessarily need to take the two extremes of the interval, otherwise you could have optimized by shortening the range, now you can simply iterate through the central element and use prefix max in an ingenious way: **before prefix max you add or subtract to each element its index so that you are already counting the contribution of the range to it**.  Another interesting idea that occurs often is building **prefix and postfix** (sum, max, min ...) and then combining it by traversing in linear time the array. 

---
## [Unpleasent String ~CF1700](https://codeforces.com/contest/2104/problem/E)

This problem introduces such an interesting technique: if you want to check if some strings X are substrings of a string A and the alphabet has size k, you can pre-build a matrix that tells you for each character m of the string where the following character n is in the string A. Thus for each string of x you can check in O(length x) if x is a substring of A.

Another fact is, given a string S and an alphabet of k char, you want to determine the least string you can make in that alphabet that is not a substring of S, **<span style="color: palegreen">Shortest Subsequence</span>**, the idea is that while you have all the k letters you can go on adding a letter to the result.

---
## [Baggage Claim ~CF2300](https://codeforces.com/contest/2098/problem/D)

This is such a good problem: you have the typical idea of using a graph for like everything, here this idea comes from the fact that you need to count the paths on a grid that satisfy a certain property: you have some couples of cells and **you need to choose only one cell for each of them**, the problem is that some couples have a cell in common, so the idea is that choosing one cell implies that you do not choose the other one! Here exactly like in [[01_GRAPH_ALGORITHMS#STRONGLY CONNECTED COMPONENTS]] with **2-SAT** you can build a DAG that says: if you use this node you won't use this one. 

---
## [Maximum Subarray Sum ~CF1500](https://codeforces.com/contest/2107/problem/C)****

No way this problem has this difficulty, the core observation is that if you let one element of an array grow 1 at time then the MSS will grow not decreasingly mostly 1 at time. From this you can actually binary search.  

--- 
## [23 Kingdom ~CF2200](https://codeforces.com/contest/2102/problem/E)

I know i write this all the time but this is such a good problem: firstly you have to notice that every layer must overlap with all the other layers otherwise you could do better. Then you have to decide how to count the "total blocks" all over all the layers, here the easiest way is by counting how many layers overlap at a certain index. The observation is that the best choice is to pick the first k indices that "allow" k values from 1 to k, and the same for the last k values, then you don't care about the order you put the k values into those indices. So you can basically build prefix and postfix arrays about how many elements are "allowed" until that point and then iterate and each time add the min between the pref and the post.  

---
## [Fewer Batteries ~CF1700](https://codeforces.com/contest/2110/problem/D)

No way this problem is SO FUCKING COOL, firstly the typical idea of watching everything **as if it was a graph**, in this case it is a DAG and it is already topsorted. Now the second great idea is that you can use **DP on DAG** to find out the maximum number of battery you can have at each index. Now the God idea is that **if you want to find out the maximum or minimum weight, so that if you traverse only edges bigger or smaller than it you can eventually reach some node from another one, you can do it by binary searching and each time using only edges bigger or equal than that value.** 

--- 
## [Yasya and the Mysterious Tree ~CF2300](https://codeforces.com/problemset/problem/1980/G)

**If you need to xor all the edges along some path of a tree the good idea is to root the tree and computing the xor from the root,** then because the xor has itself as an inverse you can simply query `d[a] and d[b]` to get the xor along that path. Then here we also have the typical idea of **finding the maximum xor between a number and a set of numbers, this can be done with a trie**. 



 // dp su dag game routes