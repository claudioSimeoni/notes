#include <bits/stdc++.h> 
using namespace std; 
#define nl cout << "\n"; 

struct node{
    int key; 
    node* p; 
    node* l; 
    node* r; 
}; 

struct Bst{
    node* head; 

    Bst(vector<int>& v){
        head = nullptr;
        for(int i=0; i<v.size(); i++) insert(v[i]);  
    }

    bool insert(int val){
        node* n = new node; 
        n->key = val; n->l = nullptr; n->r = nullptr; n->p = nullptr; 
        node* ptr = head; 

        if(ptr == nullptr){
            head = n; 
            return true; 
        }

        while(true){
            if(ptr->key > val){
                if(ptr->l != nullptr) ptr = ptr->l;
                else{
                    n->p = ptr; 
                    ptr->l = n; 
                    return true; 
                }
            } 
            if(ptr->key < val){
                if(ptr->r != nullptr) ptr = ptr->r; 
                else{
                    n->p = ptr; 
                    ptr->r = n; 
                    return true;
                }
            } 
            if(ptr->key == val){
                delete n; 
                return false; 
            } 
        }
    }

    void inorder_tree_walk(node* n){
        if(!n) return; 
        inorder_tree_walk(n->l); 
        cout << n->key << " ";
        inorder_tree_walk(n->r);
    }  
    
    node* search_rec(int val, node* n){
        if(n == nullptr || n->key == val) return n; 
        if(n->key > val) return search_rec(val, n->l);
        if(n->key < val) return search_rec(val, n->r); 
    }

    node* search_it(int val){
        node* ptr = head; 
        while(ptr != nullptr && ptr->key != val){
            if(ptr->key > val) ptr = ptr->l;
            if(ptr->key < val) ptr = ptr->r; 
        }
        return ptr; 
    }

    node* max(node* ptr){
        while(ptr->r != nullptr) ptr = ptr->r; 
        return ptr; 
    }

    node* min(node* ptr){
        while(ptr->l != nullptr) ptr = ptr->l; 
        return ptr; 
    }

    node* succ(node* n){
        if(n->r != nullptr) return min(n->r); 
        node* parent = n->p; 
 
        while(parent != nullptr && parent->r == n){
            n = parent; 
            parent = parent->p; 
        }
        return parent; 
    }

    node* prec(node* n){
        if(n->l != nullptr) return max(n->l); 
        node* parent = n->p; 
 
        while(parent != nullptr && parent->l == n){
            n = parent; 
            parent = parent->l; 
        }
        return parent; 
    }

    void del(int val){
        node* n = search_it(val); 
        if(n->l == nullptr){
            transplant(n, n->r); 
        }
        else if(n->r == nullptr){
            transplant(n, n->l); 
        }
        else{
            node* newn = min(n->r); 
            if(newn != n->r){
                transplant(newn, newn->r);
                newn->r = n->r;
                newn->r->p = newn;  
            }
            transplant(n, newn); 
            newn->l = n->l; 
            newn->l->p = newn; 
        }

        delete n; 
    }

    // utility

    void transplant(node* a, node* b){
        if(a->p == nullptr) head = b; 
        else if(a->p->l == a) a->p->l = b;
        else if(a->p->r == a) a->p->r = b; 
    
        if(b != nullptr) b->p = a->p; 
    }

}; 

int main(){
    int n; cin >> n; 
    vector<int> v(n); 
    for(int i=0; i<n; i++) cin >> v[i]; 
}