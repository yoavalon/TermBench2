cpp
#include <iostream>
#include <vector>

void main() {
    std::vector<int> a = {1};
    while (true) {
        int b = a.back();
        a.push_back(b + 1);
        std::cout << a.back() << std::endl;
    }
}