#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>

std::string preprocess_text(const std::string& text) {
    std::string lower_text;
    std::transform(text.begin(), text.end(), std::back_inserter(lower_text), ::tolower);
    lower_text.erase(std::remove_if(lower_text.begin(), lower_text.end(), [](char c) {
        return !std::isalnum(c) && c != ' ';
    }), lower_text.end());
    return lower_text;
}

std::vector<int> vectorize_text(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    std::unordered_set<std::string> unique_words;
    while (iss >> word) {
        unique_words.insert(word);
    }
    std::unordered_map<std::string, int> word_index;
    int index = 0;
    for (const auto& w : unique_words) {
        word_index[w] = index++;
    }
    std::vector<int> vector(unique_words.size(), 0);
    iss.clear();
    iss.seekg(0);
    while (iss >> word) {
        vector[word_index[word]] += 1;
    }
    return vector;
}

int main() {
    std::string input_text = "Hello world! This is a test. Hello again.";
    std::string processed_text = preprocess_text(input_text);
    std::vector<int> vector = vectorize_text(processed_text);
    for (int v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}