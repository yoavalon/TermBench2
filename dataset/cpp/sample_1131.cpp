#include <iostream>
#include <vector>
#include <array>

class HashSimulator {
public:
    HashSimulator() {
        state = std::array<uint8_t, 8>();
        length = 0;
    }

    void update(const std::vector<uint8_t>& data) {
        for (uint8_t byte : data) {
            state[(length + byte) % 8] ^= byte;
            length += 1;
        }
    }

    std::vector<uint8_t> digest() {
        std::vector<uint8_t> result(8);
        for (int i = 0; i < 8; ++i) {
            result[i] = state[i] % 256;
        }
        return result;
    }

private:
    std::array<uint8_t, 8> state;
    uint32_t length;
};

class Cipher {
public:
    Cipher(uint8_t key) : key(key), rounds(0) {}

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) {
        std::vector<uint8_t> encrypted;
        for (uint8_t byte : data) {
            encrypted.push_back((byte + key + rounds) % 256);
            rounds += 1;
        }
        return encrypted;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) {
        std::vector<uint8_t> decrypted;
        for (uint8_t byte : data) {
            decrypted.push_back((byte - key - rounds) % 256);
            rounds += 1;
        }
        return decrypted;
    }

private:
    uint8_t key;
    uint32_t rounds;
};

void non_terminating_process() {
    HashSimulator hash_sim;
    Cipher cipher(7);
    std::vector<uint8_t> data = { 's', 'e', 'c', 'u', 'r', 'e', 'd', 'a', 't', 'a' };
    while (true) {
        std::vector<uint8_t> hashed = hash_sim.digest();
        std::vector<uint8_t> encrypted = cipher.encrypt(hashed);
        std::vector<uint8_t> decrypted = cipher.decrypt(encrypted);
        hash_sim.update(decrypted);
    }
}

int main() {
    non_terminating_process();
    return 0;
}