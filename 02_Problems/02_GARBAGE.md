#### [Hungry games ~CF1600](https://codeforces.com/contest/1994)

Basically dp from the back and upper_bound on prefix sum.

#### [Funny games ~CF1900](https://codeforces.com/contest/1994)

The core idea is that if you are building a tree over n nodes little by little, you always want to connect two nodes from different components. Here performing the operations in the reverse order guarantees by pigeonhole principle that we always have two nodes from different connected components with the same congruence mod x. 

#### [Neo's Escape ~CF1500](https://codeforces.com/contest/2108/problem/C)

Cool, simply notice that once you divide in subsegments you need to put the clone on the highest element and it will only reach stuff that is decreasing from them.

#### [Apple Tree Traversing ~CF2100](https://codeforces.com/contest/2107/problem/D)

This problem has actually a quite simple greedy approach, the fact that makes it quite cool is how to compute that the actual complexity is $O(n\sqrt n)$ and the recursive idea behind it. 

#### [Smilo and Minecraft ~CF1700](https://codeforces.com/contest/2113/problem/C)

Such a simple problem but quite nice because it is solved by such a smart idea. 

#### [Minimize Fixed Points ~CF1700](https://codeforces.com/contest/2123/problem/F)

A good idea here to use a cycle decomposition, a permutation can be divided into cycles and here the idea is to group numbers based on their greatest prime divisors. 

#### [Matrix game ~CF1800](https://codeforces.com/contest/2120/problem/D)

Nice but remember when you want the lexicographically smaller to be greedy. 

#### [Minimize the Difference](https://codeforces.com/contest/2013/problem/D)

Nice problem, once you find out how to bound min and max you are guaranteed that you can play it optimally so that you reach max - min. 