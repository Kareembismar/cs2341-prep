#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main() {
    // three nodes on the heap, wired into a chain
    Node* head   = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third  = new Node{30, nullptr};
    head->next   = second;
    second->next = third;

    // splice: grab the chain first, then redirect
    Node* fresh = new Node{15, nullptr};
    fresh->next = head->next;
    head->next  = fresh;

    // walk and print — never move head
    Node* walker = head;
    while (walker != nullptr) {
        std::cout << walker->value << " ";
        walker = walker->next;
    }
    std::cout << "\n";

    // teardown: save, delete, hop
    Node* current = head;
    while (current != nullptr) {
        Node* keep = current->next;
        delete current;
        current = keep;
    }
    head = nullptr;

    return 0;
}