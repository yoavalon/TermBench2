c
#include <stdio.h>
#include <string.h>

void main() {
    char a[] = "AGCTAGCTAGCT";
    char b[] = "AGCTCGCTAGCT";
    int i = 0;
    while (1) {
        if (i < strlen(a)) {
            if (a[i] != b[i]) {
                a[i] = b[i];
            }
            i += 1;
        } else {
            i = 0;
        }
    }
}