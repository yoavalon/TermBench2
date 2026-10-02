#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>
#include <nlohmann/json.hpp>

class Node {
public:
    std::string data;
    std::string hash;

    Node(const std::string& data) : data(data) {
        hash = calculate_hash();
    }

    std::string calculate_hash() {
        nlohmann::json json_data = nlohmann::json::parse(data);
        std::string json_str = json_data.dump();
        unsigned char hash_sha256[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, json_str.c_str(), json_str.size());
        SHA256_Final(hash_sha256, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash_sha256[i];
        }
        return ss.str();
    }
};

class Blockchain {
public:
    std::vector<Node> chain;

    Blockchain() {
        chain.push_back(create_genesis_block());
    }

    Node create_genesis_block() {
        return Node("Genesis Block");
    }

    void add_block(const Node& new_block) {
        Node block = new_block;
        block.previous_hash = chain.back().hash;
        chain.push_back(block);
    }

    bool is_chain_valid() {
        for (size_t i = 1; i < chain.size(); ++i) {
            Node current_block = chain[i];
            Node previous_block = chain[i - 1];
            if (current_block.hash != current_block.calculate_hash()) {
                return false;
            }
            if (current_block.previous_hash != previous_block.hash) {
                return false;
            }
        }
        return true;
    }
};

void main() {
    Blockchain blockchain;
    for (int i = 0; i < 10; ++i) {
        std::string new_data = "Block " + std::to_string(i);
        Node new_block(new_data);
        blockchain.add_block(new_block);
    }
    std::cout << "Blockchain valid: " << (blockchain.is_chain_valid() ? "true" : "false") << std::endl;
}

int main() {
    main();
    return 0;
}