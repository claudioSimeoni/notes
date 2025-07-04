#include <bits/stdc++.h> 
using namespace std; 

struct elem{
    int key; 
    elem* next; 
    elem* prev; 

    elem(int val) : key(val), next(nullptr), prev(nullptr){}; 
}; 

// This is a doubly linked list, if you want to make it circular to simplify some implementation you can easily use instead of 
// head and tail a single elem* named sentinel that is a fake node used to track if we reach the end or the start of the list.
// At the beginning sentinel's prev and next are both pointing to sentinel. 

struct List{
    elem* head;
    elem* tail; 

    List() : head(nullptr), tail(nullptr){}; 

    ~List(){
        while(head != nullptr){
            pop_front(); 
        }
    }

    void push_front(int k){
        elem* new_elem = new elem(k); 

        if(!head) head = tail = new_elem; 
        else{
            head->prev = new_elem; 
            new_elem->next = head; 
            head = new_elem; 
        }
    }

    void push_back(int k){
        elem* new_elem = new elem(k); 

        if(!tail) tail = head = new_elem; 
        else{
            tail->next = new_elem; 
            new_elem->prev = tail; 
            tail = new_elem; 
        }
    }

    void pop_front(){
        if(!head) return; 
        elem* temp = head; 
        head = head->next; 
        if(head) head->prev = nullptr; 
        else tail = nullptr; 
        delete temp; 
    }

    void pop_back(){
        if(!tail) return; 
        elem* temp = tail; 
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr; 
        delete temp; 
    }

    void remove(int k){
        elem* ptr = search(k); 
        if(ptr == nullptr) return; 

        if(ptr == head) pop_front(); 
        else if(ptr == tail) pop_back(); 
        else{
            ptr->prev->next = ptr->next; 
            ptr->next->prev = ptr->prev; 
            delete ptr; 
        }
    }

    elem* search(int k){
        elem* ptr = head; 
        while(ptr != nullptr && ptr->key != k) ptr = ptr->next; 
        return ptr; 
    }

    void print_forward(){
        elem* ptr = head; 
        while(ptr != nullptr){
            cout << ptr->key << " "; 
            ptr = ptr->next; 
        } 
        cout << endl; 
    }
     
    void print_backward(){
        elem* ptr = tail; 
        while(ptr != nullptr){
            cout << ptr->key << " "; 
            ptr = ptr->prev; 
        } 
        cout << endl; 
    }
}; 

int main() {
    List dll;

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_front(5);

    cout << "Lista in avanti: ";
    dll.print_forward();

    cout << "Lista all'indietro: ";
    dll.print_backward();

    dll.pop_front();
    cout << "Dopo pop_front(): ";
    dll.print_forward();

    dll.pop_back();
    cout << "Dopo pop_back(): ";
    dll.print_forward();

    dll.remove(20);
    cout << "Dopo rimozione di 20: ";
    dll.print_forward();

    return 0;
}
