*Here i will integrate much with usaco guide and cp handbook* 
#### Cross product's applications 

- The first thing both books present is the usefulness of the **cross product** when trying to understand the **relative position of a vector respect to another**, in fact $a * b$ is positive only if b can be obtained by rotating clockwise a, if the product is negative the opposite holds. 
**<span style="color:green">Point Location Test</span>**

- Secondly you can find out **if two segments intersect** by doing the first procedure for both segments, in fact if they intersect then both of point a and b for example must lie on different sides of the other segment.
**<span style="color: green">Line Segment Intersection</span>**

- Another application is finding the **distance of a point from a segment**, in fact you can easily compute the area of the triangle identified by those vertices and then divide by the length of the segment. 

#### Interesting facts (from cph)

- To check if a point is inside a polygon you can send a "ray" from that point to any direction and check how many times you intersect a point on the perimeter of the polygon, if this number is odd then you are inside, on the contrary if it is even you are not. 
  
**<span style="color: green">Point in Polygon</span>**

- Given a set of points that identify a **polygon its area** is found with **shoelace formula**: 
$$
\text{Area} = \frac{1}{2} \left| \sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i) \right|
$$
**<span style="color: green">Polygon area</span>**

- Then we have **Pick's theorem**: the area of a polygon provided
that all vertices of the polygon have integer coordinates is: $a + b/2 − 1$, where a is the number of integer points inside the polygon and b is the number of integer points on the boundary of the polygon.

**<span style="color: green">Polygon Lattice points</span>**

- The last interesting trick can be used to find out the maximum Manhattan distance between two points in a set of n points, you use a coordinate transformation: it is a sort of rotation of the plane with a scalar multiplication $(x, y) \rightarrow (x + y, y - x)$ and then you basically reduced to the problem of finding the maximum between all points couples $max(\left|x_i - x_j\right| , \left|y_i - y_j\right|)$.
