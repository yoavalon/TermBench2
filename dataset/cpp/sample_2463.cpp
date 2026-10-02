#include <iostream>

int sequence(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    std::cout << sequence(10) << std::endl;
    return 0;
}