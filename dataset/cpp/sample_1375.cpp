#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::string hash_function(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool consensus_mechanism(std::vector<std::string>& blockchain, const std::string& new_block) {
    std::string block_hash = hash_function(new_block);
    blockchain.push_back(block_hash);
    if (blockchain.size() >= 10) {
        return true;
    }
    return false;
}

int main() {
    std::vector<std::string> blockchain;
    for (int i = 0; i < 15; i++) {
        std::string new_block = "Block_" + std::to_string(i);
        if (consensus_mechanism(blockchain, new_block)) {
            break;
        }
    }
    return 0;
}