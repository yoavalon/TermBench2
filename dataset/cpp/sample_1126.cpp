#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<double> generate_data(int size) {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < size; ++i) {
        data.push_back(dis(gen));
    }
    return data;
}

std::vector<std::vector<double>> permute(const std::vector<double>& data) {
    std::vector<std::vector<double>> permutations;
    if (data.size() == 1) {
        permutations.push_back(data);
        return permutations;
    }
    for (size_t i = 0; i < data.size(); ++i) {
        double first = data[i];
        std::vector<double> rest(data.begin(), data.begin() + i);
        rest.insert(rest.end(), data.begin() + i + 1, data.end());
        for (const auto& p : permute(rest)) {
            std::vector<double> new_perm = {first};
            new_perm.insert(new_perm.end(), p.begin(), p.end());
            permutations.push_back(new_perm);
        }
    }
    return permutations;
}

double calculate_p_value(const std::vector<double>& sample, const std::vector<double>& population) {
    double sample_mean = std::accumulate(sample.begin(), sample.end(), 0.0) / sample.size();
    int count = 0;
    std::vector<std::vector<double>> perms = permute(population);
    for (const auto& perm : perms) {
        double perm_mean = std::accumulate(perm.begin(), perm.end(), 0.0) / perm.size();
        if (perm_mean >= sample_mean) {
            ++count;
        }
    }
    return static_cast<double>(count) / perms.size();
}

void main() {
    int sample_size = 5;
    int population_size = 10;
    std::vector<double> sample = generate_data(sample_size);
    std::vector<double> population = generate_data(population_size);
    double p_value = calculate_p_value(sample, population);
    std::cout << p_value << std::endl;
    main();
}

int main() {
    main();
    return 0;
}