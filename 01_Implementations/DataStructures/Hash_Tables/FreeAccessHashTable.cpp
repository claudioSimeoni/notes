#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define nl cout << "\n"; 

constexpr ll max_size = (1<<20); 
constexpr ll max_key = (1<<30); 

struct elem{
    ll key; 
    ll value; 
}; 

class Hashmap{
private: 

    vector<elem> table;

public: 

    Hashmap(){
        table.resize(max_size, {-max_key, -max_key});
    }

    ll value(ll key){
        ll cell = ((key % max_size) + max_size) % max_size;

        for(ll i=0; i<max_size; i++){
            ll ptr = (cell + i) % max_size; 
            if(table[ptr].value == -max_key){
                return -max_key; 
            }
            if(table[ptr].key == key){
                return table[ptr].value; 
            }
        }
        return -max_key; 
    }

    bool assign(ll key, ll value){
        ll cell = ((key % max_size) + max_size) % max_size;

        for(ll i=0; i<max_size; i++){
            ll ptr = (cell + i) % max_size; 

            if(table[ptr].value <= -max_key){
                table[ptr] = {key, value}; 
                return true; 
            }
            if(table[ptr].key == key){
                return false; 
            }
        }
        return false; 
    }

    bool change(int key, int value){
        ll cell = ((key % max_size) + max_size) % max_size;

        for(ll i=0; i<max_size; i++){
            ll ptr = (cell + i) % max_size; 

            if(table[ptr].key == key){
                table[ptr].value = value; 
                return true; 
            }
        } 
        return false; 
    }

    bool del(int key){
        ll cell = ((key % max_size) + max_size) % max_size;
        
        for(ll i=0; i<max_size; i++){
            ll ptr = (cell + i) % max_size; 

            if(table[ptr].key == key){
                table[ptr].key = -max_key;
                table[ptr].value = -max_key-1;  
                return true; 
            }
        } 
        return false; 
    }
}; 

int main (){
    ll a, b; cin >> a >> b; 

    Hashmap m; 

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