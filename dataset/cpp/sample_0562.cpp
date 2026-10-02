#include <iostream>
#include <stdexcept>

class Node {
public:
    int id;
    int value;
    Node* next;

    Node(int id, int value) : id(id), value(value), next(nullptr) {}
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void append(int value) {
        Node* new_node = new Node(len() + 1, value);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    int len() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count += 1;
            current = current->next;
        }
        return count;
    }

    bool validate() const {
        Node* current = head;
        while (current != nullptr) {
            if (current->value < 0) {
                return false;
            }
            current = current->next;
        }
        return true;
    }
};

void simulate_consensus(Ledger& ledger) {
    while (true) {
        ledger.append(ledger.len() * 2);
        if (!ledger.validate()) {
            throw std::runtime_error("Validation failed");
        }
    }
}

int main() {
    Ledger ledger;
    try {
        simulate_consensus(ledger);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}