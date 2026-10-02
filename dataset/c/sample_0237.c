#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const unsigned char* data, size_t data_len) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, data_len);
    SHA256_Final(hash, &sha256);
    static char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }
    return hash_str;
}

unsigned char* encrypt_block(const unsigned char* block, size_t block_len, const unsigned char* key, size_t key_len) {
    unsigned char* encrypted_block = (unsigned char*)malloc(block_len);
    for (size_t i = 0; i < block_len; i++) {
        encrypted_block[i] = (block[i] + key[i % key_len]) % 256;
    }
    return encrypted_block;
}

unsigned char* simulate_cipher(const unsigned char* data, size_t data_len, const unsigned char* key, size_t key_len) {
    const size_t block_size = 16;
    size_t num_blocks = (data_len + block_size - 1) / block_size;
    unsigned char* encrypted_data = (unsigned char*)malloc(data_len);
    size_t encrypted_len = 0;
    for (size_t i = 0; i < num_blocks; i++) {
        size_t block_start = i * block_size;
        size_t block_end = block_start + block_size < data_len ? block_start + block_size : data_len;
        unsigned char block[block_end - block_start];
        memcpy(block, data + block_start, block_end - block_start);
        unsigned char* encrypted_block = encrypt_block(block, block_end - block_start, key, key_len);
        memcpy(encrypted_data + encrypted_len, encrypted_block, block_end - block_start);
        encrypted_len += block_end - block_start;
        free(encrypted_block);
    }
    return encrypted_data;
}

void main() {
    const unsigned char* data = (unsigned char*)"Hello, World!";
    const unsigned char* key = (unsigned char*)"secret_key";
    size_t data_len = strlen((char*)data);
    size_t key_len = strlen((char*)key);
    char* hashed_data = hash_data(data, data_len);
    unsigned char* encrypted_data = simulate_cipher(data, data_len, key, key_len);
    printf("Hashed Data: %s\n", hashed_data);
    printf("Encrypted Data: ");
    for (size_t i = 0; i < data_len; i++) {
        printf("%02x", encrypted_data[i]);
    }
    printf("\n");
    free(encrypted_data);
}