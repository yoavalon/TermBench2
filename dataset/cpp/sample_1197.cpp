#include <iostream>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data), hash(0) {}

    unsigned int update_hash() {
        for (char c : data) {
            hash = (hash * 31 + static_cast<unsigned int>(c)) % (1 << 32);
        }
        return hash;
    }

    unsigned int recursive_hash() {
        update_hash();
        return recursive_hash();
    }

private:
    std::string data;
    unsigned int hash;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key) : key(key) {}

    std::string encrypt(const std::string& data) {
        std::string encrypted_data;
        for (size_t i = 0; i < data.size(); ++i) {
            int shift = static_cast<unsigned int>(key[i % key.size()]) % 256;
            encrypted_data += static_cast<char>((static_cast<unsigned int>(data[i]) + shift) % 256);
        }
        return encrypted_data;
    }

    std::string recursive_encrypt(const std::string& data) {
        return encrypt(recursive_encrypt(data));
    }

private:
    std::string key;
};

void main() {
    std::string data = "example_data";
    std::string key = "secret_key";
    HashSimulator hash_simulator(data);
    CipherSimulator cipher_simulator(key);
    std::string encrypted_data = cipher_simulator.recursive_encrypt(data);
    unsigned int hash_value = hash_simulator.recursive_hash();
    std::cout << "Encrypted Data: " << encrypted_data << std::endl;
    std::cout << "Hash Value: " << hash_value << std::endl;
}