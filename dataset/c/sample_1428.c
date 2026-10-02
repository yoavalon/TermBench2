#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

typedef struct {
    char *data;
    char *key;
} HashSimulator;

typedef struct {
    char *data;
    char *key;
} CipherSimulator;

void HashSimulator_init(HashSimulator *sim, char *data, char *key) {
    sim->data = data;
    sim->key = key;
}

char* HashSimulator_hash_data(HashSimulator *sim) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, sim->data, strlen(sim->data));
    SHA256_Final(hash, &sha256);
    char *hex = (char *)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex + (i * 2), "%02x", hash[i]);
    }
    return hex;
}

char* HashSimulator_hmac_data(HashSimulator *sim) {
    unsigned char hmac[SHA256_DIGEST_LENGTH];
    HMAC_CTX *hmac_ctx = HMAC_CTX_new();
    HMAC_Init_ex(hmac_ctx, sim->key, strlen(sim->key), EVP_sha256(), NULL);
    HMAC_Update(hmac_ctx, sim->data, strlen(sim->data));
    HMAC_Final_ex(hmac_ctx, hmac, NULL);
    HMAC_CTX_free(hmac_ctx);
    char *hex = (char *)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hex + (i * 2), "%02x", hmac[i]);
    }
    return hex;
}

void CipherSimulator_init(CipherSimulator *sim, char *data, char *key) {
    sim->data = data;
    sim->key = key;
}

char* CipherSimulator_encrypt(CipherSimulator *sim) {
    char *encrypted = (char *)malloc(strlen(sim->data) + 1);
    for (size_t i = 0; i < strlen(sim->data); i++) {
        encrypted[i] = (char)((sim->data[i] + sim->key[i % strlen(sim->key)]) % 256);
    }
    encrypted[strlen(sim->data)] = '\0';
    return encrypted;
}

char* CipherSimulator_decrypt(CipherSimulator *sim, char *encrypted_data) {
    char *decrypted = (char *)malloc(strlen(encrypted_data) + 1);
    for (size_t i = 0; i < strlen(encrypted_data); i++) {
        decrypted[i] = (char)((encrypted_data[i] - sim->key[i % strlen(sim->key)]) % 256);
    }
    decrypted[strlen(encrypted_data)] = '\0';
    return decrypted;
}

int main() {
    char *data = "SecureData";
    char *key = "SecretKey";
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
    HashSimulator_init(&hash_sim, data, key);
    CipherSimulator_init(&cipher_sim, data, key);
    char *hash_result = HashSimulator_hash_data(&hash_sim);
    char *hmac_result = HashSimulator_hmac_data(&hash_sim);
    char *encrypted_data = CipherSimulator_encrypt(&cipher_sim);
    printf("Hash: %s\n", hash_result);
    printf("HMAC: %s\n", hmac_result);
    printf("Encrypted: %s\n", encrypted_data);
    char *decrypted_data = CipherSimulator_decrypt(&cipher_sim, encrypted_data);
    printf("Decrypted: %s\n", decrypted_data);
    free(hash_result);
    free(hmac_result);
    free(encrypted_data);
    free(decrypted_data);
    return 0;
}