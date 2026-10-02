#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next = nullptr) : value(value), next(next) {}
};

class ConsensusMechanism {
public:
    Node* chain;

    ConsensusMechanism() : chain(nullptr) {}

    void append(int value) {
        if (!chain) {
            chain = new Node(value);
        } else {
            _append_helper(chain, value);
        }
    }

    void _append_helper(Node* current, int value) {
        if (!current->next) {
            current->next = new Node(value);
        } else {
            _append_helper(current->next, value);
        }
    }

    bool validate() {
        return _validate_helper(chain);
    }

    bool _validate_helper(Node* current) {
        if (!current) {
            return true;
        }
        if (current->next && current->value > current->next->value) {
            return false;
        }
        return _validate_helper(current->next);
    }
};

void main() {
    ConsensusMechanism mechanism;
    for (int i = 0; i < 10; ++i) {
        mechanism.append(i);
    }
    std::cout << mechanism.validate() << std::endl;
}