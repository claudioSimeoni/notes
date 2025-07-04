## BITWISE OPERATIONS

- The formula `~x = −x − 1` holds.

- Note that `x << k` corresponds to multiplying `x` by $2^k$, and `x >> k` corresponds to dividing `x` by $2^k$ rounded down to an integer.

- The k-th bit of a number is one exactly when `x & (1 << k)` is not zero.

- It is also possible to modify single bits of numbers using similar ideas. For example, the formula `x | (1 << k)` sets the k-th bit of `x` to one, the formula `x & ~(1 << k)` sets the k-th bit of `x` to zero, and the formula `x ^ (1 << k)` inverts the k-th bit of `x`.

- The formula `x & (x − 1)` sets the last one bit of `x` to zero, and the formula `x & −x` sets all the one bits to zero, except for the last one bit. The formula `x | (x − 1)` inverts all the bits after the last one bit. Also note that a positive number `x` is a power of two exactly when `x & (x − 1) = 0`. A great property of the xor is that it is it's own inverse: `x^x = 0`. To compute the greatest power of two that divides `x` we can use `x&-x`.

#### Randomic Equalities

- a|b = a⊕b + a&b
- a⊕(a&b) = (a|b)⊕b
- b⊕(a&b) = (a|b)⊕a
- (a&b)⊕(a|b) = a⊕b

Addition:

- a+b = a|b + a&b
- a+b = a⊕b + 2(a&b)

Subtraction:

- a-b = (a⊕(a&b))-((a|b)⊕a)
- a-b = ((a|b)⊕b)-((a|b)⊕a)
- a-b = (a⊕(a&b))-(b⊕(a&b))
- a-b = ((a|b)⊕b)-(b⊕(a&b))

--- 
## COORDINATE COMPRESSION 

When dealing with big numbers and we just care about the relative order of this number, to keep a low complexity we might want to compress the coordinates, this can be easily done by using a vector and then sorting it, then we can use the indices of the array to find out the i-th number and we can use a map to store the index of each number. 