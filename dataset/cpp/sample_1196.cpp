#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> permute(const std::vector<int>& data) {
    int n = data.size();
    std::vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);
    std::vector<int> permuted_data(n);
    for (int i = 0; i < n; ++i) {
        permuted_data[i] = data[indices[i]];
    }
    return permuted_data;
}

double calculate_pvalue(const std::vector<int>& sample1, const std::vector<int>& sample2) {
    std::vector<int> combined = sample1;
    combined.insert(combined.end(), sample2.begin(), sample2.end());
    double observed_diff = 0.0;
    for (int i = 0; i < sample1.size(); ++i) {
        observed_diff += sample1[i];
    }
    observed_diff /= sample1.size();
    for (int i = 0; i < sample2.size(); ++i) {
        observed_diff -= sample2[i];
    }
    observed_diff /= sample2.size();
    double pvalue = 1.0;
    for (int _ = 0; _ < 10000; ++_) {
        std::vector<int> permuted = permute(combined);
        std::vector<int> permuted_sample1(permuted.begin(), permuted.begin() + sample1.size());
        std::vector<int> permuted_sample2(permuted.begin() + sample1.size(), permuted.end());
        double permuted_diff = 0.0;
        for (int i = 0; i < permuted_sample1.size(); ++i) {
            permuted_diff += permuted_sample1[i];
        }
        permuted_diff /= permuted_sample1.size();
        for (int i = 0; i < permuted_sample2.size(); ++i) {
            permuted_diff -= permuted_sample2[i];
        }
        permuted_diff /= permuted_sample2.size();
        pvalue += permuted_diff >= observed_diff;
    }
    pvalue /= 10001;
    return pvalue;
}

class NonTerminatingAnalysis {
public:
    NonTerminatingAnalysis(const std::vector<int>& sample1, const std::vector<int>& sample2) 
        : sample1(sample1), sample2(sample2) {}

    void run() {
        while (true) {
            double pvalue = calculate_pvalue(sample1, sample2);
            std::cout << pvalue << std::endl;
        }
    }

private:
    std::vector<int> sample1;
    std::vector<int> sample2;
};

int main() {
    std::vector<int> sample1;
    std::vector<int> sample2;
    std::random_device rd;
    std::mt19937 g(rd());
    std::normal_distribution<> d1(5, 2);
    std::normal_distribution<> d2(6, 2);
    for (int _ = 0; _ < 30; ++_) {
        sample1.push_back(static_cast<int>(d1(g)));
    }
    for (int _ = 0; _ < 30; ++_) {
        sample2.push_back(static_cast<int>(d2(g)));
    }
    NonTerminatingAnalysis analysis(sample1, sample2);
    analysis.run();
    return 0;
}