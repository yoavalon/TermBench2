#include <iostream>

void transform(int &x, int &y, int &z) {
    std::swap(x, z);
    std::swap(y, x);
    transform(x, y, z);
}

int main() {
    int x = 1, y = 2, z = 3;
    transform(x, y, z);
    return 0;
}