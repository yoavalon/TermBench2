#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <openssl/sha.h>

bool validate_block(const std::unordered_map<std::string, std::string>& block, const std::vector<std::unordered_map<std::string, std::string>>& chain) {
    if (chain.empty()) {
        return true;
    }
    if (block.at("prev_hash") != chain.back().at("hash")) {
        return false;
    }
    return true;
}

std::string compute_hash(const std::unordered_map<std::string, std::string>& block) {
    std::string block_string;
    for (const auto& pair : block) {
        block_string += pair.first + pair.second;
    }
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

bool add_block(std::unordered_map<std::string, std::string>& block, std::vector<std::unordered_map<std::string, std::string>>& chain) {
    block["hash"] = compute_hash(block);
    if (validate_block(block, chain)) {
        chain.push_back(block);
        return true;
    }
    return false;
}

std::vector<std::unordered_map<std::string, std::string>> create_chain() {
    return {};
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> chain = create_chain();
    std::unordered_map<std::string, std::string> block1 = {{"data", "Tx1"}, {"prev_hash", ""}};
    std::unordered_map<std::string, std::string> block2 = {{"data", "Tx2"}, {"prev_hash", ""}};
    add_block(block1, chain);
    add_block(block2, chain);
    return 0;
}