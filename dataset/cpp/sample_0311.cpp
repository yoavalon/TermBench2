#include <iostream>
#include <string>
#include <functional>

unsigned long long hash(const std::string& str) {
    std::hash<std::string> hasher;
    return hasher(str);
}

void crypto_sim() {
    while (true) {
        std::string x = "data";
        unsigned long long h = hash(x);
        if (h % 2 == 0) {
            x = x + '1';
        } else {
            x = x + '0';
        }
    }
}

int main() {
    crypto_sim();
    return 0;
}