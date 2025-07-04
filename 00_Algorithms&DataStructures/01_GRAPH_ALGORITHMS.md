## GRAPH TRAVERSAL

Graphs can be represented by **adjacency list** or **adjacency matrix**, or **edges list**. Usually adjacency lists are preferred because they require less memory. Depth-first search and Breadth-first *(ampiezza)* search are the most popular ways to traverse a graph, they both run in $O(nodes + edges)$. 
#### FloodFill

Floodfill *(piena/alluvione)* is used to traverse a grid or just a portion of it that satisfies a condition. Clearly while you floodfill you can also check other conditions such as the number of blocks of each component. **Works exactly as dfs** and runs in O($griddim$).

The recursive implementation can sometimes cause stack overflow or TLE so you can use the iterative one, **it is identical to bfs** but it uses `pair<int, int>` to store the coordinates. 

Another important situation in which it is necessary the iterative implementation is when you want to compute the **Shortest Path with Unweighted Edges**, or more generally compute the distance between two nodes, in this case you need to do bfs with the iterative implementation. In addition in the first case you also need to store the parents. Note that the same thing can be done in a traditional graph by using bfs and tracking parents. Then we would need to backtrack to find the shortest path.

---
## FUNCTIONAL GRAPHS

In a **succession graph** (functional) the out degree of each node is 1, $i.e.$, exactly one edge starts at each node. A successor graph consists of one or more components, each of which contains one cycle and SOME paths that lead to it. 

You can easily *compute $succ(x, k)$*, where $succ(x, k)$ is the function $succ$ applied k times by using the following recursion: 

$$
\text{succ}(x, k) =
\begin{cases}
\text{succ}(x) & \text{if } k = 1 \\
\text{succ}(\text{succ}(x, \frac{k}{2}), \frac{k}{2}) & \text{if } k > 1
\end{cases}
$$

We use it to precalculate $succ(x, 2^z)$ for each $z$ while $2^z < u$ (where u is the max iteration for which we need to compute the function). We do so for each x and this takes $O(nlogu)$ now we can easily compute $succ(x, k)$ in $O(logk)$, this is quite the same principle behind [[DS2_RANGE#SPARSE TABLE]].

> **FLOYD’s algorithm** walks forward in the graph using two pointers a and b. Both pointers begin at a node x that is the starting node of the graph. Then, on each turn, the pointer a walks one step forward and the pointer b walks two steps forward. The process 	continues until the pointers meet each other. At this point, the pointer a has walked $k$ steps and the pointer b has walked $2*k$ steps, so the length of the cycle divides $k$. Thus, the first node that belongs to the cycle can be found by moving the pointer a to node $x$ and advancing the pointers step by step until they meet again. 

**ATTENTION:** sometimes traversing a functional graph can lead to tle because you are traversing more than once the paths, thus you should use the [[IMPLEMENTATION_TRICKS#The 0 1 2 Trick]].

---
## TOPOLOGICAL SORT

If you have a **DAG (directed a-cyclic graph)** you have multiple ways to form a topological sort, this means that whenever you have an arrow from a to b in the original graph, in the sorted array a appears before b. This array is generally not unique. To determine one of these array you can use both bfs and dfs (in both cases it takes $O(nodes + edges)$): 

- With bfs (**Kahn's Algorithm**) you visit firstly the nodes with `indegree = 0`, in fact the first node of the sorted array must have in degree 0, then we can proceed in a recursive way: as soon as we pop elements with in degree 0 we update their neighbors and check whether their in degree become 0 and in this case we push it. 

We can also use Kahn's algorithm to extract the **lexicographic minimum topological sort** by breaking ties lexicographic. Although the above code does not do this, one can simply replace the queue with a priority_queue to implement this extension. 

- With dfs we traverse the graph starting from random nodes and then push them in reverse order, at the end we reverse the array. To see why this works you can reason by contradiction. 

> Note that usually the bfs implementation is slightly better, while if you want to track a cycle dfs is better. 

---
## SHORTEST PATH 

#### BELLMAN-FORD ALGORITHM 

Firstly we suppose that we do not have negative cycles. In fact the algorithm computes the shortest path (not simple path) from a node $x$ to any node of the graph. Id does this by iterating $n-1$ times trough every edge of the graph, because every shortest path is long at most $n-1$, $n-1$ iterations suffices. In addition we added the "done" that makes everything end if during an iteration everything remains stable. Clearly we can easily reconstruct the path by keeping the parents. The algorithms takes $O(nm)$. 

To check whether a negative cycle exists you can basically perform $n$ steps and if anything changes during the last step so you have a negative cycle. 

#### SPFA

This algorithm basically do the same of bellman ford but it keeps in a queue the nodes that were recently updated because they could update their neighbors (since the value of the neighbors might depend on it). Complexity:  $O(nm)$. 

#### FLOYD-WARSHALL

This algorithm computes all the distances between any couple of vertices, it keeps a matrix whose value of $i,j$ is the current distance of node i and j and you iterate through all the vertices, each of these shorten some couple of vertices distance. Note that as in the previous algorithms you cannot have negative cycles. Complexity: $O(n^3)$.

#### DIJKSTRA 

Dijkstra's algorithm works when we have a graph with non negative weights. In the first case we have a dense graph, where $m$ ~ $n^2$ and it computes all the shortest paths from a vetex $k$ to every other vertex. Complexity: $O(n^2 + m)$. 

In the second version we speed up the searching of the shortest distance current element by keeping a priority queue q  that contains pairs of the form $(−d, x)$, meaning that the current distance to node $x$ is $d$. Complexity: O($(n + m)logn$). 

> A last important way to compute the shortest path from a single source occurs when dealing with **DAGs**, in these case you can simply perform a topological sort and then proceed with a **DP**, this allows you to compute everything you need in just $O(n + m)$, this technique can be used in many other situations. 
--- 
## STRONGLY CONNECTED COMPONENTS 

About SCC, the most common way to compute it is using **Kosaraju's Algorithm**, you firstly do a dfs and insert in a stack nodes as soon as they get processed (i. e. when you return from that node), and then in the stack order you call dfs every time you find a not visited node and boom: you have the SCCs. 

The problem of **satisfiability** is an NP problem that requires to find, given a boolean formula with boolean variables $x_i$, the values of $x_i$ for which the formula is true. Well in some specific cases it turns out that you can do it in polynomial time. This is the case of 2-SAT, in this problem you are given a boolean formula $(x_a \lor x_b) \land ... \land (x_j \lor x_i)$ and you need to solve the satisfiability problem. You begin by building a graph with nodes $x_i$ and $\lnot x_i$ where if $x_i$ and $x_j$ are in the same block you link node $\lnot x_i$ to $x_j$ and $\lnot x_j$ to $x_i$. You then compute connected components of this graph. Now you can build a **component graph** that by construction is a **DAG**, and from here you top-sort it and you insert each component from the end of the original array, avoiding components with elements that where already inserted.

