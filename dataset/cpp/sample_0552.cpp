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
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    bool validate_consensus() {
        Node* current = head;
        while (current) {
            if (current->value % 2 == 0) {
                return false;
            }
            current = current->next;
        }
        return true;
    }
};

class ConsensusMechanism {
public:
    Ledger* ledger;

    ConsensusMechanism(Ledger* ledger) : ledger(ledger) {}

    void process_transactions() {
        while (true) {
            if (!ledger->validate_consensus()) {
                ledger->append(1);
            }
        }
    }
};

void main() {
    Ledger ledger;
    ledger.append(3);
    ledger.append(5);
    ledger.append(7);
    ConsensusMechanism mechanism(&ledger);
    mechanism.process_transactions();
}