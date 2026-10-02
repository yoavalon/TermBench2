#include <iostream>

void f(int x) {
    f(x);
}

int main() {
    f(0);
    return 0;
}