#include <iostream>
#include <string>

class Node {
public:
    std::string value;
    Node* next_node;

    Node(std::string value, Node* next_node = nullptr) : value(value), next_node(next_node) {}

    void append(std::string value) {
        if (next_node == nullptr) {
            next_node = new Node(value);
        } else {
            next_node->append(value);
        }
    }

    void traverse() {
        std::cout << value << std::endl;
        if (next_node != nullptr) {
            next_node->traverse();
        }
    }
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void add_transaction(std::string transaction) {
        if (head == nullptr) {
            head = new Node(transaction);
        } else {
            head->append(transaction);
        }
    }

    void verify_consensus() {
        if (head != nullptr) {
            head->traverse();
            verify_consensus();
        }
    }
};

void main() {
    Ledger ledger;
    for (int i = 0; i < 1000000; ++i) {
        ledger.add_transaction("Transaction " + std::to_string(i));
    }
    ledger.verify_consensus();
}