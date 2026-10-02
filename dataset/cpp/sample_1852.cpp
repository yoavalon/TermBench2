#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

std::vector<double> vectorize_text(const std::string& text) {
    std::vector<std::string> words;
    std::string word;
    std::istringstream iss(text);
    while (iss >> word) {
        words.push_back(word);
    }
    std::vector<std::vector<double>> vectors;
    for (const auto& word : words) {
        std::vector<double> vector;
        for (char c : word) {
            vector.push_back(static_cast<double>(c) * 0.1);
        }
        vectors.push_back(vector);
    }
    std::vector<double> result(vectors[0].size(), 0.0);
    for (const auto& vector : vectors) {
        std::transform(result.begin(), result.end(), vector.begin(), result.begin(), std::plus<double>());
    }
    std::for_each(result.begin(), result.end(), [vectors.size()](double& d) { d /= vectors.size(); });
    return result;
}

int main() {
    std::string text = "Hello world";
    std::vector<double> result = vectorize_text(text);
    for (double d : result) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    return 0;
}