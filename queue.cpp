#include <iostream>

struct Node
{
    double value;
    Node *next;
};

int main () {
    Node* front= nullptr;
    Node* back = nullptr;
    
    Node* n= new Node;
    n-> value = 10; 
    n-> next = nullptr;

    front = n;
    back = n;

    n = new Node;
    n-> value = 20;
    n->next = nullptr;

    back ->next = n;
    back = n;

    n = new Node;
    n-> value = 30;
    n-> next = nullptr;

    back ->next = n;
    back = n;

    std::cout<<front->value << '\n';

    Node* keep = front->next;
    delete front;
    front = keep;

    std::cout<<front->value << '\n';

    Node* walker = front;
    while (walker != nullptr) {
        std::cout << walker->value << " ";
        walker = walker->next;
    }
    std::cout << '\n';

    Node* current = front;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    front = nullptr;
    back = nullptr;

    return 0;
}