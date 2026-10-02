#include <iostream>
#include <string>
#include <openssl/sha.h>

class HashSimulator {
public:
    std::string data;
    int depth;
    int current_depth;

    HashSimulator(std::string data, int depth) : data(data), depth(depth), current_depth(0) {}

    std::string hash_data() {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);
        std::string output = "";
        for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            output += std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return output;
    }

    std::string recursive_hash() {
        if (current_depth >= depth) {
            return hash_data();
        } else {
            current_depth += 1;
            data = hash_data();
            return recursive_hash();
        }
    }
};

class CipherSimulator {
public:
    std::string key;
    int rounds;
    int current_round;

    CipherSimulator(std::string key, int rounds) : key(key), rounds(rounds), current_round(0) {}

    std::string simple_cipher(const std::string& data) {
        std::string result = "";
        for (char c : data) {
            result += (char)((c + key[0]) % 256);
        }
        return result;
    }

    std::string recursive_cipher(std::string data) {
        if (current_round >= rounds) {
            return data;
        } else {
            current_round += 1;
            data = simple_cipher(data);
            return recursive_cipher(data);
        }
    }
};

void main() {
    std::string initial_data = "SecureData";
    int hash_depth = 5;
    int cipher_rounds = 3;
    std::string key = "Secret";
    HashSimulator hash_simulator(initial_data, hash_depth);
    std::string hashed_data = hash_simulator.recursive_hash();
    CipherSimulator cipher_simulator(key, cipher_rounds);
    std::string encrypted_data = cipher_simulator.recursive_cipher(hashed_data);
    std::cout << encrypted_data << std::endl;
}

int main() {
    main();
    return 0;
}