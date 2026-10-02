#include <iostream>
#include <string>
#include <map>
#include <openssl/sha.h>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data) {}

    void generate_hashes() {
        for (size_t i = 0; i < data.length(); ++i) {
            std::string key = data.substr(i, 1);
            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256_CTX sha256;
            SHA256_Init(&sha256);
            SHA256_Update(&sha256, key.c_str(), key.size());
            SHA256_Final(hash, &sha256);
            std::stringstream ss;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
                ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
            }
            hash_values[key] = ss.str();
        }
    }

    void display_hashes() {
        for (const auto& pair : hash_values) {
            std::cout << "Data: " << pair.first << ", Hash: " << pair.second << std::endl;
        }
    }

private:
    std::string data;
    std::map<std::string, std::string> hash_values;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& data) : data(data) {}

    void encrypt() {
        for (char c : data) {
            char encrypted_char = (c + 3) % 256;
            cipher_text.push_back(encrypted_char);
        }
    }

    void display_cipher() {
        std::cout << "Cipher Text: ";
        for (char c : cipher_text) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

private:
    std::string data;
    std::string cipher_text;
};

void main() {
    std::string data = "HelloWorld";
    HashSimulator hash_simulator(data);
    CipherSimulator cipher_simulator(data);
    hash_simulator.generate_hashes();
    hash_simulator.display_hashes();
    cipher_simulator.encrypt();
    cipher_simulator.display_cipher();
    exit(0);
}