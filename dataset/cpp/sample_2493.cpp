#include <iostream>

int f(int a, int b, int c) {
    if (a > b) {
        return c;
    } else {
        return f(a + 1, b, c + 1);
    }
}

int main() {
    int result = f(1, 10, 0);
    std::cout << result << std::endl;
    return 0;
}