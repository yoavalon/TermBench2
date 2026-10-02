#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

typedef struct {
    const char *data;
    const char *hash_algorithms[4];
} HashSimulator;

typedef struct {
    const char *data;
    const unsigned char *key;
} CipherSimulator;

typedef struct {
    const char *data;
    const unsigned char *key;
} DataMutator;

unsigned char* apply_hash(const char *data, const char *algorithm, unsigned int *digest_length) {
    unsigned char *digest;
    if (strcmp(algorithm, "md5") == 0) {
        digest = (unsigned char *)malloc(MD5_DIGEST_LENGTH);
        MD5(data, strlen(data), digest);
        *digest_length = MD5_DIGEST_LENGTH;
    } else if (strcmp(algorithm, "sha1") == 0) {
        digest = (unsigned char *)malloc(SHA_DIGEST_LENGTH);
        SHA1(data, strlen(data), digest);
        *digest_length = SHA_DIGEST_LENGTH;
    } else if (strcmp(algorithm, "sha256") == 0) {
        digest = (unsigned char *)malloc(SHA256_DIGEST_LENGTH);
        SHA256(data, strlen(data), digest);
        *digest_length = SHA256_DIGEST_LENGTH;
    } else if (strcmp(algorithm, "sha512") == 0) {
        digest = (unsigned char *)malloc(SHA512_DIGEST_LENGTH);
        SHA512(data, strlen(data), digest);
        *digest_length = SHA512_DIGEST_LENGTH;
    }
    return digest;
}

void simulate_hashes(const char *data) {
    HashSimulator hash_sim;
    hash_sim.data = data;
    hash_sim.hash_algorithms[0] = "md5";
    hash_sim.hash_algorithms[1] = "sha1";
    hash_sim.hash_algorithms[2] = "sha256";
    hash_sim.hash_algorithms[3] = "sha512";

    for (int i = 0; i < 4; i++) {
        unsigned int digest_length;
        unsigned char *digest = apply_hash(data, hash_sim.hash_algorithms[i], &digest_length);
        printf("%s: ", hash_sim.hash_algorithms[i]);
        for (int j = 0; j < digest_length; j++) {
            printf("%02x", digest[j]);
        }
        printf("\n");
        free(digest);
    }
}

unsigned char* xor_cipher(const char *data, const unsigned char *key, size_t data_length) {
    unsigned char *encrypted = (unsigned char *)malloc(data_length);
    for (size_t i = 0; i < data_length; i++) {
        encrypted[i] = data[i] ^ key[i % strlen((char *)key)];
    }
    return encrypted;
}

void simulate_ciphers(const char *data, const unsigned char *key) {
    CipherSimulator cipher_sim;
    cipher_sim.data = data;
    cipher_sim.key = key;

    unsigned char *encrypted = xor_cipher(data, key, strlen(data));
    printf("xor: ");
    for (size_t i = 0; i < strlen(data); i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");
    free(encrypted);
}

void mutate(const char *data) {
    DataMutator data_mutator;
    data_mutator.data = (const unsigned char *)data;
    data_mutator.key = (const unsigned char *)"secret";

    simulate_hashes(data);
    simulate_ciphers(data, data_mutator.key);
}

int main() {
    const char *data = "Sample data for cryptographic simulation";
    mutate(data);
    return 0;
}