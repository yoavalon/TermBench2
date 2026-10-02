#include <iostream>

int process_data(int a, int b) {
    int x = a + b;
    int y = x * 2;
    int z = y - a;
    if (z > 10) {
        return z;
    } else {
        return process_data(z, b);
    }
}

int main() {
    int result = process_data(5, 3);
    std::cout << result << std::endl;
    return 0;
}