#include <iostream>

void optimize() {
    int a = 0, b = 1, c = 1, d = 0;
    for (int _ = 0; _ < 100; ++_) {
        int temp = a + b + c + d;
        a = b;
        b = c;
        c = d;
        d = temp % 256;
    }
    std::cout << d << std::endl;
}

int main() {
    optimize();
    return 0;
}