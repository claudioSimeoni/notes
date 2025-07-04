#### Counting the number of paths from node i to node j  

The **square** of a graph G is a graph with the same nodes but with an edge between two nodes only if the original graph has a path <= 2 that links these two. To solve this you can use this trick: the matrix MG of adjacency of the graph G raised to n has in the cell ij the number of paths of length n from node i to node j. 

---
#### Finding the universal sink given the adj matrix 

The **universal sink** of a directed graph if it exists is a node that has inner degree 0 and outer degree v-1. Given an adjacency matrix of this graph a strategy to find a sink if it exists is to go through the matrix from the top left corner and keep going to the right when we find a 0 and downwards when you find a 1. 

---
#### Mod 9 Mod 11

When dealing with sum of the digits you must immediately come up with the idea of mod 9. An interesting fact is that using modular arithmetic you can build analogous criteria with 99, 999, ... So also this idea should arise in your mind. An analogue situations shows up with the alternating sum of digits, even in this situation you can build new criteria with 11, 111.  

[Hacking Numbers (Hard Version) ~CF2600](https://codeforces.com/contest/2109/problem/C3) in this problem the idea is that you can easily control $S(k)$ if a number is divisible by $10^n - 1$ and it has at most $2n$ digits, clearly $S(k) = 9n$. Another important fact to analyze in this problem is that we want the overall function to converge. 

---
#### Regions of the plan 

- To find out if a point is inside a region you can basically shoot a ray from that point and see how many times you cross some borders
- To see how many integer coordinate squares a curve intersect you can basically see how many vertical or horizontal line does it cross 

- ---

 > **2SUM**: Given a sorted array, we want to find two elements with sum x.  We can use two pointers, one starting from the right and the other from the left. **<span style="color: green">Sum of two values</span>**

---

> Given (a1, ... an) we want to minimize $S = |a1-x| + ... |an-x|$ choosing an appropriate x, it turn's out that the best choice is always the median of the array. Instead regarding $S = (a1-x)^2 + ... (an-x)^2$ you just compute it with the derivative. **<span style="color: green">Stick Lengths</span>**

