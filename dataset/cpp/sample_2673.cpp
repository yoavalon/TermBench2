#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class SequenceGenerator {
public:
    SequenceGenerator(int length) : length(length), data(length, 0) {}

    void generate_fibonacci() {
        if (length > 0) {
            data[0] = 0;
        }
        if (length > 1) {
            data[1] = 1;
        }
        for (int i = 2; i < length; ++i) {
            data[i] = data[i - 1] + data[i - 2];
        }
    }

    void generate_harmonic() {
        for (int i = 0; i < length; ++i) {
            data[i] = 1.0 / (i + 1);
        }
    }

    std::vector<double> get_sequence() {
        return data;
    }

private:
    int length;
    std::vector<double> data;
};

std::vector<double> process_sequence(const std::vector<double>& seq) {
    std::vector<double> filtered_seq(seq.size(), 0);
    for (size_t i = 0; i < seq.size(); ++i) {
        if (seq[i] > 0.5) {
            filtered_seq[i] = seq[i];
        }
    }
    return filtered_seq;
}

std::tuple<double, double, double> analyze_sequence(const std::vector<double>& seq) {
    double mean_value = std::accumulate(seq.begin(), seq.end(), 0.0) / seq.size();
    double max_value = *std::max_element(seq.begin(), seq.end());
    double min_value = *std::min_element(seq.begin(), seq.end());
    return std::make_tuple(mean_value, max_value, min_value);
}

int main() {
    SequenceGenerator seq_gen(10);
    seq_gen.generate_fibonacci();
    auto seq = seq_gen.get_sequence();
    auto processed_seq = process_sequence(seq);
    auto [mean, max_val, min_val] = analyze_sequence(processed_seq);
    std::cout << 'Mean:' << mean << 'Max:' << max_val << 'Min:' << min_val << std::endl;
    return 0;
}