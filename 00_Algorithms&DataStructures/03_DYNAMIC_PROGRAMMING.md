**Dynamic Programming** is basically recursion but storing the results to avoid redundant computation (**Memoization**). You should recall dp when dealing with the following types of problems: 

- **Finding an optimal solution**: We want to find a solution that is as large as possible or as small as possible.

- **Counting the number of solutions**: We want to calculate the total number of possible solutions.

---

## Knapsack  

These type of problems generally involve filling a limited container with a subset of items where we want to count or optimize some quantity associated with the items. Almost every time, you can think of each item as having a positive weight, and the total weight of the items we choose must not exceed the capacity of the container, which is some number. Some variations of knapsack-type problems include:

Counting **how many sequences** of items will fill the container completely, meaning the total weight is exactly the capacity of the  container (the order may or may not matter): 

- You might want to compute how many **ordered** of these sequences fill the container. **<span style="color: palegreen">Dice Combinations, Coin Combinations I</span>**. Or how many **unordered** of them do. **<span style="color: palegreen">Coin Combinations II</span>**.

The **0/1 Knapsack problem:** Choosing a subset of items such that we maximize their total value and their total weight does not exceed the capacity of the container. **<span style="color: palegreen">Book Shop</span>**. Or choosing a minimal subset of items that fill the container. **<span style="color: palegreen">Minimizing Coins</span>**.
  
Finding **all the possible total weights** that we can achieve from any subset of items such that their total weight does not exceed the capacity of the container (in the chapter of CPH linked above). **<span style="color: palegreen">Money Sums</span>**.

---

## Paths on Grids 

A common type of DP Problems involves a 2D grid of square cells (like graph paper), and we have to analyze "paths". Using dp we can easily compute the number of all the possible paths or any quantity along all the paths **<span style="color: palegreen">Grid Paths</span>**. The cool thing is you can use the exact same principle to compute the **longest common subsequence** of two strings, and to find out the edit distance of two arrays **<span style="color: palegreen">Edit Distance</span>**. 

---

## LIS (Longest Increasing Subsequence)

The LIS can be easily found in O(n ^ 2) using dp, furthermore we can apply some procedures to improve to O(n * log n). 

- The first idea is to go through the array from the left and store a set with the elements visited, if the current element is x, we substitute s.upper_bound(x) with x.
- The second idea is to use RMQ to query the maximum of the previous dp achieved until now. 

In all these cases we can reconstruct the lis by simply storing a parents array. 

---

## Other common ideas

- **Range Dp** problems involve computing something on a range of an array, the classical recursion involves sliding along all the prefix-suffix combinations for a total complexity of O(n ^ 3). The classical example of this problem is the **matrices multiplication** idea where we want to decide the most convenient order to multiply a set of ordered matrices.

- **Digit Dp** problems involve computing something about digits in a range of numbers that usually is really wide and instead of doing a dp on numbers themselves we do so on their digits, thus scaling the factor from 10 ^ dig to around dig ^ 2.  
