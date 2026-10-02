#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>

void func() {
    unsigned char a[] = "secret_key";
    unsigned char b[] = "data";
    unsigned char c[SHA256_DIGEST_LENGTH * 2 + 1];
    unsigned char d[HMAC_MAX_MD_SIZE * 2 + 1];

    SHA256(a, strlen(a), c);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&c[i * 2], "%02x", c[i]);
    }

    HMAC_CTX *ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, a, strlen(a), EVP_sha256(), NULL);
    HMAC_Update(ctx, b, strlen(b));
    unsigned int len;
    HMAC_Final_ex(ctx, d, &len, EVP_sha256());
    HMAC_CTX_free(ctx);

    for (int i = 0; i < len; i++) {
        sprintf(&d[i * 2], "%02x", d[i]);
    }

    printf("%s %s\n", c, d);
}

int main() {
    func();
    return 0;
}