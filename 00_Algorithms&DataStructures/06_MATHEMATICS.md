## NUMBER THEORY 

#### Primes and Phi 

Primes factorization can be done in $O(sqrt(n))$ clearly. **<span style="color:green">Counting Divisors</span>**

Another fantastic idea is to use **sieve of Erathostenes**: this can efficiently precompute any property that involves prime numbers in O(n log n). Namely checking if a number is prime, building its factorization storing the previous factor in each cell and then querying in O(log n). 

The exact two methods can be used for computing $\phi(n)$, both for a single number and precomputing.

#### Fexp 

You can compute every power k of a number n in O(log k) by using the recursive idea of fexp. This allows to find modular inverses by using Euler-Fermat theorem. **<span style="color:green">Exponentiation</span>** To precompute inverses mod p in O(log p) we can use a recursion with Euclidean division. 


#### Euclid for GCD

Firstly we can build an easy recursion to find the **GCD**, this has complexity O(log n) because each number can be bounded by one of the numbers of Fibonacci series. The **LCM** clearly is a * b / GCD. 

Secondly you can use the same idea to compute the coefficients x y in the formula ax + by = d by building a function that returns d, x, y for each call, this can be also written recursively. 

## COMBINATORICS ❌