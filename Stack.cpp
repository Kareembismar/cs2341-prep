#include <iostream>

struct Node {
    double value;
    Node* next;
};

int main() {
    Node* head = nullptr;

    Node* n = new Node;
    n->value = 10;
    n->next  = head;
    head     = n;

    n = new Node;
    n->value = 20;
    n->next  = head;
    head     = n;

    n = new Node;
    n->value = 30;
    n->next  = head;
    head     = n;

    std::cout << "peek: " << head->value << "\n";

    Node* keep = head->next;
    delete head;
    head = keep;

    std::cout << "peek: " << head->value << "\n";

    Node* walker = head;
    while (walker != nullptr) {
        std::cout << walker->value << " ";
        walker = walker->next;
    }
    std::cout << "\n";

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    return 0;
}
