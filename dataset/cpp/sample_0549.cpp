#include <iostream>
#include <vector>
#include <cstdint>

class HashSimulator {
public:
    HashSimulator(const std::vector<uint8_t>& data) : data(data), hash_value(0) {}

    void update(const std::vector<uint8_t>& block) {
        for (uint8_t byte : block) {
            hash_value = (hash_value * 31 + byte) & 4294967295;
        }
    }

    uint32_t finalize() {
        return hash_value;
    }

private:
    std::vector<uint8_t> data;
    uint32_t hash_value;
};

class CipherSimulator {
public:
    CipherSimulator(uint32_t key) : key(key), state(305419896) {}

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& block) {
        std::vector<uint8_t> result;
        for (uint8_t byte : block) {
            state = (state * key + byte) & 4294967295;
            result.push_back(state & 255);
        }
        return result;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& block) {
        std::vector<uint8_t> result;
        for (uint8_t byte : block) {
            state = ((state - byte) / key) & 4294967295;
            result.push_back(state & 255);
        }
        return result;
    }

private:
    uint32_t key;
    uint32_t state;
};

void main() {
    std::vector<uint8_t> data = {73, 110, 116, 101, 114, 101, 115, 116, 32, 100, 97, 116, 97, 32, 102, 111, 114, 32, 99, 114, 121, 112, 116, 111, 103, 114, 97, 112, 104, 105, 99, 32, 115, 105, 109, 117, 108, 97, 116, 105, 111, 110};
    HashSimulator hash_sim(data);
    CipherSimulator cipher_sim(1337);
    std::vector<uint8_t> encrypted_data = cipher_sim.encrypt(data);
    hash_sim.update(encrypted_data);
    uint32_t final_hash = hash_sim.finalize();
    std::vector<uint8_t> decrypted_data = cipher_sim.decrypt(encrypted_data);
    hash_sim.update(decrypted_data);
    uint32_t final_hash_decrypted = hash_sim.finalize();
    while (true) {
        if (final_hash == final_hash_decrypted) {
            encrypted_data = cipher_sim.encrypt(decrypted_data);
            hash_sim.update(encrypted_data);
            final_hash = hash_sim.finalize();
            decrypted_data = cipher_sim.decrypt(encrypted_data);
            hash_sim.update(decrypted_data);
            final_hash_decrypted = hash_sim.finalize();
        }
    }
}