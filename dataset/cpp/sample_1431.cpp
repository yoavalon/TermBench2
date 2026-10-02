#include <iostream>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>
#include <vector>

class HashSimulator {
public:
    HashSimulator(const std::vector<unsigned char>& data) : data(data) {
        hash = calculateHash(data);
    }

    void update(const std::vector<unsigned char>& new_data) {
        data.insert(data.end(), new_data.begin(), new_data.end());
        hash = calculateHash(data);
    }

    const std::vector<unsigned char>& getHash() const {
        return hash;
    }

private:
    std::vector<unsigned char> data;
    std::vector<unsigned char> hash;

    std::vector<unsigned char> calculateHash(const std::vector<unsigned char>& data) {
        unsigned char digest[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.data(), data.size());
        SHA256_Final(digest, &sha256);
        return std::vector<unsigned char>(digest, digest + SHA256_DIGEST_LENGTH);
    }
};

class CipherSimulator {
public:
    CipherSimulator(const std::vector<unsigned char>& key) : key(key) {
        AES_set_encrypt_key(key.data(), key.size() * 8, &enc_key);
        AES_set_decrypt_key(key.data(), key.size() * 8, &dec_key);
        iv = generateRandomBytes(AES_BLOCK_SIZE);
    }

    std::vector<unsigned char> encrypt(const std::vector<unsigned char>& data) {
        std::vector<unsigned char> padded_data = pad(data, AES_BLOCK_SIZE);
        std::vector<unsigned char> encrypted_data(padded_data.size());
        AES_cbc_encrypt(padded_data.data(), encrypted_data.data(), padded_data.size(), &enc_key, iv.data(), AES_ENCRYPT);
        return encrypted_data;
    }

    std::vector<unsigned char> decrypt(const std::vector<unsigned char>& encrypted_data) {
        std::vector<unsigned char> decrypted_data(encrypted_data.size());
        AES_cbc_encrypt(encrypted_data.data(), decrypted_data.data(), encrypted_data.size(), &dec_key, iv.data(), AES_DECRYPT);
        return unpad(decrypted_data, AES_BLOCK_SIZE);
    }

private:
    std::vector<unsigned char> key;
    std::vector<unsigned char> iv;
    AES_KEY enc_key;
    AES_KEY dec_key;

    std::vector<unsigned char> generateRandomBytes(int size) {
        std::vector<unsigned char> bytes(size);
        RAND_bytes(bytes.data(), size);
        return bytes;
    }

    std::vector<unsigned char> pad(const std::vector<unsigned char>& data, int block_size) {
        int padding_length = block_size - (data.size() % block_size);
        std::vector<unsigned char> padded_data = data;
        padded_data.insert(padded_data.end(), padding_length, padding_length);
        return padded_data;
    }

    std::vector<unsigned char> unpad(const std::vector<unsigned char>& data, int block_size) {
        int padding_length = data.back();
        return std::vector<unsigned char>(data.begin(), data.end() - padding_length);
    }
};

void main() {
    std::vector<unsigned char> data = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    HashSimulator hash_sim(data);
    std::cout << "Initial Hash: ";
    for (unsigned char c : hash_sim.getHash()) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;

    std::vector<unsigned char> new_data = {' ', 'A', 'd', 'd', 'i', 't', 'i', 'o', 'n', 'a', 'l', ' ', 'D', 'a', 't', 'a'};
    hash_sim.update(new_data);
    std::cout << "Updated Hash: ";
    for (unsigned char c : hash_sim.getHash()) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;

    std::vector<unsigned char> key = generateRandomBytes(16);
    CipherSimulator cipher_sim(key);
    std::vector<unsigned char> encrypted = cipher_sim.encrypt(data);
    std::cout << "Encrypted: ";
    for (unsigned char c : encrypted) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;

    std::vector<unsigned char> decrypted = cipher_sim.decrypt(encrypted);
    std::cout << "Decrypted: ";
    for (unsigned char c : decrypted) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}