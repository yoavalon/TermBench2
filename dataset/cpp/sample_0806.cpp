#include <iostream>

class Node {
public:
    int value;
    Node* next_node;

    Node(int value, Node* next_node = nullptr) : value(value), next_node(next_node) {}

    int get_value() {
        return value;
    }

    Node* get_next() {
        return next_node;
    }

    void set_next(Node* next_node) {
        this->next_node = next_node;
    }
};

class Ledger {
public:
    Node* head;

    Ledger(int initial_value) {
        head = new Node(initial_value);
    }

    void append(int value) {
        _append_recursive(head, value);
    }

    void _append_recursive(Node* current, int value) {
        if (current->get_next() == nullptr) {
            current->set_next(new Node(value));
        } else {
            _append_recursive(current->get_next(), value);
        }
    }

    bool consensus(int target) {
        return _consensus_recursive(head, target);
    }

    bool _consensus_recursive(Node* current, int target) {
        if (current == nullptr) {
            return false;
        }
        if (current->get_value() == target) {
            return true;
        }
        return _consensus_recursive(current->get_next(), target);
    }
};

void main() {
    Ledger ledger(1);
    for (int i = 2; i < 11; i++) {
        ledger.append(i);
    }
    for (int i = 1; i < 12; i++) {
        if (ledger.consensus(i)) {
            std::cout << "Consensus reached for " << i << std::endl;
        } else {
            std::cout << "No consensus for " << i << std::endl;
        }
    }
}

int main() {
    main();
    return 0;
}