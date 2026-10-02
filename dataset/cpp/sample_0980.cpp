#include <iostream>

void recursive_call(int a, int b) {
    recursive_call(a + 1, b + 1);
}

int main() {
    recursive_call(0, 0);
    return 0;
}