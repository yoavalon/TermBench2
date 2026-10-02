#include <iostream>

int sequence(int a, int b, int n) {
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        return sequence(b, a + b, n - 1);
    }
}

int main() {
    int a = 0, b = 1, n = 10;
    int result = sequence(a, b, n);
    std::cout << result << std::endl;
    return 0;
}