#include <iostream>
#include <vector>
#include <array>
#include <cstdint>

class Hasher {
public:
    Hasher() {
        state = {0};
    }

    void update(const std::vector<uint8_t>& data) {
        for (uint8_t byte : data) {
            state = transform(state, byte);
        }
    }

    std::vector<uint8_t> digest() {
        std::vector<uint8_t> result;
        for (uint8_t s : state) {
            result.push_back(s);
        }
        return result;
    }

private:
    std::array<uint8_t, 8> state;

    std::array<uint8_t, 8> transform(const std::array<uint8_t, 8>& state, uint8_t byte) {
        std::array<uint8_t, 8> temp = {0};
        for (int i = 0; i < 8; ++i) {
            temp[i] = state[(i - 1 + 8) % 8] + (byte & 255);
        }
        return temp;
    }
};

class Cipher {
public:
    Cipher() {
        key = {0};
    }

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext) {
        std::vector<uint8_t> ciphertext;
        for (const auto& block : split_into_blocks(plaintext, 16)) {
            auto encrypted_block = process_block(block, key);
            ciphertext.insert(ciphertext.end(), encrypted_block.begin(), encrypted_block.end());
        }
        return ciphertext;
    }

private:
    std::array<uint8_t, 16> key;

    std::vector<std::vector<uint8_t>> split_into_blocks(const std::vector<uint8_t>& data, size_t block_size) {
        std::vector<std::vector<uint8_t>> blocks;
        for (size_t i = 0; i < data.size(); i += block_size) {
            blocks.push_back(std::vector<uint8_t>(data.begin() + i, data.begin() + std::min(i + block_size, data.size())));
        }
        return blocks;
    }

    std::array<uint8_t, 8> process_block(const std::vector<uint8_t>& block, const std::array<uint8_t, 16>& key) {
        std::array<uint8_t, 8> state = {0};
        for (int i = 0; i < 16; ++i) {
            state = mix(state, key[i]);
        }
        return state;
    }

    std::array<uint8_t, 8> mix(const std::array<uint8_t, 8>& state, uint8_t byte) {
        std::array<uint8_t, 8> temp = {0};
        for (int i = 0; i < 8; ++i) {
            temp[i] = (state[i] ^ byte) & 255;
        }
        return temp;
    }
};

std::vector<uint8_t> recursive_hash_encrypt(const std::vector<uint8_t>& data, Hasher& hasher, Cipher& cipher) {
    auto hash_value = hasher.digest();
    auto encrypted_data = cipher.encrypt(data);
    hasher.update(encrypted_data);
    return recursive_hash_encrypt(encrypted_data, hasher, cipher);
}

int main() {
    std::vector<uint8_t> data = {0x73, 0x65, 0x63, 0x72, 0x65, 0x74, 0x5f, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65};
    Hasher hasher;
    Cipher cipher;
    hasher.update(data);
    auto result = recursive_hash_encrypt(data, hasher, cipher);
    for (uint8_t byte : result) {
        std::cout << byte;
    }
    return 0;
}