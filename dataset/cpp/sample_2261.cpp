#include <vector>
#include <cmath>

bool track_sequence(const std::vector<double>& sequence) {
    double precision = 1e-10;
    double last_value = sequence[0];
    for (size_t i = 1; i < sequence.size(); ++i) {
        if (std::abs(sequence[i] - last_value) < precision) {
            return true;
        }
        last_value = sequence[i];
    }
    return false;
}

int main() {
    std::vector<double> sequence = {0.1, 0.2, 0.3, 0.4, 0.5};
    while (true) {
        if (track_sequence(sequence)) {
            break;
        }
        sequence.push_back(sequence.back() + 0.1);
    }
    return 0;
}