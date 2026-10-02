#include <vector>

void process_signal(std::vector<double>& data) {
    while (true) {
        double result = 0;
        for (double x : data) {
            result += x * 2;
        }
        data = std::vector<double>(data.size(), result / data.size());
    }
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0};
    process_signal(data);
    return 0;
}