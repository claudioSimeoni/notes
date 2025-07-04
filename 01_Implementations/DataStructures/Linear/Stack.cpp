#include <bits/stdc++.h> 
using namespace std; 

struct Stack{
    int end; 
    vector<int> st; 

    Stack(int max_dim){
        end = -1; 
        st.resize(max_dim); 
    }

    bool empty(){
        if(end == -1) return true; 
        return false; 
    }

    void push(int a){
        if(end == st.size()-1) throw std::overflow_error("Stack Overflow"); 
        end++; 
        st[end] = a; 
    }

    int pop(){
        if(empty()) throw std::underflow_error("Stack Underflow");
        end--; 
        return st[end + 1]; 
    }

    int top(){
        if(empty()) throw std::underflow_error("Stack Underflow"); 
        return st[end]; 
    }
}; 

int main() {
    Stack s(5);  // Crea uno stack con dimensione massima 5

    // Push (inserire elementi)
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl;  // Dovrebbe stampare 30

    // Pop (rimuovere un elemento)
    cout << "Popped: " << s.pop() << endl;  // Dovrebbe stampare 30
    cout << "Top element after pop: " << s.top() << endl;  // Dovrebbe stampare 20

    // Aggiungere più elementi
    s.push(40);
    s.push(50);
    s.push(60);  // Lo stack ora dovrebbe essere pieno

    // Provare a svuotare lo stack
    while (!s.empty()) {
        cout << "Popped: " << s.pop() << endl;
    }

    // Provare a fare pop su uno stack vuoto (dovrebbe lanciare un errore)
    cout << "Trying to pop from an empty stack..." << endl;
    cout << s.pop() << endl;  // Dovrebbe lanciare un'eccezione

    return 0;
}