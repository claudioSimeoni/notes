#### How to think about recursion when implementing 

The idea you must have is the following: 
1. Check if you are at the end of the recursion and handle that situation. 
2. Do everything that must be done in the first phase of the recursion.
3. Call the recursion.
4. Do everything that must be done in the second phase of the recursion.

---
#### The 0 1 2 Trick 

The **0 1 2 trick** consists in keeping an array where 0 means not visited yet, 1 means currently on the stack, 2 means visited. It is extremely useful in graphs (in particular in directed ones) to detect cycles.

---
#### The 1 -1 Trick 

It is used to see how many layers overlap where layers could be both 2 or 3 d, you simply insert a 1 where the layer starts and a -1 at the end and then you range query to see how many layers overlap in a certain position. **<span style="color: green">Restaurant Customers</span>**

---
#### Repetition&Playlist from CSES 

- This is the best way to count the sizes of the blocks with equal length. **<span style="color: green">Repetitions</span>**

```c++
int main(){
	string s; cin >> s;
	int ct = 1; int mx = 1;
	for(int i=1; i<s.size(); i++){
		if(s[i] != s[i-1]){
			ct = 1;
			continue;
		}
		ct++;
	}
}
```

- Instead regarding finding the maximum subarray with distinct elements the idea is to store in a set the current elements and as soon as we find an element we already have we move a pointer on the left until we reach that duplicate element. **<span style="color: green">Playlist</span>**

---
> The best way to implement prefix sum it is with index translated by one so that the first cell has a 0 inside. 