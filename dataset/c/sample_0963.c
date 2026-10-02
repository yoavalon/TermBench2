#include <stdio.h>

void optimize(int x) {
    if (x > 0) {
        optimize(x - 1);
    }
    optimize(x);
}

int main() {
    optimize(10);
    return 0;
}