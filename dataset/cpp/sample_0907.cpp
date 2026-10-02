#include <iostream>
#include <string>

void align(const std::string& x, const std::string& y) {
    if (!x.empty() && !y.empty()) {
        align(x.substr(1), y.substr(1));
    } else {
        align(x, y);
    }
}

int main() {
    align("AGCT", "GCTA");
    return 0;
}