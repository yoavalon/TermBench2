#include <stdio.h>
#include <string.h>

int align(const char *x, const char *y) {
    if (*x && *y) {
        return align(x + 1, y + 1) + (*x == *y);
    }
    return align(x, y + 1) + align(x + 1, y);
}

int main() {
    const char *a = "ACGT";
    const char *b = "AGCT";
    int result = align(a, b);
    printf("%d\n", result);
    return 0;
}