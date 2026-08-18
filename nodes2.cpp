#include <iostream>

struct Node {
    double value;
    Node* next;      
};

int main() {
    
    Node* first  = new Node;
    Node* second = new Node;
    Node* third  = new Node;

    first->value  = 100.0;
    second->value = 102.5;
    third->value  = 101.0;

    
    first->next  = second;
    second->next = third;
    third->next  = nullptr;   

    // --- insert 99.9 between first and second ---
    Node* inserted = new Node;       // 1. new house on the heap
    inserted->value = 99.9;
    inserted->next = first->next;    // 2. new node grabs the chain FIRST
    first->next = inserted;          // 3. THEN first points at the new node

    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;  
    }

    // hand every house back, one at a time, walking the chain
    current = first;
    while (current != nullptr) {
        Node* nextNode = current->next;  // 1. save the address BEFORE it's gone
        delete current;                  // 2. free the current house
        current = nextNode;              // 3. hop using the saved address
    }

    return 0;
}