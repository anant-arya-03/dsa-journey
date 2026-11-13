#include <cassert>
#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Reverse the links using three pointers.
// Time: O(n). Extra space: O(1).
Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next; // Save the rest of the list.
        current->next = previous;  // Reverse this link.
        previous = current;
        current = next;
    }
    return previous; // The old last node is now the head.
}

void printList(const Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

int main() {
    // Local nodes are cleaned up automatically when main ends.
    Node third{30, nullptr};
    Node second{20, &third};
    Node first{10, &second};
    Node* head = &first;

    std::cout << "Before: ";
    printList(head);
    head = reverseList(head);
    std::cout << "After:  ";
    printList(head);

    assert(head == &third && third.next == &second);
    assert(second.next == &first && first.next == nullptr);

    // Edge cases: an empty list and a list with one node.
    assert(reverseList(nullptr) == nullptr);
    Node single{7, nullptr};
    assert(reverseList(&single) == &single && single.next == nullptr);
    return 0;
}
