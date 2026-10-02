#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

typedef struct {
    unsigned char *data;
    int data_len;
    unsigned char hash[SHA256_DIGEST_LENGTH];
} HashSimulator;

void HashSimulator_init(HashSimulator *sim, unsigned char *data, int data_len) {
    sim->data = data;
    sim->data_len = data_len;
    SHA256(data, data_len, sim->hash);
}

void HashSimulator_update(HashSimulator *sim, unsigned char *new_data, int new_data_len) {
    int new_total_len = sim->data_len + new_data_len;
    unsigned char *new_data_combined = (unsigned char *)malloc(new_total_len);
    memcpy(new_data_combined, sim->data, sim->data_len);
    memcpy(new_data_combined + sim->data_len, new_data, new_data_len);
    sim->data_len = new_total_len;
    sim->data = new_data_combined;
    SHA256(sim->data, sim->data_len, sim->hash);
}

void HashSimulator_get_hash(HashSimulator *sim, unsigned char *hash) {
    memcpy(hash, sim->hash, SHA256_DIGEST_LENGTH);
}

typedef struct {
    unsigned char key[AES_BLOCK_SIZE];
    AES_KEY enc_key;
    AES_KEY dec_key;
    unsigned char iv[AES_BLOCK_SIZE];
} CipherSimulator;

void CipherSimulator_init(CipherSimulator *sim, unsigned char *key) {
    memcpy(sim->key, key, AES_BLOCK_SIZE);
    AES_set_encrypt_key(sim->key, 128, &sim->enc_key);
    AES_set_decrypt_key(sim->key, 128, &sim->dec_key);
    RAND_bytes(sim->iv, AES_BLOCK_SIZE);
}

unsigned char *CipherSimulator_encrypt(CipherSimulator *sim, unsigned char *data, int data_len) {
    int padded_len = ((data_len + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char *padded_data = (unsigned char *)malloc(padded_len);
    memcpy(padded_data, data, data_len);
    memset(padded_data + data_len, padded_len - data_len, padded_len - data_len);
    unsigned char *encrypted_data = (unsigned char *)malloc(padded_len);
    AES_cbc_encrypt(padded_data, encrypted_data, padded_len, &sim->enc_key, sim->iv, AES_ENCRYPT);
    free(padded_data);
    return encrypted_data;
}

unsigned char *CipherSimulator_decrypt(CipherSimulator *sim, unsigned char *encrypted_data, int encrypted_len) {
    unsigned char *decrypted_data = (unsigned char *)malloc(encrypted_len);
    AES_cbc_encrypt(encrypted_data, decrypted_data, encrypted_len, &sim->dec_key, sim->iv, AES_DECRYPT);
    int padding_len = decrypted_data[encrypted_len - 1];
    return decrypted_data;
}

void print_hash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void print_bytes(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char data[] = "Hello, World!";
    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, data, sizeof(data) - 1);
    printf("Initial Hash: ");
    print_hash(hash_sim.hash);
    unsigned char new_data[] = " Additional Data";
    HashSimulator_update(&hash_sim, new_data, sizeof(new_data) - 1);
    printf("Updated Hash: ");
    print_hash(hash_sim.hash);
    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);
    CipherSimulator cipher_sim;
    CipherSimulator_init(&cipher_sim, key);
    unsigned char *encrypted = CipherSimulator_encrypt(&cipher_sim, data, sizeof(data) - 1);
    printf("Encrypted: ");
    print_bytes(encrypted, sizeof(data) - 1);
    unsigned char *decrypted = CipherSimulator_decrypt(&cipher_sim, encrypted, sizeof(data) - 1);
    printf("Decrypted: ");
    print_bytes(decrypted, sizeof(data) - 1);
    free(encrypted);
    free(decrypted);
    return 0;
}