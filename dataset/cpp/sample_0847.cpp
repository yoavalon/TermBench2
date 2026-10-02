#include <iostream>
#include <vector>
#include <string>

class HashFunction {
public:
    HashFunction(const std::vector<unsigned char>& data) : data(data), hash_value(0) {}

    HashFunction& update() {
        for (unsigned char byte : data) {
            hash_value = hash_value * 33 ^ byte;
        }
        return *this;
    }

    int digest() const {
        return hash_value;
    }

private:
    std::vector<unsigned char> data;
    int hash_value;
};

class CipherSimulator {
public:
    CipherSimulator(const std::vector<unsigned char>& key, const std::vector<unsigned char>& data) 
        : key(key), data(data), encrypted_data(data.size(), 0) {}

    CipherSimulator& encrypt(int index = 0) {
        if (index >= data.size()) {
            return *this;
        }
        encrypted_data[index] = data[index] ^ key[index % key.size()];
        encrypt(index + 1);
        return *this;
    }

    const std::vector<unsigned char>& get_encrypted_data() const {
        return encrypted_data;
    }

private:
    std::vector<unsigned char> key;
    std::vector<unsigned char> data;
    std::vector<unsigned char> encrypted_data;
};

int main() {
    std::vector<unsigned char> original_data = {72, 101, 108, 108, 111, 44, 32, 119, 111, 114, 108, 100, 33};
    HashFunction hash_function(original_data);
    hash_function.update();
    int hash_value = hash_function.digest();
    std::vector<unsigned char> key = {115, 101, 99, 114, 101, 116};
    CipherSimulator cipher_simulator(key, original_data);
    cipher_simulator.encrypt();
    const std::vector<unsigned char>& encrypted_data = cipher_simulator.get_encrypted_data();
    std::cout << "Hash Value: " << hash_value << std::endl;
    std::cout << "Encrypted Data: ";
    for (unsigned char byte : encrypted_data) {
        std::cout << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;
    return 0;
}