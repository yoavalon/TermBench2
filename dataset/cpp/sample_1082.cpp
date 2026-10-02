#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <openssl/sha.h>

std::string hash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool validate_blockchain(const std::vector<std::string>& blockchain, int index) {
    if (index >= blockchain.size()) {
        return true;
    }
    std::string prev_block = index > 0 ? blockchain[index - 1] : "genesis";
    if (blockchain[index] == hash(prev_block)) {
        return validate_blockchain(blockchain, index + 1);
    }
    return false;
}

void simulate_network(std::vector<std::unordered_map<std::string, std::string>>& nodes, std::vector<std::string>& blockchain) {
    for (auto& node : nodes) {
        if (node["state"] == "idle") {
            node["state"] = "active";
            node["block"] = hash(blockchain.back());
            blockchain.push_back(node["block"]);
            node["state"] = "idle";
        }
    }
    simulate_network(nodes, blockchain);
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> nodes(5);
    for (auto& node : nodes) {
        node["state"] = "idle";
    }
    std::vector<std::string> blockchain = {"genesis"};
    simulate_network(nodes, blockchain);
    return 0;
}