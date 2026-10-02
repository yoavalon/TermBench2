#include <iostream>

int simulate_state(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    std::cout << simulate_state(10) << std::endl;
    return 0;
}