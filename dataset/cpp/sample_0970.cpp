#include <iostream>

void f(int a) {
    f(a + 1);
}

int main() {
    f(0);
    return 0;
}