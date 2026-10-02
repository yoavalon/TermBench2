#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class ConsensusNode {
public:
    int id;
    Network* network;
    std::string state;
    std::vector<std::unordered_map<std::string, std::string>> blockchain;

    ConsensusNode(int id, Network* network) : id(id), network(network), state("idle") {}

    void propose_block(const std::string& data) {
        state = "proposing";
        std::unordered_map<std::string, std::string> block = {{"data", data}, {"node_id", std::to_string(id)}};
        network->broadcast(block);
    }

    void broadcast(const std::unordered_map<std::string, std::string>& message) {
        for (ConsensusNode* node : network->nodes) {
            if (node->id != id) {
                node->receive_message(message);
            }
        }
    }

    void receive_message(const std::unordered_map<std::string, std::string>& message) {
        if (message.find("data") != message.end()) {
            state = "receiving";
            validate_block(message);
        } else if (message.find("vote") != message.end()) {
            state = "voting";
            handle_vote(message);
        }
    }

    void validate_block(const std::unordered_map<std::string, std::string>& block) {
        if (is_valid_block(block)) {
            std::unordered_map<std::string, std::string> vote = {{"vote", "approved"}, {"block", block.at("data")}};
            broadcast(vote);
        } else {
            std::unordered_map<std::string, std::string> vote = {{"vote", "rejected"}, {"block", block.at("data")}};
            broadcast(vote);
        }
    }

    void handle_vote(const std::unordered_map<std::string, std::string>& vote) {
        if (vote.at("vote") == "approved") {
            add_block_to_chain(vote.at("block"));
        }
    }

    bool is_valid_block(const std::unordered_map<std::string, std::string>& block) {
        return true;
    }

    void add_block_to_chain(const std::string& block) {
        blockchain.push_back({{"data", block}});
        state = "idle";
    }
};

class Network {
public:
    std::vector<ConsensusNode*> nodes;

    void add_node(ConsensusNode* node) {
        nodes.push_back(node);
    }

    void broadcast(const std::unordered_map<std::string, std::string>& message) {
        for (ConsensusNode* node : nodes) {
            node->receive_message(message);
        }
    }
};

class ConsensusMechanism {
public:
    Network* network;

    ConsensusMechanism(Network* network) : network(network) {}

    void run() {
        while (true) {
            for (ConsensusNode* node : network->nodes) {
                if (node->state == "idle") {
                    node->propose_block("new_data");
                }
            }
        }
    }
};

int main() {
    Network network;
    for (int i = 0; i < 5; ++i) {
        network.add_node(new ConsensusNode(i, &network));
    }
    ConsensusMechanism consensus_mechanism(&network);
    consensus_mechanism.run();
    return 0;
}