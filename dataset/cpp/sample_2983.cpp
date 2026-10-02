#include <iostream>
#include <string>
#include <openssl/sha.h>

class HashSequence {
public:
    std::string current_value;

    HashSequence(const std::string& initial_value) : current_value(initial_value) {}

    std::string update() {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, current_value.c_str(), current_value.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        current_value = ss.str();
        return current_value;
    }
};

class CipherSimulator {
public:
    HashSequence& hash_sequence;

    CipherSimulator(HashSequence& hash_sequence) : hash_sequence(hash_sequence) {}

    std::string encrypt() {
        std::string encrypted_value;
        for (char c : hash_sequence.current_value) {
            encrypted_value += static_cast<char>((c + 3) % 256);
        }
        return encrypted_value;
    }
};

class SequenceAnalyzer {
public:
    CipherSimulator& cipher_simulator;

    SequenceAnalyzer(CipherSimulator& cipher_simulator) : cipher_simulator(cipher_simulator) {}

    void analyze() {
        while (true) {
            std::string hashed_value = cipher_simulator.hash_sequence.update();
            std::string encrypted_value = cipher_simulator.encrypt();
            std::cout << "Hashed: " << hashed_value << "\nEncrypted: " << encrypted_value << "\n";
        }
    }
};

int main() {
    std::string initial_value = "seed_value";
    HashSequence hash_sequence(initial_value);
    CipherSimulator cipher_simulator(hash_sequence);
    SequenceAnalyzer sequence_analyzer(cipher_simulator);
    sequence_analyzer.analyze();
    return 0;
}