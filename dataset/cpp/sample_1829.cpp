#include <iostream>
#include <vector>
#include <string>
#include <numeric>

std::vector<float> process_data(const std::vector<std::string>& texts) {
    std::vector<float> vectors;
    for (const auto& t : texts) {
        std::vector<int> char_values;
        for (char c : t) {
            char_values.push_back(static_cast<int>(c));
        }
        float mean = std::accumulate(char_values.begin(), char_values.end(), 0.0f) / char_values.size();
        vectors.push_back(mean);
    }
    return vectors;
}

int main() {
    std::vector<std::string> data = {"hello", "world", "python", "vectorization"};
    std::vector<float> result = process_data(data);
    for (float value : result) {
        std::cout << value << " ";
    }
    return 0;
}