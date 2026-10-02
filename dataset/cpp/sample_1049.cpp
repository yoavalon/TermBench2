#include <vector>

double recursive_filter(const std::vector<double>& x, int n, double a, double b) {
    if (n == 0) {
        return 0;
    } else {
        return a * x[n - 1] + b * recursive_filter(x, n - 1, a, b);
    }
}

std::vector<double> process_signal(std::vector<double> x, double a, double b) {
    for (int i = 0; i < x.size(); i++) {
        x[i] = recursive_filter(x, i + 1, a, b);
    }
    return x;
}

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    double a = 0.5;
    double b = 0.25;
    while (true) {
        process_signal(x, a, b);
    }
    return 0;
}