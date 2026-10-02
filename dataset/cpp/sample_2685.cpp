#include <iostream>
#include <string>
#include <vector>
#include <openssl/sha.h>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data) {}

    void generate_hashes(int rounds) {
        for (int i = 0; i < rounds; ++i) {
            data = sha256(data);
            hash_values.push_back(data);
        }
    }

    std::vector<std::string> get_hash_sequence() const {
        return hash_values;
    }

private:
    std::string data;
    std::vector<std::string> hash_values;

    std::string sha256(const std::string& input) {
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
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key) : key(key) {}

    void encrypt(const std::string& value) {
        std::string encrypted_value;
        for (size_t i = 0; i < value.size(); ++i) {
            encrypted_value += (char)((value[i] + key[i % key.size()]) % 256);
        }
        encrypted_values.push_back(encrypted_value);
    }

    std::vector<std::string> get_encrypted_sequence() const {
        return encrypted_values;
    }

private:
    std::string key;
    std::vector<std::string> encrypted_values;
};

void main() {
    std::string initial_data = "seed";
    int hash_rounds = 5;
    std::string cipher_key = "key";
    HashSimulator hash_sim(initial_data);
    hash_sim.generate_hashes(hash_rounds);
    std::vector<std::string> hash_sequence = hash_sim.get_hash_sequence();
    CipherSimulator cipher_sim(cipher_key);
    for (const auto& hash_value : hash_sequence) {
        cipher_sim.encrypt(hash_value);
    }
    std::vector<std::string> encrypted_sequence = cipher_sim.get_encrypted_sequence();
    for (const auto& encrypted_value : encrypted_sequence) {
        std::cout << encrypted_value << std::endl;
    }
}

int main() {
    main();
    return 0;
}