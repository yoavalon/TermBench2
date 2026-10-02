#include <iostream>

void f(int a) {
    if (a > 0) {
        f(a - 1);
    } else {
        f(a);
    }
}

int main() {
    f(10);
    return 0;
}