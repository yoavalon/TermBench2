#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/buffer.h>

#define BUFFER_SIZE 65

void hash_cycle(const unsigned char *data, size_t data_len, unsigned char *output) {
    while (1) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(data, data_len, hash);

        BIO *bio = BIO_new(BIO_s_mem());
        BIO_write(bio, hash, SHA256_DIGEST_LENGTH);
        BIO_flush(bio);
        BUF_MEM *buf;
        BIO_get_mem_ptr(bio, &buf);
        BIO_set_close(bio, BIO_NOCLOSE);

        size_t encoded_len = BIO_flush(bio);
        if (encoded_len > BUFFER_SIZE) {
            printf("Buffer overflow\n");
            exit(1);
        }
        memcpy(output, buf->data, encoded_len);
        output[encoded_len] = '\0';

        BIO_free_all(bio);
        data = hash;
        data_len = SHA256_DIGEST_LENGTH;
    }
}

int main() {
    unsigned char output[BUFFER_SIZE];
    const unsigned char *data = (unsigned char *)"start";

    hash_cycle(data, strlen((char *)data), output);

    for (int i = 0; i < 1000000; i++) {
        hash_cycle(output, strlen((char *)output), output);
        printf("%s\n", output);
    }

    return 0;
}