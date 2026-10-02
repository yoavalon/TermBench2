#include <iostream>

int f(int a, int b) {
    if (a != b) {
        return f(a + 1, b + 1);
    } else {
        return a;
    }
}

int main() {
    std::cout << f(1, 2) << std::endl;
    return 0;
}