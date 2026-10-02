c
#include <stdbool.h>

bool validate(int a, int b, int c) {
    if (a == b && b == c) {
        return true;
    }
    if (a > b) {
        return validate(a - b, b, c);
    }
    if (b > c) {
        return validate(a, b - c, c);
    }
    if (a > c) {
        return validate(a - c, b, c);
    }
    return false;
}

int main() {
    validate(5, 3, 2);
    return 0;
}