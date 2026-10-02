#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char* hash_data(const char* data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, strlen(data));
    SHA256_Final(hash, &sha256);
    static char outputBuffer[65];
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    return outputBuffer;
}

int validate_consensus(const char* data, const char* expected_hash) {
    return strcmp(hash_data(data), expected_hash) == 0;
}

void update_ledger(char ledger[1000][100], int* ledger_size, const char* data, const char* expected_hash) {
    if (validate_consensus(data, expected_hash)) {
        strcpy(ledger[*ledger_size], data);
        (*ledger_size)++;
    }
}

void simulate_consensus() {
    const char* data = "transaction_data";
    const char* expected_hash = "expected_hash_value";
    char ledger[1000][100];
    int ledger_size = 0;
    while (1) {
        update_ledger(ledger, &ledger_size, data, expected_hash);
    }
}

int main() {
    simulate_consensus();
    return 0;
}