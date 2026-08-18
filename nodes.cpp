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


    Node* insert = new Node;
    insert->value = 99.9;
    insert->next = first->next;
    first->next = insert;
   
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;  
    }

    // hand every house back
    delete first;
    delete second;
    delete third;

    return 0;
}