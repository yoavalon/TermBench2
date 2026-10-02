#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <iomanip>

class HashSimulator {
public:
    HashSimulator(const std::string& data) {
        this->data = data;
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hasher, &sha256);
    }

    void update(const std::string& additional_data) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, additional_data.c_str(), additional_data.size());
        SHA256_Update(&sha256, hasher, SHA256_DIGEST_LENGTH);
        SHA256_Final(hasher, &sha256);
    }

    std::string get_hash() {
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hasher[i];
        }
        return ss.str();
    }

private:
    std::string data;
    unsigned char hasher[SHA256_DIGEST_LENGTH];
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key) {
        this->key = key;
        this->state = 0;
    }

    std::string encrypt(const std::string& plaintext) {
        std::string ciphertext = "";
        for (char char : plaintext) {
            char shifted_char = (char + key[state % key.size()] - 65) % 26 + 65;
            ciphertext += shifted_char;
            state++;
        }
        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string plaintext = "";
        for (char char : ciphertext) {
            char shifted_char = (char - key[state % key.size()] - 65 + 26) % 26 + 65;
            plaintext += shifted_char;
            state++;
        }
        return plaintext;
    }

private:
    std::string key;
    int state;
};

int main() {
    HashSimulator hash_sim("initial_data");
    CipherSimulator cipher_sim("key");
    while (true) {
        std::string data = "some_data";
        hash_sim.update(data);
        std::string hash_value = hash_sim.get_hash();
        std::string encrypted_data = cipher_sim.encrypt(data);
        std::string decrypted_data = cipher_sim.decrypt(encrypted_data);
    }
    return 0;
}