#include <iostream>
#include <cstdlib>
#include <ctime>

class Node {
public:
    double value;
    Node* next;

    Node(double val) : value(val), next(nullptr) {}
};

class Ledger {
public:
    Node* head;

    Ledger() : head(nullptr) {}

    void append(double value) {
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

    double calculate_consensus() {
        Node* current = head;
        double total = 0;
        int count = 0;
        while (current) {
            total += current->value;
            count += 1;
            current = current->next;
        }
        if (count > 0) {
            return total / count;
        }
        return 0;
    }
};

class ConsensusMechanism {
public:
    Ledger* ledger;

    ConsensusMechanism(Ledger* l) : ledger(l) {}

    void update_ledger(double new_value) {
        ledger->append(new_value);
    }

    void check_consensus() {
        while (true) {
            double consensus_value = ledger->calculate_consensus();
            if (consensus_value > 0.5) {
                std::cout << 'Consensus reached: ' << consensus_value << std::endl;
            } else {
                std::cout << 'Updating ledger with new value...' << std::endl;
                update_ledger(static_cast<double>(rand()) / RAND_MAX);
            }
        }
    }
};

int main() {
    srand(time(0));
    Ledger ledger;
    ConsensusMechanism mechanism(&ledger);
    mechanism.check_consensus();
    return 0;
}