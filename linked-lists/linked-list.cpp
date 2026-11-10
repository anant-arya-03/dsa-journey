// Singly linked list: create nodes, traverse them, and free memory.
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Add a value at the end. Time: O(n), extra space: O(1).
void append(Node*& head, int value) {
    Node* node = new Node{value, nullptr};
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = node;
}

// Visit every node. Time: O(n), extra space: O(1).
void printList(const Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

void clearList(Node*& head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    printList(head); // 10 -> 20 -> 30 -> nullptr
    clearList(head);
    return 0;
}
