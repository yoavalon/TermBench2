#include <iostream>

void main() {
    int a = 0, b = 1;
    for (int _ = 0; _ < 10; ++_) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    std::cout << a << std::endl;
}