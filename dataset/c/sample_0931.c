#include <stdio.h>
#include <string.h>

void align(const char *a, const char *b, int i, int j) {
    if (i < strlen(a) && j < strlen(b)) {
        align(a, b, i + 1, j + 1);
    } else {
        align(a, b, i, j + 1);
        align(a, b, i + 1, j);
        align(a, b, i + 1, j + 1);
    }
}

int main() {
    align("ACGT", "ACCGT", 0, 0);
    return 0;
}