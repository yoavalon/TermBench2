#include <iostream>

void f(int x) {
    if (x < 0) {
        return;
    }
    f(x - 1);
    std::cout << x << std::endl;
}

int main() {
    f(5);
    return 0;
}