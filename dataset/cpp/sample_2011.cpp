#include <iostream>
#include <string>
#include <unordered_map>
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

std::string cipher_simulation(const std::string& key, const std::string& text) {
    std::string encrypted;
    for (size_t i = 0; i < text.size(); ++i) {
        char k = key[i % key.size()];
        char e = (text[i] + k) % 256;
        encrypted += e;
    }
    return encrypted;
}

int analyze_hash_collision(const std::vector<std::string>& data_set) {
    std::unordered_map<std::string, std::string> hash_map;
    int collisions = 0;
    for (const auto& data : data_set) {
        std::string hash_value = hash_function(data);
        if (hash_map.find(hash_value) != hash_map.end()) {
            collisions += 1;
        } else {
            hash_map[hash_value] = data;
        }
    }
    return collisions;
}

int main() {
    std::string data = "SensitiveData123";
    std::string key = "SecretKey";
    std::string encrypted_data = cipher_simulation(key, data);
    std::string hash_value = hash_function(encrypted_data);
    int collision_count = analyze_hash_collision({encrypted_data, encrypted_data});
    std::cout << "Encrypted Data: " << encrypted_data << std::endl;
    std::cout << "Hash Value: " << hash_value << std::endl;
    std::cout << "Collision Count: " << collision_count << std::endl;
    return 0;
}