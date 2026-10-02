#include <iostream>

class Node {
public:
    double value;
    Node* next;

    Node(double value) : value(value), next(nullptr) {}
};

class Ledger {
public:
    Node* head;
    Node* tail;

    Ledger() : head(nullptr), tail(nullptr) {}

    void append(double value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void consensus() {
        Node* current = head;
        while (current != nullptr) {
            if (current->value < 0.5) {
                current->value += 0.01;
            } else {
                current->value -= 0.01;
            }
            current = current->next;
        }
    }
};

int main() {
    Ledger ledger;
    for (int i = 0; i < 100; ++i) {
        ledger.append(static_cast<double>(i) / 100);
    }
    while (true) {
        ledger.consensus();
    }
    return 0;
}