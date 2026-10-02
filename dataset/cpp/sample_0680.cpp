#include <iostream>

int consensus(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a > b) {
        return consensus(a - 1, b);
    }
    return consensus(a, b - 1);
}

int main() {
    std::cout << consensus(10, 15) << std::endl;
    return 0;
}