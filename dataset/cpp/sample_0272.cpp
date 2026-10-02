#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

class Block {
public:
    int index;
    std::string data;
    std::string previous_hash;
    std::string hash;

    Block(int index, std::string data, std::string previous_hash) : index(index), data(data), previous_hash(previous_hash) {
        hash = calculate_hash();
    }

    std::string calculate_hash() {
        std::string block_string = "{\"index\":" + std::to_string(index) + ",\"data\":\"" + data + "\",\"previous_hash\":\"" + previous_hash + "\"}";
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, block_string.c_str(), block_string.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }
};

class Blockchain {
public:
    std::vector<Block> chain;

    Blockchain() {
        chain.push_back(create_genesis_block());
    }

    Block create_genesis_block() {
        return Block(0, "Genesis Block", "0");
    }

    void add_block(Block new_block) {
        new_block.previous_hash = chain.back().hash;
        new_block.hash = new_block.calculate_hash();
        chain.push_back(new_block);
    }

    bool is_chain_valid() {
        for (size_t i = 1; i < chain.size(); i++) {
            Block current_block = chain[i];
            Block previous_block = chain[i - 1];
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

void simulate_consensus_mechanics() {
    Blockchain blockchain;
    for (int i = 1; i < 10; i++) {
        std::string new_block_data = "Block " + std::to_string(i) + " Data";
        Block new_block(i, new_block_data, "");
        blockchain.add_block(new_block);
        std::cout << "Block " << i << " added to the blockchain" << std::endl;
    }
    if (blockchain.is_chain_valid()) {
        std::cout << "Blockchain is valid." << std::endl;
    } else {
        std::cout << "Blockchain is invalid." << std::endl;
    }
}

int main() {
    simulate_consensus_mechanics();
    return 0;
}