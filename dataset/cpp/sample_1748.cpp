#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Block {
public:
    std::string data;
    int prev_hash;
    int hash;

    Block(std::string data, int prev_hash) : data(data), prev_hash(prev_hash) {
        hash = calculate_hash();
    }

    int calculate_hash() {
        return std::hash<std::string>()(data + std::to_string(prev_hash));
    }
};

class ConsensusNode {
public:
    int id;
    std::vector<Block> chain;

    ConsensusNode(int id) : id(id) {}

    void add_block(const Block& block) {
        chain.push_back(block);
        broadcast_block(block);
    }

    void broadcast_block(const Block& block) {
        for (auto& node : network) {
            if (&node != this) {
                node.receive_block(block);
            }
        }
    }

    void receive_block(const Block& block) {
        chain.push_back(block);
    }
};

std::vector<ConsensusNode> network;

std::vector<ConsensusNode> initialize_network(int num_nodes) {
    std::vector<ConsensusNode> nodes;
    for (int i = 0; i < num_nodes; ++i) {
        nodes.push_back(ConsensusNode(i));
    }
    return nodes;
}

Block generate_block(ConsensusNode& node, const std::string& data) {
    if (!node.chain.empty()) {
        Block prev_block = node.chain.back();
        return Block(data, prev_block.hash);
    } else {
        return Block(data, 0);
    }
}

void simulate_consensus() {
    network = initialize_network(5);
    Block initial_block = generate_block(network[0], "Genesis");
    network[0].add_block(initial_block);
    while (true) {
        for (auto& node : network) {
            std::string new_data = "Transaction " + std::to_string(node.chain.size());
            Block new_block = generate_block(node, new_data);
            node.add_block(new_block);
        }
    }
}

int main() {
    simulate_consensus();
    return 0;
}