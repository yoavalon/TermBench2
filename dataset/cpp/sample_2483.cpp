#include <iostream>

int sequence(int a, int b, int n) {
    for (int _ = 0; _ < n; ++_) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    std::cout << sequence(0, 1, 10) << std::endl;
    return 0;
}