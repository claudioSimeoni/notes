## TRIE

A **trie** is used to store a dictionary of strings and is useful because you can tell if a certain prefix of a string is present in the dictionary in $O(pref.length())$, additionally you can also store some useful information in every node of the trie such as how many strings have that prefix. Here each node is a word and `trie[node][letter]` is the node of the word 'word' + 'letter'. [Shorten the Array](https://codeforces.com/contest/2093/problem/G), [Yasya and the Mysterious Tree](https://codeforces.com/problemset/problem/1980/G)

```c++
void insert(string s, vector<vector<int>>& trie, vector<bool>& stop, int& curr_node){
	int node = 0;
	for(auto ch: s){
		if(trie[node][ch] == -1) trie[node][dig] = curr_node++;
		node = trie[node][ch];
	}
	// the stop node is the one that stores the word s
	stop[node] = 1;
}
```
