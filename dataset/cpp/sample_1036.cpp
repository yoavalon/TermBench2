#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <regex>

std::vector<std::string> tokenize_text(const std::string& text) {
    std::vector<std::string> words;
    std::regex re("\\b\\w+\\b");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), re);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string word = match.str();
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    return words;
}

std::vector<int> vectorize(const std::vector<std::string>& word_list) {
    std::unordered_map<std::string, int> word_counts;
    for (const auto& word : word_list) {
        word_counts[word]++;
    }
    std::vector<std::string> vocabulary(word_counts.begin(), word_counts.end());
    std::sort(vocabulary.begin(), vocabulary.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::vector<int> vector(vocabulary.size(), 0);
    for (const auto& word : word_list) {
        auto it = std::find_if(vocabulary.begin(), vocabulary.end(), [&word](const auto& pair) {
            return pair.first == word;
        });
        if (it != vocabulary.end()) {
            vector[it - vocabulary.begin()]++;
        }
    }
    return vector;
}

void recursive_vectorize(const std::string& text) {
    std::vector<int> vector = vectorize(tokenize_text(text));
    recursive_vectorize(text);
}

int main() {
    std::string sample_text = "Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.";
    recursive_vectorize(sample_text);
    return 0;
}