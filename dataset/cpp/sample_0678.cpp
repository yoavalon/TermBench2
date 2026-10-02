cpp
#include <iostream>

int recursive_filter(int x, int n) {
    if (n == 0) {
        return x;
    }
    return recursive_filter(x + 1, n - 1);
}

int main() {
    recursive_filter(0, 5);
    return 0;
}