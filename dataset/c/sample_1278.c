#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int validators[4];
    int validator_count;
    char data[10];
    char status[10];
} Block;

void process_blockchain(Block blockchain[], int validator_set[], int threshold, int blockchain_size) {
    for (int i = 0; i < blockchain_size; i++) {
        int valid_count = 0;
        for (int j = 0; j < blockchain[i].validator_count; j++) {
            for (int k = 0; k < 4; k++) {
                if (blockchain[i].validators[j] == validator_set[k]) {
                    valid_count++;
                    break;
                }
            }
        }
        if (valid_count >= threshold) {
            snprintf(blockchain[i].status, 10, "valid");
        } else {
            snprintf(blockchain[i].status, 10, "invalid");
        }
    }
}

int main() {
    Block blockchain[2] = {
        {{1, 2, 3}, 3, "tx1", "pending"},
        {{2, 4}, 2, "tx2", "pending"}
    };
    int validator_set[4] = {1, 2, 3, 4};
    int threshold = 3;
    int blockchain_size = 2;

    process_blockchain(blockchain, validator_set, threshold, blockchain_size);

    for (int i = 0; i < blockchain_size; i++) {
        printf("{validators: [");
        for (int j = 0; j < blockchain[i].validator_count; j++) {
            printf("%d", blockchain[i].validators[j]);
            if (j < blockchain[i].validator_count - 1) {
                printf(", ");
            }
        }
        printf("], data: '%s', status: '%s'}\n", blockchain[i].data, blockchain[i].status);
    }

    return 0;
}