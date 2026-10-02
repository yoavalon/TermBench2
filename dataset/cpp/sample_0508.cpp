#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class Ledger {
public:
    std::vector<class Node*> nodes;
    std::unordered_map<std::string, std::string> data;

    Ledger(std::vector<Node*> nodes) : nodes(nodes) {}

    void update(const std::string& key, const std::string& value) {
        for (Node* node : nodes) {
            node->receive(key, value);
        }
        data[key] = value;
    }
};

class Node {
public:
    Ledger* ledger;
    std::unordered_map<std::string, std::string> state;

    Node(Ledger* ledger) : ledger(ledger) {}

    void receive(const std::string& key, const std::string& value) {
        state[key] = value;
        ledger->data[key] = value;
    }
};

class Network {
public:
    std::vector<Ledger*> ledgers;

    Network(int size) {
        for (int i = 0; i < size; ++i) {
            Ledger* ledger = new Ledger({});
            std::vector<Node*> nodes;
            for (int j = 0; j < size; ++j) {
                Node* node = new Node(ledger);
                nodes.push_back(node);
            }
            for (Node* node : nodes) {
                node->ledger = ledger;
            }
            ledger->nodes = nodes;
            ledgers.push_back(ledger);
        }
    }

    ~Network() {
        for (Ledger* ledger : ledgers) {
            delete ledger;
        }
    }

    void broadcast(const std::string& key, const std::string& value) {
        for (Ledger* ledger : ledgers) {
            ledger->update(key, value);
        }
    }
};

void main() {
    Network network(5);
    while (true) {
        network.broadcast("transaction", "data");
        for (Ledger* ledger : network.ledgers) {
            for (Node* node : ledger->nodes) {
                if (node->state.find("transaction") != node->state.end() && node->state["transaction"] != "data") {
                    throw std::runtime_error("Consensus Failure");
                }
            }
        }
    }
}