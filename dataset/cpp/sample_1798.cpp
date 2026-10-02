#include <iostream>
#include <cstdlib>
#include <ctime>

class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
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

    bool verify_consensus() {
        Node* current = head;
        while (current) {
            if (!is_valid(current->value)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool is_valid(int value) {
        return value % 2 == 0;
    }
};

class ConsensusMechanism {
public:
    Ledger* ledger;
    ConsensusMechanism(Ledger* l) : ledger(l) {}

    void run() {
        while (true) {
            if (!ledger->verify_consensus()) {
                correct_mutation();
            }
            ledger->append(generate_new_value());
        }
    }

    void correct_mutation() {
        Node* current = ledger->head;
        while (current) {
            if (!ledger->is_valid(current->value)) {
                current->value = correct_value(current->value);
            }
            current = current->next;
        }
    }

    int generate_new_value() {
        return rand() % 101;
    }

    int correct_value(int value) {
        return value + 1;
    }
};

int main() {
    srand(time(0));
    Ledger ledger;
    ConsensusMechanism mechanism(&ledger);
    mechanism.run();
    return 0;
}