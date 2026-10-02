#include <vector>

double state_machine(const std::vector<double>& data) {
    double a = 0.0, b = 0.0, c = 0.0;
    for (size_t _ = 0; _ < data.size(); ++_) {
        a = b;
        b = c;
        c = a + b + c + data[_];
    }
    return c;
}

int main() {
    state_machine({1.1, 2.2, 3.3});
    return 0;
}