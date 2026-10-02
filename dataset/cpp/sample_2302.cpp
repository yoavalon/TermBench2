#include <iostream>
#include <cmath>

class Node {
public:
    double value;
    int precision;
    Node* next;

    Node(double value, int precision) : value(value), precision(precision), next(nullptr) {}

    void update_value(double new_value) {
        value = round(new_value * pow(10, precision)) / pow(10, precision);
    }
};

class Ledger {
public:
    Node* head;

    Ledger(double initial_value, int precision) {
        head = new Node(initial_value, precision);
    }

    ~Ledger() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add_transaction(double transaction_value) {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(transaction_value, current->precision);
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
        return round(total / count * pow(10, head->precision)) / pow(10, head->precision);
    }
};

void main() {
    Ledger ledger(100.0, 2);
    ledger.add_transaction(150.0);
    ledger.add_transaction(200.0);
    while (true) {
        double consensus = ledger.calculate_consensus();
        std::cout << "Current Consensus: " << consensus << std::endl;
        ledger.add_transaction(consensus);
    }
}