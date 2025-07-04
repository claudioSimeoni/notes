#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll; 

// This function computes in O(sqrt(n)) if n is prime.
bool prime(int n){
    if(n < 2) return false; 
    for(int i=2; i*i <= n; i++){
        if(n % i == 0) return false; 
    }
    return true; 
}

// This one finds the **prime factorization** of n in O(sqrt(n)).
map<int, int> factorization(int n, map<int, int> m){
    for(int i=2; i*i<= n; i++){
        while(n % i == 0){
            n /= i; 
            m[i]++; 
        }
    }
    if(n > 1) m[n]++;
    return m;  
}

// This is the Sieve of Eratosthenes
vector<int> sieve(int n){
    vector<int> v(n+1); 
    for(int i=2; i<=n; i++){
        if(v[i]) continue; 
        for(int j=2*i; j<=n; j+=i){     // Note that you could also start from i*i
            v[j] = i;  
        }
    }
    return v; 
}

// This algorithm computes the GCD of a, b. Obviously to compute the mcm you do a*b/(a,b).
int gcd(int a, int b){
    if(b == 0) return a; 
    return gcd(b, a % b); 
}

// This algorithm is called binary exponentiation and computes x to the power of y mod m in O(logy).
ll fexp(ll x, ll y, ll m){
    if(y == 0) return 1; 
    if(y % 2 == 1){
        return (x * fexp(x, y-1, m)) % m; 
    }
    ll k = fexp(x, y/2, m);
    return (k*k) % m;  // here is fundamental to create a variable to store the result of fexp(x, y/2) otherwise the function
}                      // would be called two times creating a complexity of O(y).

// The phi can be used to easily compute the inverse of x mod m, in fact with **Euler's theorem** x^phi(m) = 1 mod m we deduce 
// 1/x = x^(phi(m) - 1) mod m (if m is prime the theorem is called little fermat's theorem).
int phi(int n){
    int ret = n; 
    for(int i=2; i*i<=n; i++){
        if(n % i == 0){
            ret -= ret/i; 
            while(n % i == 0){
                n /= i; 
            }
        }
    }
    if(n > 1) ret -= ret/n; 
    return ret; 
}

// This is the precomputation with Sieve of Eratosthenes
void precomputephi(int n){
    vector<int> phi(n+1); 
    for(int i=0; i<n+1; i++) phi[i] = i; 
    for(int i=2; i*i<=n; i++){
        if(phi[i] == i){
            for(int j=i; j<=n; j+=i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
}

// To see why this works see usaco, basically it is a recursive way to precompute each modular inverse until m mod m.
void modinv(int m){
    vector<int> inv(m); 
    inv[1] = 1; 
    for(int i=2; i<m; i++) inv[i] = (m - ((m/i) * inv[m % i])) % m; 
}

// Another interesting thing is that you can bollire forte and use chinese remainder theorem 













































































































// int main(){
//     vector<int> k = sieve(20); 
//     for(int i=0; i<21; i++){
//         cout << k[i] << " "; 
//     }
// }
