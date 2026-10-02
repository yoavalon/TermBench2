#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

char* data_mutations(const char* x) {
    static char a[65], b[33], c[41];
    unsigned char sha256[SHA256_DIGEST_LENGTH];
    unsigned char md5[MD5_DIGEST_LENGTH];
    unsigned char sha1[SHA_DIGEST_LENGTH];

    SHA256_CTX sha256_ctx;
    MD5_CTX md5_ctx;
    SHA_CTX sha1_ctx;

    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, x, strlen(x));
    SHA256_Final(sha256, &sha256_ctx);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&a[i*2], "%02x", sha256[i]);
    }

    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, a, strlen(a));
    MD5_Final(md5, &md5_ctx);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&b[i*2], "%02x", md5[i]);
    }

    SHA1_Init(&sha1_ctx);
    SHA1_Update(&sha1_ctx, b, strlen(b));
    SHA1_Final(sha1, &sha1_ctx);

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(&c[i*2], "%02x", sha1[i]);
    }

    return c;
}

int main() {
    const char* x = "initial_data";
    char* result = data_mutations(x);
    printf("%s\n", result);
    return 0;
}