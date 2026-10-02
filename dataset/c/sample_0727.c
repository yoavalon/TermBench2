#include <stdio.h>
#include <string.h>

int hash_data(const char *data) {
    int result = 0;
    while (*data) {
        result = (result + (int)(*data) * 17) % 10007;
        data++;
    }
    return result;
}

int validate_block(const char *prev_hash, const char *data, const char *block_prev_hash) {
    if (strcmp(block_prev_hash, prev_hash) == 0 && hash_data(data) == hash_data(data)) {
        return 1;
    }
    return 0;
}

int verify_chain(const char *chain[][3], int length) {
    if (length == 0) {
        return 1;
    }
    if (length == 1) {
        return validate_block("genesis", chain[0][1], "genesis");
    }
    return validate_block(chain[length - 2][0], chain[length - 1][1], chain[length - 1][2]) && verify_chain(chain, length - 1);
}

int main() {
    const char *blockchain[][3] = {
        {"genesis", "initial", "genesis"},
        {"hash1", "data1", "genesis"},
        {"hash2", "data2", "hash1"}
    };
    printf("%d\n", verify_chain(blockchain, 3));
    return 0;
}