#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define nl cout << "\n"; 

constexpr ll max_size = (1<<20); 
constexpr ll max_key = (1<<30); 

// these variables are used as arguments of the universal hash 2 
ll uh1; 
ll uh2; 

struct elem{
    ll key; 
    ll value; 
}; 

class Hashmap{
private: 

    vector<vector<elem>> table;
    ll (*hash)(ll k); 
    
    public: 
    
    Hashmap(ll (*f)(ll)){
        table.resize(max_size);
        hash = f; 
    }

    ll value(ll key){
        ll cell = hash(key); 
        for(ll i=0; i<table[cell].size(); i++){
            if(table[cell][i].key == key){
                return table[cell][i].value; 
            }
        }
        return -max_key; 
    }

    void assign(ll key, ll value){
        ll cell = hash(key); 
        table[cell].push_back({key, value}); 
    }
}; 

ll proportion_hash(ll k){
    k = ((k % max_key) + max_key) % max_key;
    return (k * max_size / max_key) % max_size; 
}

ll division_hash(ll k){
    k = ((k % max_key) + max_key) % max_key;
    return k % max_size; 
}

ll multiplication_hash(ll k){
    // we need floor(m(kA mod 1)) A = s / 2^(maxbitk) with m=2^x
    k = ((k % max_key) + max_key) % max_key;

    ll s = max_key - 1; 
    ll module = k * s % max_key; 

    return module >> 10; 
}

ll universal_hash(ll k){
    k = ((k % max_key) + max_key) % max_key;
    
    k = uh1 * k % max_key; 
    k = (k + uh2) % max_key; 

    return k % max_size; 
}

int main (){
    ll a, b; cin >> a >> b; 

    // uh1 = rand() % max_key; 
    // uh2 = rand() % max_key; 

    Hashmap m(proportion_hash); 

    for(ll i=0; i<a; i++){
        ll x; cin >> x;
        ll val = m.value(b - x); 

        if(val != -max_key){
            cout << val << " " << i + 1 << "\n"; 
            return 0; 
        }

        m.assign(x, i + 1); 
    }

    cout << "IMPOSSIBLE\n"; 
} 