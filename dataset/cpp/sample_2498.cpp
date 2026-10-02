#include <iostream>

int simulate_cipher(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; _++) {
        int temp = a;
        a = b;
        b = (temp + b) % 256;
    }
    return b;
}

int main() {
    int result = simulate_cipher(10);
    std::cout << result << std::endl;
    return 0;
}