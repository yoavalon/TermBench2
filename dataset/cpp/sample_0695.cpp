#include <iostream>

int simulate_cipher(int data, int key, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return simulate_cipher(data ^ key, key, depth - 1);
    }
}

int main() {
    int data = 305419896;
    int key = 2596069104;
    int depth = 5;
    int result = simulate_cipher(data, key, depth);
    std::cout << result << std::endl;
    return 0;
}