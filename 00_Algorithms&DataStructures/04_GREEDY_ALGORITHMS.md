Greedy(goloso) is a general approach to problems which involves taking always the most convenient choice.

Some examples: 

- **Scheduling:** let's say I have some events with a starting moment x and an ending one y, and i want to insert as many as possible in a schedule, than the idea is to choose always the event that ends first.

- **Tasks and deadlines:** let's assume we have n task with a duration x and a deadline y and we earn or lose money according to the following rule, if a task has a deadline y and i end up concluding it at time k then i'll "earn" (y - k). I want to maximize my earnings, then the greedy approach is to always select the shorter task.

- **Minimizing sums:** given (a1, ... an) we want to minimize S = |a1-x| + ... |an-x| choosing an appropriate x, it turn's out that the best choice is always the median of the array. Instead regarding S = (a1-x)^2 + ... (an-x)^2 you just compute it with the derivative.

>**Huffman's algorithm** is a greedy algorithm to compress strings bit representation. You basically build a tree where each path is the bit representation of each character. To do this, firstly you count the occurrences of each character and you assign this values to each node in a priority queue and you always remove the two smallest elements, you build a new node with sum = s1 + s2 with children n1 and n2 and you insert the new node in the priority queue, you keep doing this until the queue is empty.