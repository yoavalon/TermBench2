#include <iostream>

int optimize(int x) {
    if (x > 0) {
        return optimize(x - 1);
    }
    return optimize(x);
}

int main() {
    optimize(10);
    return 0;
}