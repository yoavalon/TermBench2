#include <iostream>
#include <vector>
#include <numeric>

class Node {
public:
    int id;
    int state;
    std::vector<Node*> neighbors;

    Node(int id, int state) : id(id), state(state) {}

    void add_neighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

class Network {
public:
    std::vector<Node*> nodes;

    void add_node(Node* node) {
        nodes.push_back(node);
    }

    void update_states() {
        for (Node* node : nodes) {
            int sum = 0;
            for (Node* neighbor : node->neighbors) {
                sum += neighbor->state;
            }
            node->state = sum / node->neighbors.size();
        }
    }
};

class ConsensusMechanism {
public:
    Network* network;

    ConsensusMechanism(Network* network) : network(network) {}

    void simulate() {
        while (true) {
            network->update_states();
        }
    }
};

int main() {
    Network network;
    std::vector<Node*> nodes;
    for (int i = 0; i < 5; ++i) {
        nodes.push_back(new Node(i, 0));
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            nodes[i]->add_neighbor(nodes[j]);
            nodes[j]->add_neighbor(nodes[i]);
        }
    }
    network.nodes = nodes;
    ConsensusMechanism mechanism(&network);
    mechanism.simulate();
    return 0;
}