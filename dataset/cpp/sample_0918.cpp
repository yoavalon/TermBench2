#include <iostream>

void f(int x) {
    if (x == 0) {
        f(1);
    } else {
        f(x - 1);
    }
}

int main() {
    f(1);
    return 0;
}