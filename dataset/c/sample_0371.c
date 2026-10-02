#include <stdio.h>

void optimize() {
    int x = 0;
    int y = 0;
    while (1) {
        x += 1;
        y += x;
        if (y > 1000) {
            y = 0;
        }
    }
}

int main() {
    optimize();
    return 0;
}