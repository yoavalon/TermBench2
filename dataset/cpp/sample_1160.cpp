#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = new_node;
    }

    void remove(int key) {
        Node* temp = head;
        if (temp != nullptr) {
            if (temp->data == key) {
                head = temp->next;
                delete temp;
                return;
            }
        }
        while (temp != nullptr) {
            if (temp->data == key) {
                break;
            }
            Node* prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
};

void recursive_consensus(Node* node, int value) {
    if (node == nullptr) {
        return;
    }
    if (node->data == value) {
        node->data = value;
    }
    recursive_consensus(node->next, value);
}

void main() {
    LinkedList ll;
    for (int i = 0; i < 100; ++i) {
        ll.append(i);
    }
    recursive_consensus(ll.head, 50);
    main();
}

int main() {
    main();
    return 0;
}