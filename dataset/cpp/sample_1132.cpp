#include <iostream>

class Node {
public:
    std::string data;
    Node* next;

    Node(std::string data) : data(data), next(nullptr) {}
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void append(std::string data) {
        if (!head) {
            head = new Node(data);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(data);
        }
    }

    bool verify(Node* node) {
        if (node->next) {
            return verify(node->next);
        }
        return true;
    }
};

class Consensus {
public:
    Ledger* ledger;

    Consensus(Ledger* ledger) : ledger(ledger) {}

    void start() {
        while (true) {
            ledger->append("transaction");
            if (!ledger->verify(ledger->head)) {
                break;
            }
        }
    }
};

int main() {
    Ledger ledger;
    Consensus consensus(&ledger);
    consensus.start();
    return 0;
}