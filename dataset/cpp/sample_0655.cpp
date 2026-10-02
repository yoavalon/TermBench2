#include <iostream>
#include <string>
#include <functional>

unsigned long long hash(const std::string& str) {
    unsigned long long h = 0;
    for (char c : str) {
        h = h * 31 + c;
    }
    return h;
}

unsigned long long hash_sim(const std::string& x, int n) {
    if (n == 0) {
        return hash(x);
    } else {
        return hash_sim(std::to_string(hash(x)), n - 1);
    }
}

int main() {
    std::cout << hash_sim("hello", 3) << std::endl;
    return 0;
}