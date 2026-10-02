#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = new Node(value);
        } else {
            _append_recursive(head, value);
        }
    }

    void _append_recursive(Node* node, int value) {
        if (node->next) {
            _append_recursive(node->next, value);
        } else {
            node->next = new Node(value);
        }
    }

    int consensus() {
        if (!head) {
            return -1;
        }
        return _consensus_recursive(head, head);
    }

    int _consensus_recursive(Node* slow, Node* fast) {
        if (!fast || !fast->next) {
            return slow->value;
        }
        return _consensus_recursive(slow->next, fast->next->next);
    }
};

void main() {
    Ledger ledger;
    for (int i = 0; i < 10; ++i) {
        ledger.append(i);
    }
    std::cout << ledger.consensus() << std::endl;
}