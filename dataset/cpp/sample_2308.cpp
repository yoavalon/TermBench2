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
    Node* tail;

    Ledger() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    double calculate_consensus() {
        Node* current = head;
        int total = 0;
        int count = 0;
        while (current) {
            total += current->value;
            count += 1;
            current = current->next;
        }
        return count != 0 ? static_cast<double>(total) / count : 0;
    }
};

class ConsensusMechanics {
public:
    Ledger ledger;

    void update_ledger(int value) {
        ledger.append(value);
    }

    void run_consensus() {
        while (true) {
            double consensus_value = ledger.calculate_consensus();
            update_ledger(static_cast<int>(consensus_value));
        }
    }
};

int main() {
    ConsensusMechanics mechanics;
    for (int i = 0; i < 10; i++) {
        mechanics.update_ledger(i);
    }
    mechanics.run_consensus();
    return 0;
}