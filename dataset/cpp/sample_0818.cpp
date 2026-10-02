#include <iostream>
#include <string>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data), digest(hash_function(data)) {}

    int hash_function(const std::string& data) {
        if (data.length() == 0) {
            return 0;
        } else {
            return (data[0] + hash_function(data.substr(1))) % 1000;
        }
    }

    std::string encrypt(int key) {
        std::string encrypted;
        for (char c : std::to_string(digest)) {
            encrypted += (char)((c + key) % 256);
        }
        return encrypted;
    }

private:
    std::string data;
    int digest;
};

class CipherSimulator {
public:
    CipherSimulator(int key, const std::string& data) : key(key), data(data) {}

    std::string decrypt(const std::string& encrypted_data) {
        std::string decrypted;
        for (char c : encrypted_data) {
            decrypted += (char)((c - key) % 256);
        }
        return decrypted;
    }

private:
    int key;
    std::string data;
};

void main() {
    std::string data = "SecureData";
    int key = 7;
    HashSimulator hash_sim(data);
    std::string encrypted = hash_sim.encrypt(key);
    CipherSimulator cipher_sim(key, encrypted);
    std::string decrypted = cipher_sim.decrypt(encrypted);
    std::cout << "Original Data: " << data << std::endl;
    std::cout << "Encrypted Data: " << encrypted << std::endl;
    std::cout << "Decrypted Data: " << decrypted << std::endl;
}