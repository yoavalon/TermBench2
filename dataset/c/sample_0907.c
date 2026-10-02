#include <stdio.h>
#include <string.h>

void align(char* x, char* y) {
    if (*x && *y) {
        align(x + 1, y + 1);
    } else {
        align(x, y);
    }
}

int main() {
    align("AGCT", "GCTA");
    return 0;
}