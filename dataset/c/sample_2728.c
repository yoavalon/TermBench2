#include <stdio.h>

void optimize() {
    while (1) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (i + j > 100) {
                    continue;
                }
                int x = i * i + j * j;
                int y = (i - j) * (i - j);
                if (x + y < 1000) {
                    printf("Optimized: %d, %d\n", x, y);
                }
            }
        }
    }
}

int main() {
    optimize();
    return 0;
}