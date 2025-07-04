#include <bits/stdc++.h> 
using namespace std; 

constexpr int inf = 1e9; 

void insert(int x, vector<array<int, 2>>& trie, vector<bool>& stop, int& curr_node, vector<int>& maxind, int ind){
    int node = 0; 
    for(int i=31; i>=0; i--){
        int dig = (x >> i) & 1; 
        if(trie[node][dig] == -1) trie[node][dig] = curr_node++; 
        node = trie[node][dig]; 
        maxind[node] = ind; 
    }

    // the stop node is the one that stores the number x 
    stop[node] = 1; 
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> v(n); 
        for(int i=0; i<n; i++) cin >> v[i]; 
        
        if(k == 0){
            cout << 1 << "\n"; 
            continue; 
        }

        vector<array<int, 2>> trie(64 * n, {-1, -1}); 
        vector<bool> stop(64 * n); 
        vector<int> maxind(64 * n, -inf); 

        int curr_node = 1; 
        int ans = inf; 

        for(int i=0; i<n; i++){
            int x = v[i]; 
            int node = 0; 
            
            for(int j=31; j>=0; j--){
                int xbit = (x >> j) & 1; 
                int kbit = (k >> j) & 1; 

                if(kbit){
                    node = trie[node][xbit ^ 1]; 
                    if(node == -1) break; 
                }
                else{
                    if(trie[node][xbit ^ 1] == -1){
                        if(trie[node][xbit] == -1) break; 
                        node = trie[node][xbit]; 
                    }
                    else{
                        ans = min(ans, i + 1 - maxind[trie[node][xbit ^ 1]]); 
                        if(trie[node][xbit] == -1) break; 
                        node = trie[node][xbit]; 
                    }
                    
                }
                if(stop[node]){
                    ans = min(ans, i + 1 - maxind[node]); 
                }

            }

            node = 0; 
            insert(x, trie, stop, curr_node, maxind, i); 
        }

        if(ans >= inf) cout << -1 << "\n"; 
        else cout << ans << "\n"; 

    }
}


// This problem made me learn a new ds called a trie, this ds is used to store a dictionary of strings and is useful because you can tell
// if a certain prefix of a string is present in the dictionary in O(pref.length()), additionally you can also store some useful information
// in every node of the trie such as how many strings have that prefix.