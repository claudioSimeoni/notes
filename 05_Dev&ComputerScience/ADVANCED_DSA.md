Here i will store some advanced data structures and algorithms that are not useful for cp but may interesting. 

## B-TREES 

So basically B-trees are BST where each node has n values and n + 1 pointers: the n values divide the domain in n + 1 intervals handled by the n + 1 subtrees.

This is useful when dealing with information stored in the **hard disk**: accessing it requires mechanical actions (for example the HDD is built with magnetic platters and accessing data requires their rotation) that are generally quite slow and so the goal is to rarely access it, thus we flatten the BST to guarantee this property.

This tree has a value $t$ associated, each node must have from $t$ to $2t-1$ values stored. **Searching** a value is done as in a BST. **Inserting** a value is quite similar, while we go through the tree and if we meet a node with $2t-1$ values stored we split it. Concerning the **delete** operation we go through the tree and as soon as we meet the node we want to delete we check the dimensions of the two children, if the both have the minimum dimension we merge them, otherwise we replace it with either the greatest of the left child or the least of the right child and we substitute the node to delete with it.

---
## FIBONACCI HEAP 

The Fibonacci heap is an union of many heaps, these heaps are not binary tree. Each layer of the trees, including the roots of the different trees, is linked with a circular linked list. They support the following operations:

- **MAKE-HEAP $O(1)$**:
  Creates an empty heap.

- **INSERT(x) $O(1)$ amortized**:
  Adds xx to the root list, updating H:minH:min if necessary.

- **MINIMUM() $O(1)$**:
  Returns min.

- **EXTRACT-MIN() $O(\log n)$ amortized**:
  Removes H:minH:min, promotes its children to roots, and triggers **consolidation**, merging trees of the same degree to reduce the number of roots. The new minimum is found among the remaining roots.

- **UNION(H1, H2) $O(1)$**:
  Merges the root lists and updates H:minH:min without immediate consolidation.

- **DECREASE-KEY(x, k) $O(1)$ amortized**:
  If kk is smaller than xx’s parent, xx is cut and moved to the root list. If the parent was already marked (lost a child before), it is also cut, potentially triggering a cascade of cuts.

- **DELETE(x) $O(\log n)$ amortized**:
  Sets xx’s key to −∞−∞, makes it H:minH:min, then calls EXTRACT-MIN.

Fibonacci Heaps are theoretically optimal for applications requiring frequent DECREASE-KEY, such as Dijkstra’s algorithm for shortest paths and Prim’s algorithm for minimum spanning trees. Their amortized efficiency makes them useful in network optimization and graph algorithms with many priority queue operations.

However, they are rarely used in practice due to high constant factors, complex implementation, and inefficient EXTRACT-MIN compared to binary heaps. In real-world applications, d-ary heaps or binary heaps often perform better despite worse theoretical bounds, making Fibonacci Heaps mostly of theoretical interest.

---
## VAN EMDE BOAS TREE 

This tree supports all the typical dynamic access operations in $O(\log \log n)$ is built in a recursive way: each cluster of the structure is of this form:

```c++
struct vEB{
    int universe;
    int min;
    int max;
    vEB* summary;
    vEB** clusters;
}
```

So we have an universe representing the domain of the possible values stored, each vEB is divided in $\sqrt{universe}$ clusters stored in an array of pointers, each of dimension $\sqrt{universe}$. Each cluster also has a pointer to a summary of dimension $\sqrt{universe}$ that stores which children clusters are used. each cluster also holds its max and min relatively to the current cluster indexed from 0.

- **MAKE-VEB(u) $O(u)$**:
  Creates an empty vEB tree with universe size $u$. For large $u$, the structure is recursively built.

- **INSERT(x) $O(\log \log u)$**:
  - If empty: set both `min` and `max` to $x$.
  - If $x < \text{min}$, swap with `min`.
  - Recursively insert `LOW(x)` into cluster `HIGH(x)`.
  - If that cluster was previously empty, insert `HIGH(x)` into `summary`.

- **DELETE(x) $O(\log \log u)$**:
  - If `min == max`, set both to `NIL`.
  - If $u = 2$, set `min`/`max` based on the remaining value.
  - Otherwise:
    - If $x == \text{min}$, replace with the smallest value in the first non-empty cluster.
    - Recursively delete `LOW(x)` from `clusters[HIGH(x)]`.
    - If the cluster becomes empty, remove `HIGH(x)` from `summary`.

- **MEMBER(x) $O(\log \log u)$**:
  - Base case: $x = \text{min}$ or $x = \text{max}$.
  - Else: check `clusters[HIGH(x)]` for `LOW(x)`.

- **MINIMUM() / MAXIMUM() $O(1)$**:
  Return `min` / `max`.

- **SUCCESSOR(x) $O(\log \log u)$**:
  - If $x < \text{min}$, return `min`.
  - If there's a larger element in `clusters[HIGH(x)]`, recurse into that cluster.
  - Else, find the next non-empty cluster in `summary`, return its `min`.

- **PREDECESSOR(x) $O(\log \log u)$**:
  Similar logic to `SUCCESSOR`, but in reverse.

---
## MATRICES OPERATIONS 

### Linear systems of equations 

Probably the easiest way to solve one of those is **Gaussian elimination** but this would imply that given A, if you keep changing the vector b you would have to do the entire process anytime, thus the greatest idea to solve these system is to use LUP factorization, it is basically LU but you store a permutation P matrix whenever you swap two rows. Then you can use the factorization to solve any system with A as matrix. 

The second topic the book presents is demonstrating how inversion can be done in the same complexity of multiplication of matrices, this is a bit overkill and it is done with **Shur's complement**. 

The chapter ends with some properties of the definite positive matrices and then they are used for the method of minimum squares, a method used to interpolate n points into a polynomial of degree < n, of course this will be an approximation, it is used to work with small degree polynomials. 

>The chapter is mostly useless, the only thing you should learn about linear algebra's algorithms is: **Implementing Gaussian Elimination**, this can do basically everything you need in O($n^3$), the only other topic you should take a look is **Matrix exponentiation** on usaco guide. 