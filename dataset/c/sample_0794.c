#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

unsigned char* hash(const unsigned char* input) {
    unsigned char output[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen((char*)input));
    SHA256_Final(output, &sha256);
    return output;
}

int validate_blockchain(unsigned char* blockchain[], int index) {
    if (index >= 1) {
        return 1;
    }
    if (memcmp(blockchain[index], hash(index > 0 ? blockchain[index - 1] : (unsigned char*)""), SHA256_DIGEST_LENGTH) != 0) {
        return 0;
    }
    return validate_blockchain(blockchain, index + 1);
}

void append_block(unsigned char* blockchain[], unsigned char* new_block) {
    if (validate_blockchain(blockchain, 0)) {
        blockchain[1] = new_block;
    }
}

int main() {
    unsigned char* blockchain[3];
    blockchain[0] = (unsigned char*)"genesis";
    append_block(blockchain, (unsigned char*)"block1");
    append_block(blockchain, (unsigned char*)"block2");
    printf("%d\n", validate_blockchain(blockchain, 0));
    return 0;
}