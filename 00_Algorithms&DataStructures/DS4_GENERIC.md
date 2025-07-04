## DSU (DISJOINT SET UNION) 

Here the idea is quite simple and it is just about building a struct that let us know if two elements of a graph are in the same component in O(log n) while updating the graph in O(log n). The idea is to store a tree for each component where the root of each of these trees is seen as the representative of that component, to check if two elements are in the same component we just follow the path from a node to its root and check if they are equal. 

Updating a and b with a new edge imply merging the representative nodes of a and b, you can both merge by **size** of the component or by **rank** (the height of the tree) but the second imply storing extra information and i think the first one is easier to implement. The GOATed idea here is path compression: whenever we use the function find() to find the representative of a node k we bring that node to his root thus decreasing the height of the tree, this results in an amortized complexity of O($\alpha$(n)) for each operation. Alpha is the inverse of the **Ackerman Function**, a function that grows extremely fast. 

**<span style="color:green">Road Construction</span>