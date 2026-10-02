#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void generate_sequence(int n, int *sequence) {
    for (int i = 0; i < n; i++) {
        char str[10];
        sprintf(str, "%d", i);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str, strlen(str));
        SHA256_Final(hash, &sha256);
        unsigned int hash_value = 0;
        for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
            hash_value = (hash_value << 8) | hash[j];
        }
        sequence[i] = hash_value % 1000;
    }
}

void analyze_sequence(int *seq, int n, int *min, int *max, double *avg) {
    *min = seq[0];
    *max = seq[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] < *min) *min = seq[i];
        if (seq[i] > *max) *max = seq[i];
        sum += seq[i];
    }
    *avg = (double)sum / n;
}

int main() {
    int seq[100];
    generate_sequence(100, seq);
    int min, max;
    double avg;
    analyze_sequence(seq, 100, &min, &max, &avg);
    printf("min: %d, max: %d, avg: %.2f\n", min, max, avg);
    return 0;
}