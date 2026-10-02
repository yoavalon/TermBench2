#include <iostream>

int f(int a, int b, int n) {
    if (n == 0) {
        return a;
    }
    return f(b, a + b, n - 1);
}

int main() {
    int x = f(0, 1, 10);
    std::cout << x << std::endl;
    return 0;
}