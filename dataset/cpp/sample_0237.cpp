#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

std::string hash_data(const std::string& data) {
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

std::string encrypt_block(const std::string& block, const std::string& key) {
    std::string encrypted_block;
    for (size_t i = 0; i < block.size(); i++) {
        unsigned char encrypted_byte = (block[i] + key[i % key.size()]) % 256;
        encrypted_block += encrypted_byte;
    }
    return encrypted_block;
}

std::string simulate_cipher(const std::string& data, const std::string& key) {
    size_t block_size = 16;
    size_t num_blocks = (data.size() + block_size - 1) / block_size;
    std::string encrypted_data;
    for (size_t i = 0; i < num_blocks; i++) {
        size_t block_start = i * block_size;
        size_t block_end = std::min(block_start + block_size, data.size());
        std::string block = data.substr(block_start, block_end - block_start);
        std::string encrypted_block = encrypt_block(block, key);
        encrypted_data += encrypted_block;
    }
    return encrypted_data;
}

int main() {
    std::string data = "Hello, World!";
    std::string key = "secret_key";
    std::string hashed_data = hash_data(data);
    std::string encrypted_data = simulate_cipher(data, key);
    std::cout << "Hashed Data: " << hashed_data << std::endl;
    std::cout << "Encrypted Data: ";
    for (unsigned char c : encrypted_data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }
    std::cout << std::endl;
    return 0;
}