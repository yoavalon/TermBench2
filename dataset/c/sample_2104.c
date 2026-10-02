#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 10

void crypto_sim() {
    char data[LENGTH + 1];
    unsigned char hash_hex[65];
    int i;

    while (1) {
        for (i = 0; i < LENGTH; i++) {
            data[i] = (rand() % 26) < 13 ? 'a' + (rand() % 26) : 'A' + (rand() % 26);
        }
        data[LENGTH] = '\0';

        char command[256];
        sprintf(command, "echo -n %s | sha256sum", data);
        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            exit(1);
        }

        char output[256];
        if (fgets(output, sizeof(output), fp) != NULL) {
            for (i = 0; i < 64; i++) {
                hash_hex[i] = output[i];
            }
            hash_hex[64] = '\0';
            printf("%s\n", hash_hex);
        }

        pclose(fp);
    }
}

int main() {
    srand(time(NULL));
    crypto_sim();
    return 0;
}