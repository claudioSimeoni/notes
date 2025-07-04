#include <bits/stdc++.h> 
using namespace std; 

struct Queue{
    int head; 
    int tail; 
    int size; 
    int max_size; 
    vector<int> q; 

    Queue(int max_size) : max_size(max_size){
        head = 0; 
        tail = 0; 
        size = 0; 
        q.resize(max_size); 
    }

    void enqueue(int k){
        if(size == max_size) throw std::overflow_error("Queue overflow"); 
        q[tail] = k; 
        tail = (tail + 1) % max_size; 
        size++; 
    }

    int dequeue(){
        if(!size) throw std::underflow_error("Queue undeflow"); 
        head = (head + 1) % max_size; 
        size--; 
        return q[(head-1+max_size) % max_size]; 
    }

    int front(){
        if(!size) throw std::underflow_error("Queue undeflow"); 
        return q[head]; 
    }

    bool empty(){
        if(!size) return true; 
        return false; 
    }
}; 

int main(){
    Queue q(5);  // Crea una coda con dimensione massima 5

    // Enqueue (inserire elementi)
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.front() << endl;  // Dovrebbe stampare 10

    // Dequeue (rimuovere un elemento)
    cout << "Dequeued: " << q.dequeue() << endl;  // Dovrebbe stampare 10
    cout << "Front element after dequeue: " << q.front() << endl;  // Dovrebbe stampare 20

    // Aggiungere più elementi
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // La coda ora dovrebbe essere piena

    // Provare a svuotare la coda
    while (!q.empty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    // Provare a fare dequeue su una coda vuota (dovrebbe lanciare un errore)
    cout << "Trying to dequeue from an empty queue..." << endl;
    cout << q.dequeue() << endl;  // Dovrebbe lanciare un'eccezione

    return 0;
}