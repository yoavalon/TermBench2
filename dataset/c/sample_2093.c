#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

typedef struct {
    char *key;
    char *message;
} HashSimulator;

typedef struct {
    char *data;
} CipherSimulator;

typedef struct {
    HashSimulator *hash_simulator;
    CipherSimulator *cipher_simulator;
} DataProcessor;

void HashSimulator_init(HashSimulator *self, const char *key, const char *message) {
    self->key = strdup(key);
    self->message = strdup(message);
}

char* HashSimulator_hash_message(HashSimulator *self) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, self->message, strlen(self->message));
    SHA256_Final(hash, &sha256);
    char *output = (char*)malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

char* HashSimulator_hmac_message(HashSimulator *self) {
    unsigned char hash[HMAC_SIZE];
    unsigned int hash_len;
    HMAC_CTX *hmac = HMAC_CTX_new();
    HMAC_Init_ex(hmac, self->key, strlen(self->key), EVP_sha256(), NULL);
    HMAC_Update(hmac, (unsigned char*)self->message, strlen(self->message));
    HMAC_Final_ex(hmac, hash, &hash_len);
    HMAC_CTX_free(hmac);
    char *output = (char*)malloc(HMAC_SIZE * 2 + 1);
    for(int i = 0; i < hash_len; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    return output;
}

void CipherSimulator_init(CipherSimulator *self, const char *data) {
    self->data = strdup(data);
}

char* CipherSimulator_xor_cipher(CipherSimulator *self, const char *key) {
    size_t len = strlen(self->data);
    char *output = (char*)malloc(len + 1);
    for(size_t i = 0; i < len; i++) {
        output[i] = self->data[i] ^ key[i % 16];
    }
    output[len] = '\0';
    return output;
}

char* CipherSimulator_shift_cipher(CipherSimulator *self, int shift) {
    size_t len = strlen(self->data);
    char *output = (char*)malloc(len + 1);
    for(size_t i = 0; i < len; i++) {
        output[i] = (self->data[i] + shift) % 256;
    }
    output[len] = '\0';
    return output;
}

void DataProcessor_init(DataProcessor *self, HashSimulator *hash_simulator, CipherSimulator *cipher_simulator) {
    self->hash_simulator = hash_simulator;
    self->cipher_simulator = cipher_simulator;
}

char** DataProcessor_process_data(DataProcessor *self) {
    char *hash_result = HashSimulator_hash_message(self->hash_simulator);
    char *hmac_result = HashSimulator_hmac_message(self->hash_simulator);
    char *xor_result = CipherSimulator_xor_cipher(self->cipher_simulator, hash_result);
    char *shift_result = CipherSimulator_shift_cipher(self->cipher_simulator, 5);
    char **result = (char**)malloc(3 * sizeof(char*));
    result[0] = hmac_result;
    result[1] = xor_result;
    result[2] = shift_result;
    free(hash_result);
    return result;
}

void main() {
    char *key = (char*)malloc(33);
    for(int i = 0; i < 16; i++) {
        sprintf(key + (i * 2), "%02x", (unsigned char)rand());
    }
    key[32] = '\0';
    char *message = "SecureMessage";
    HashSimulator hash_sim;
    HashSimulator_init(&hash_sim, key, message);
    CipherSimulator cipher_sim;
    CipherSimulator_init(&cipher_sim, message);
    DataProcessor data_processor;
    DataProcessor_init(&data_processor, &hash_sim, &cipher_sim);
    char **result = DataProcessor_process_data(&data_processor);
    printf("%s %s %s\n", result[0], result[1], result[2]);
    free(key);
    free(result[0]);
    free(result[1]);
    free(result[2]);
    free(result);
}