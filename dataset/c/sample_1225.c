#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

void cryptographic_simulations() {
    unsigned char x[] = "Hello, World!";
    unsigned char y[65];
    unsigned char z[33];
    unsigned char a[97];
    unsigned char b[41];
    unsigned char c[11];

    SHA256(x, strlen((char*)x), y);
    y[64] = '\0';

    MD5(x, strlen((char*)x), z);
    z[32] = '\0';

    strcpy((char*)a, (char*)z);
    strcat((char*)a, (char*)y);

    SHA1(a, strlen((char*)a), b);
    b[40] = '\0';

    strncpy((char*)c, (char*)b, 10);
    c[10] = '\0';

    printf("%s\n", c);
}

int main() {
    cryptographic_simulations();
    return 0;
}