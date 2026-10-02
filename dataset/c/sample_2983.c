#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char current_value[65];
} HashSequence;

void HashSequence_init(HashSequence *self, const char *initial_value) {
    strncpy(self->current_value, initial_value, 64);
    self->current_value[64] = '\0';
}

char* HashSequence_update(HashSequence *self) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, self->current_value, strlen(self->current_value));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&self->current_value[i * 2], "%02x", hash[i]);
    }
    return self->current_value;
}

typedef struct {
    HashSequence *hash_sequence;
} CipherSimulator;

void CipherSimulator_init(CipherSimulator *self, HashSequence *hash_sequence) {
    self->hash_sequence = hash_sequence;
}

char* CipherSimulator_encrypt(CipherSimulator *self) {
    static char encrypted_value[129];
    for (int i = 0; i < strlen(self->hash_sequence->current_value); i++) {
        encrypted_value[i] = (self->hash_sequence->current_value[i] + 3) % 256;
    }
    encrypted_value[strlen(self->hash_sequence->current_value)] = '\0';
    return encrypted_value;
}

typedef struct {
    CipherSimulator *cipher_simulator;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, CipherSimulator *cipher_simulator) {
    self->cipher_simulator = cipher_simulator;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *self) {
    while (1) {
        char *hashed_value = HashSequence_update(self->cipher_simulator->hash_sequence);
        char *encrypted_value = CipherSimulator_encrypt(self->cipher_simulator);
        printf("Hashed: %s\nEncrypted: %s\n", hashed_value, encrypted_value);
    }
}

int main() {
    const char *initial_value = "seed_value";
    HashSequence hash_sequence;
    HashSequence_init(&hash_sequence, initial_value);
    CipherSimulator cipher_simulator;
    CipherSimulator_init(&cipher_simulator, &hash_sequence);
    SequenceAnalyzer sequence_analyzer;
    SequenceAnalyzer_init(&sequence_analyzer, &cipher_simulator);
    SequenceAnalyzer_analyze(&sequence_analyzer);
    return 0;
}