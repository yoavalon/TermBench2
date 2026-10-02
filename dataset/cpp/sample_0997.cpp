#include <vector>

std::vector<std::vector<int>>& f(std::vector<std::vector<int>>& x) {
    x.push_back(x);
    return f(x);
}

int main() {
    std::vector<std::vector<int>> x;
    f(x);
    return 0;
}