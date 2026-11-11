# Linked lists

A place for my linked list practice and notes. Add new solutions here with a clear name, like `reverse-linked-list.cpp` or `delete-node-notes.md`.

## Start here

[linked-list.cpp](linked-list.cpp) is a small singly linked list example. It adds values at the end, prints the list, and frees the allocated memory.

With g++ installed, run these commands from the repository root in a Linux or macOS terminal:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic linked-lists/linked-list.cpp -o /tmp/dsa-linked-list
/tmp/dsa-linked-list
```

Expected output:

```text
10 -> 20 -> 30 -> nullptr
```

## Things to remember

- `head` points to the first node; an empty list has `head == nullptr`.
- Each node stores a value and a pointer to the next node.
- Check for `nullptr` before accessing a node.
- Save the next pointer before deleting the current node.
- In this example, appending takes O(n) time because it walks to the end.

## Ideas to practice next

- Insert at the beginning.
- Delete a node by value.
- Reverse the list.
- Find the middle with slow and fast pointers.

[Back to my DSA journey](../README.md)
