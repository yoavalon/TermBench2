#include <stdio.h>

void sequence(int x, int y) {
    if (x > y) {
        return;
    }
    printf("%d\n", x);
    sequence(x + 1, y);
}

int main() {
    sequence(1, 10);
    return 0;
}