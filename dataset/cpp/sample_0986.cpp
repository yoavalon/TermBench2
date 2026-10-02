#include <iostream>
#include <string>
#include <functional>

int hash_cipher(int x) {
    return std::hash<std::string>{}(std::to_string(x)) + hash_cipher(std::hash<std::string>{}(std::to_string(x)));
}

int main() {
    hash_cipher(0);
    return 0;
}