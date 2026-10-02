#include <iostream>
#include <string>
#include <vector>
#include <openssl/sha.h>
#include <openssl/hmac.h>

class HashSimulator {
public:
    HashSimulator(const std::string& data) : data(data) {}

    std::string hash_data(const std::string& algorithm) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string output = std::string((char*)hash, SHA256_DIGEST_LENGTH);
        return output;
    }

private:
    std::string data;
};

class CipherSimulator {
public:
    CipherSimulator(const std::string& key) : key(key) {}

    std::string xor_cipher(const std::string& data) {
        std::string result;
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] ^ key[i % key.size()];
        }
        return result;
    }

private:
    std::string key;
};

class DataMutator {
public:
    DataMutator(HashSimulator& hash_sim, CipherSimulator& cipher_sim) : hash_sim(hash_sim), cipher_sim(cipher_sim) {}

    std::pair<std::string, std::string> mutate_data(const std::string& data, const std::string& algorithm) {
        std::string hashed_data = hash_sim.hash_data(algorithm);
        std::string ciphered_data = cipher_sim.xor_cipher(data);
        return {hashed_data, ciphered_data};
    }

private:
    HashSimulator& hash_sim;
    CipherSimulator& cipher_sim;
};

void main() {
    std::string data = "This is a sample data for hashing and ciphering";
    std::string key = "cipherkey";
    std::string algorithm = "sha256";
    HashSimulator hash_sim(data);
    CipherSimulator cipher_sim(key);
    DataMutator mutator(hash_sim, cipher_sim);
    auto [hashed_result, ciphered_result] = mutator.mutate_data(data, algorithm);
    std::cout << "Hashed Result: " << hashed_result << std::endl;
    std::cout << "Ciphered Result: " << ciphered_result << std::endl;
}

int main() {
    main();
    return 0;
}