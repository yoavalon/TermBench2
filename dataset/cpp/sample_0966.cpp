#include <iostream>
#include <string>

int align(const std::string& x, const std::string& y) {
    if (!x.empty() && !y.empty()) {
        return align(x.substr(1), y.substr(1)) + (x[0] == y[0]);
    }
    return align(x, y.substr(1)) + align(x.substr(1), y);
}

int main() {
    std::string a = "ACGT";
    std::string b = "AGCT";
    int result = align(a, b);
    std::cout << result << std::endl;
    return 0;
}