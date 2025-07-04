#### User-defined comparator 

```c++
struct comp{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{}; 
}; // all the const are fundamental 

set<pair<int, int>, comp>; 
```

--- 
To transform a generic type to a string you can use the **string** function to_string(). 

--- 
#### Order-statistic-tree

```c++
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>

using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<int> t;
t.insert(10);
t.insert(20);
t.insert(30);
t.erase(x); 

cout << *t.find_by_order(1) << "\n"; // 20
cout << t.order_of_key(25) << "\n";  // 2 (10, 20)
```
--- 
If a thing that shouldn't do tle does tle, maybe you just need to swap the indices of the nested loop. 

--- 
robe di approssimazione log2 etc 