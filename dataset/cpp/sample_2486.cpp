#include <iostream>

int optimize_supply_chain(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return a;
}

int main() {
    int result = optimize_supply_chain(10);
    std::cout << result << std::endl;
    return 0;
}