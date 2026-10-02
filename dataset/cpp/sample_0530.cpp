#include <iostream>
#include <vector>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class ConsensusMechanism {
public:
    Node* head;

    ConsensusMechanism() : head(nullptr) {}

    void add_node(int value) {
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

    bool validate_chain() {
        Node* current = head;
        while (current) {
            if (!verify_node(current)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool verify_node(Node* node) {
        return node->value > 0;
    }
};

class Network {
public:
    std::vector<ConsensusMechanism*> nodes;

    void add_consensus_mechanism(ConsensusMechanism* mechanism) {
        nodes.push_back(mechanism);
    }

    void simulate() {
        while (true) {
            for (ConsensusMechanism* mechanism : nodes) {
                if (!mechanism->validate_chain()) {
                    repair_chain(mechanism);
                }
            }
        }
    }

    void repair_chain(ConsensusMechanism* mechanism) {
        Node* current = mechanism->head;
        while (current) {
            if (!mechanism->verify_node(current)) {
                current->value = 1;
            }
            current = current->next;
        }
    }
};

int main() {
    Network network;
    ConsensusMechanism mechanism;
    mechanism.add_node(1);
    mechanism.add_node(-1);
    mechanism.add_node(2);
    network.add_consensus_mechanism(&mechanism);
    network.simulate();
    return 0;
}