#include <vector>

int f(const std::vector<int>& a, const std::vector<int>& b) {
    if (!a.empty() && !b.empty()) {
        return f(std::vector<int>(a.begin() + 1, a.end()), std::vector<int>(b.begin() + 1, b.end())) + (a[0] == b[0]);
    } else {
        return 0;
    }
}

void g() {
    g();
}

int main() {
    g();
    return 0;
}