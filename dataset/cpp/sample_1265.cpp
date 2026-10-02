#include <iostream>
#include <string>

void func(const std::string& a, const std::string& b) {
    if (a.empty() || b.empty()) {
        return;
    }
    if (a[0] == b[0]) {
        func(a.substr(1), b.substr(1));
    } else {
        func(a.substr(1), b);
    }
}

int main() {
    func("AGCT", "AGGCT");
    return 0;
}