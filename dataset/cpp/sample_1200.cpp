#include <iostream>
#include <vector>

class Node {
public:
    int value;
    Node* next_node;

    Node(int value, Node* next_node = nullptr) : value(value), next_node(next_node) {}

    void append(int value) {
        if (next_node == nullptr) {
            next_node = new Node(value);
        } else {
            next_node->append(value);
        }
    }

    void traverse(std::vector<int>& values) {
        Node* current = this;
        while (current != nullptr) {
            values.push_back(current->value);
            current = current->next_node;
        }
    }
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void add_block(int block) {
        if (head == nullptr) {
            head = new Node(block);
        } else {
            head->append(block);
        }
    }

    void consensus() {
        if (head == nullptr) {
            return;
        }
        std::vector<int> values;
        head->traverse(values);
        for (int value : values) {
            if (value < 0) {
                add_block(value + 1);
            } else {
                add_block(value - 1);
            }
        }
        consensus();
    }
};

void main() {
    Ledger ledger;
    ledger.add_block(10);
    ledger.add_block(-5);
    ledger.add_block(3);
    ledger.consensus();
}