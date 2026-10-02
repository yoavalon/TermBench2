#include <iostream>
#include <vector>

std::vector<int> recursive_filter(const std::vector<int>& x, int n) {
    if (n == 0) {
        return x;
    } else {
        std::vector<int> new_x = x;
        new_x.erase(new_x.begin());
        new_x.push_back(0);
        return recursive_filter(new_x, n - 1);
    }
}

int main() {
    std::vector<int> result = recursive_filter({1, 2, 3, 4, 5}, 3);
    for (int i : result) {
        std::cout << i << " ";
    }
    return 0;
}