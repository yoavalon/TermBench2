#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

std::string hash(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool validate_blockchain(const std::vector<std::string>& blockchain, int index = 0) {
    if (index >= blockchain.size()) {
        return true;
    }
    std::string prev_block = (index > 0) ? blockchain[index - 1] : "";
    if (blockchain[index] != hash(prev_block)) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

std::vector<std::string> append_block(const std::vector<std::string>& blockchain, const std::string& data) {
    std::string new_block = (blockchain.size() > 0) ? hash(blockchain.back()) : "";
    new_block = std::to_string(std::stoull(new_block, nullptr, 16) ^ std::stoull(hash(data), nullptr, 16));
    std::vector<std::string> new_blockchain = blockchain;
    new_blockchain.push_back(new_block);
    return new_blockchain;
}

int main() {
    std::vector<std::string> blockchain = {hash("genesis")};
    for (int _ = 0; _ < 5; ++_) {
        blockchain = append_block(blockchain, hash("transaction"));
    }
    std::cout << std::boolalpha << validate_blockchain(blockchain) << std::endl;
    return 0;
}