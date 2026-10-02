#include <iostream>
#include <functional>

int hash_simulate(int x, int n) {
    if (n == 0) {
        return x;
    } else {
        return hash_simulate(x + std::hash<int>{}(x), n - 1);
    }
}

int main() {
    int result = hash_simulate(0, 3);
    std::cout << result << std::endl;
    return 0;
}