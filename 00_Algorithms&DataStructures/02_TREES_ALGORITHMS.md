## INTRODUCTION 

- A **tree** is a connected, acyclic graph. 
- A **tree** consists of n nodes and n − 1 edges.
- Removing any edge from a tree divides it into two components, and adding any edge to a tree creates a cycle. 
- There is always a unique path between any two nodes of a tree.

The **leaves** of a tree are the nodes with degree 1. In a **rooted** tree, one of the nodes is appointed the root of the tree, and all other nodes are placed underneath the root. In a rooted tree, the **children** of a node are its lower neighbors, and the **parent** of a node is its upper neighbor. When dealing with trees it is often useful to root it. 

>Tree dfs is easier to implement because there are no cycle so we don't need to store the visited ones.

>Another interesting fact is that you don't need a bfs to find distances on a tree, you can just use a dfs rooting the tree on that node 

--- 
## SILVER

- Using dp we can easily compute the **size of each subtree** or the length of the longest path from the node to a leaf. **<span style="color:PaleGreen">Subordinates</span>**

- To compute the **diameter** (the longest path between two nodes) of a tree it suffices to dfs from a generic node 'a' to find the farthest node 'b'. Then 'b' is an extreme of the diameter so you can dfs from it to find the diameter. **<span style="color:PaleGreen">Tree Diameter, Tree Distances I</span>

--- 
## GOLD 

#### Euler tour

The technique is the following: you perform a dfs from the root node and you add the elements in an array as soon as you visit them. Now this array can be used to perform several operations: 

#### Subtree and Path Queries

Using a **range query** data structure such as a segment tree, and storing subtrees sizes you can do subtrees queries with updates in O(log n). **<span style="color:palegreen">Subtree Queries</span>**

Actually you can also make queries with updates on paths starting from the root. Let's say we want to support sum queries with updates of the type: summing something to node i. This time the elements stored in the rq are the sum of the elements in the path from the root to node i. The updates on node i will involve the whole subtree of node i, range updates can be done with difference arrays or lazy propagation. 

#### LCA (Lowest Common Ancestor)

- **Method 1**, you use the idea of preprocessing the k-th ancestors where k is a power of two, this can be easily done recursively and also allows queries on the k-th ancestor in $O(logn)$. Now if you have a query a, b, you firstly bring both a and b to the same level and then you iterate through the powers of two from the greatest one checking if the 2^i-th ancestor of both is different, if it is you go one level upwards.   

- **Method 2** is the following: we do an euler tour on the graph, but this time we record every time we go through a node, also while backtracking, thus obtaining a $2 * n - 1$ array x. We also track the position of the first occurrence of each node in that array. We also keep an array for the distances of each node from the root. Now we can simply use a range query data structure to find the LCA. 

#### DP on Trees 

Using DP on Trees we can basically compute anything, here we have a couple of examples of what you can easily do: 

Firstly we can easily solve the problem of finding the greatest **matching** we can build, this means to link every node to one and only one other node. Another thing we can do is finding from every node x the **maximum distance** from that node **to any other node**. **<span style="color: palegreen">Tree Matching</span>**, **<span style="color: palegreen">Tree Distances I</span>**
