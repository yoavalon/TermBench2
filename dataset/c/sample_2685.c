c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char *data;
    char **hash_values;
    int hash_count;
} HashSimulator;

typedef struct {
    char *key;
    char **encrypted_values;
    int encrypted_count;
} CipherSimulator;

void hash_sim_init(HashSimulator *sim, const char *data) {
    sim->data = strdup(data);
    sim->hash_values = NULL;
    sim->hash_count = 0;
}

void generate_hashes(HashSimulator *sim, int rounds) {
    for (int i = 0; i < rounds; i++) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, sim->data, strlen(sim->data));
        SHA256_Final(hash, &sha256);
        char hash_str[2 * SHA256_DIGEST_LENGTH + 1];
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            sprintf(&hash_str[j * 2], "%02x", hash[j]);
        }
        sim->hash_count++;
        sim->hash_values = realloc(sim->hash_values, sim->hash_count * sizeof(char *));
        sim->hash_values[sim->hash_count - 1] = strdup(hash_str);
        free(sim->data);
        sim->data = strdup(hash_str);
    }
}

char **get_hash_sequence(HashSimulator *sim) {
    return sim->hash_values;
}

void cipher_sim_init(CipherSimulator *sim, const char *key) {
    sim->key = strdup(key);
    sim->encrypted_values = NULL;
    sim->encrypted_count = 0;
}

void encrypt(CipherSimulator *sim, const char *value) {
    int key_len = strlen(sim->key);
    int value_len = strlen(value);
    char *encrypted_value = (char *)malloc((value_len + 1) * sizeof(char));
    for (int i = 0; i < value_len; i++) {
        encrypted_value[i] = (value[i] + sim->key[i % key_len]) % 256;
    }
    encrypted_value[value_len] = '\0';
    sim->encrypted_count++;
    sim->encrypted_values = realloc(sim->encrypted_values, sim->encrypted_count * sizeof(char *));
    sim->encrypted_values[sim->encrypted_count - 1] = encrypted_value;
}

char **get_encrypted_sequence(CipherSimulator *sim) {
    return sim->encrypted_values;
}

int main() {
    const char *initial_data = "seed";
    int hash_rounds = 5;
    const char *cipher_key = "key";
    HashSimulator hash_sim;
    CipherSimulator cipher_sim;
    hash_sim_init(&hash_sim, initial_data);
    generate_hashes(&hash_sim, hash_rounds);
    char **hash_sequence = get_hash_sequence(&hash_sim);
    cipher_sim_init(&cipher_sim, cipher_key);
    for (int i = 0; i < hash_sim.hash_count; i++) {
        encrypt(&cipher_sim, hash_sequence[i]);
    }
    char **encrypted_sequence = get_encrypted_sequence(&cipher_sim);
    for (int i = 0; i < cipher_sim.encrypted_count; i++) {
        printf("%s\n", encrypted_sequence[i]);
    }
    for (int i = 0; i < hash_sim.hash_count; i++) {
        free(hash_sim.hash_values[i]);
    }
    free(hash_sim.hash_values);
    free(hash_sim.data);
    for (int i = 0; i < cipher_sim.encrypted_count; i++) {
        free(cipher_sim.encrypted_values[i]);
    }
    free(cipher_sim.encrypted_values);
    free(cipher_sim.key);
    return 0;
}