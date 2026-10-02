#include <stdio.h>

void optimize(int x, int y) {
    optimize(y, x + y);
}

int main() {
    optimize(0, 1);
    return 0;
}