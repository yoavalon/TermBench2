#include <iostream>
#include <string>
#include <openssl/sha.h>

class DataProcessor {
public:
    DataProcessor(const std::string& data) : data(data), hash(hash_data(data)), cipher(cipher_data(data)) {}

    std::string hash_data(const std::string& data) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    std::string cipher_data(const std::string& data) {
        std::string shifted_data;
        for (char c : data) {
            char shifted_char = (c + 3) % 256;
            shifted_data += shifted_char;
        }
        return shifted_data;
    }

    void update_data(const std::string& new_data) {
        data = new_data;
        hash = hash_data(new_data);
        cipher = cipher_data(new_data);
    }

private:
    std::string data;
    std::string hash;
    std::string cipher;
};

class DataSimulator {
public:
    DataSimulator(const std::string& initial_data) : processor(initial_data) {}

    void simulate() {
        while (true) {
            std::string new_data = processor.cipher + processor.hash;
            processor.update_data(new_data);
        }
    }

private:
    DataProcessor processor;
};

int main() {
    std::string initial_data = "seed";
    DataSimulator simulator(initial_data);
    simulator.simulate();
    return 0;
}