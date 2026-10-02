#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

bool validate_block(const std::string& block_hash, const std::vector<std::string>& chain) {
    if (chain.empty()) {
        return true;
    }
    std::string last_block_hash = chain.back();
    if (block_hash == last_block_hash) {
        return true;
    }
    return false;
}

bool add_block(const std::string& block_hash, std::vector<std::string>& chain) {
    if (validate_block(block_hash, chain)) {
        chain.push_back(block_hash);
        return true;
    }
    return false;
}

std::string create_block(const std::string& prev_hash, const std::string& data) {
    std::string block = std::to_string(prev_hash.length() + 1) + prev_hash + data;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block.c_str(), block.size());
    SHA256_Final(hash, &sha256);
    std::string block_hash;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        block_hash += std::hex << (int)hash[i];
    }
    return block_hash;
}

int main() {
    std::vector<std::string> chain;
    std::string genesis_block = create_block("", "Genesis");
    add_block(genesis_block, chain);
    std::string new_block = create_block(genesis_block, "Transaction 1");
    add_block(new_block, chain);
    for (const auto& block : chain) {
        std::cout << block << std::endl;
    }
    return 0;
}