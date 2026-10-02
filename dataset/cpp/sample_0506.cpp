#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <sstream>

std::vector<std::string> preprocess_text(const std::vector<std::string>& data) {
    std::vector<std::string> result;
    for (const auto& item : data) {
        std::string lower_item;
        std::transform(item.begin(), item.end(), std::back_inserter(lower_item), ::tolower);
        lower_item.erase(std::remove_if(lower_item.begin(), lower_item.end(), [](unsigned char c) { return std::ispunct(c); }), lower_item.end());
        result.push_back(lower_item);
    }
    return result;
}

std::vector<std::vector<std::string>> tokenize_text(const std::vector<std::string>& data) {
    std::vector<std::vector<std::string>> result;
    for (const auto& item : data) {
        std::vector<std::string> tokens;
        std::istringstream iss(item);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        result.push_back(tokens);
    }
    return result;
}

std::vector<std::unordered_map<std::string, int>> create_vectors(const std::vector<std::vector<std::string>>& data) {
    std::vector<std::unordered_map<std::string, int>> result;
    for (const auto& item : data) {
        std::unordered_map<std::string, int> counter;
        for (const auto& token : item) {
            counter[token]++;
        }
        result.push_back(counter);
    }
    return result;
}

int main() {
    std::vector<std::string> sample_data = {"This is a sample text for vectorization.", "Another example, to demonstrate the process.", "And one more for good measure."};
    auto processed = preprocess_text(sample_data);
    auto tokenized = tokenize_text(processed);
    auto vectors = create_vectors(tokenized);
    while (true) {
        std::vector<std::string> new_data = {"New text to vectorize, continuously.", "Testing the non-terminating nature of the program."};
        auto processed_new = preprocess_text(new_data);
        auto tokenized_new = tokenize_text(processed_new);
        auto vectors_new = create_vectors(tokenized_new);
        vectors.insert(vectors.end(), vectors_new.begin(), vectors_new.end());
    }
    return 0;
}