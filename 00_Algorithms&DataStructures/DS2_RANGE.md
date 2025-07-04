## PREFIX SUM

Prefix sum consists in precomputing in O(n) recursively the sum of each prefix of an array, thus allowing to easily compute the sum of a subarray in O(1). Be careful that if a query involves the first element you should remember that there is a "-1" element that has the value 0.

Prefix sum can be used also to compute the **maximum subarray sum**: you iterate through the prefixes and you keep the least one while updating the max as the difference between the current prefix and the least one. Another interesting way to approach the **maximum subarray sum** is by iterating through the original array and holding the current max in this way $sum = max(sum + arr[i], arr[i])$. 

Prefix sum can be used also on a grid and the following formula computes the sum of the elements of a rectangle of the grid: 

		$prefix[i][j] = ​prefix[i−1][j] + prefix[i][j−1] − prefix[i−1][j−1] + arr[i][j]​$. 
		
Note that you can still use the [[IMPLEMENTATION_TRICKS#The 1 -1 Trick]] but in the following way :

1 -1

-1 1

## SEGMENT TREE 

The **segment tree** is a tree-based data structure that is built in O(n * log n) that supports updating an element in O(log n) and range queries on **ASSOCIATIVE** merging functions (sum, min, max, gcd, lcm, bitwise operations ...) in O(log n).

Its structure is quite easy, each node stores the merge of the two children, the most practical way to implement it is using a 4 * n sized 1-indexed array.

**<span style="color: green">Dynamic Range Minimum Queries</span>**

## BIT (Binary index tree / Fenwick Tree)

The **Bit** is a data structure that is built in O(n * log n) that supports updating an element in O(log n) and range queries on both **ASSOCIATIVE** AND **INVERTIBLE** merging functions (sum, xor ...) in O(log n). 

It is typically preferred when dealing with those types of merging because it is easier to implement but it is actually less general and i usually prefer the segment. The idea behind it is that every cell of the array stores the sum of the previous 2 * k elements before it including itself, where k is the maximum power dividing the cell's index. The array is 1 indexed. 

**<span style="color: green">Dynamic Range Sum Queries</span>**

## SPARSE TABLE 

A **sparse table** is a **static** data structure that is built in O(n * log n) that supports range queries in O(1), it can only be used with **IDEMPOTENT** operations (it means that applying them more than once doesn't affect the result, such operations are min, max, gcd, lcm). 

The idea behind is that you store for each index i of the array, the sum of ranges starting from it with length 2 * k, these are log n ranges for each index and can be computed in O(n * log n) recursively. Now every range query can be computed in O(1) by merging two ranges, note that we can do so because of idempotence. 

*A cool thing is that you can build using a bit or a segment a weakened **Order statistic tree** (a ds that is like a set but supporting finding the position of an element and finding the ith element), the size N must be treatable. The first can be achieved by querying on a range, while the second one needs (log n) ^ 2 because you also binary search*