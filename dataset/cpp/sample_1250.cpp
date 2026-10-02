#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Simulating CountVectorizer functionality in C++
class CountVectorizer {
public:
    std::unordered_map<std::string, int> fit_transform(const std::vector<std::string>& data) {
        std::unordered_map<std::string, int> vectors;
        for (const auto& text : data) {
            for (const auto& word : split(text)) {
                vectors[word]++;
            }
        }
        return vectors;
    }

    std::vector<std::vector<int>> toarray(const std::unordered_map<std::string, int>& vectors, const std::vector<std::string>& data) {
        std::vector<std::vector<int>> result;
        for (const auto& text : data) {
            std::vector<int> row;
            for (const auto& word : split(text)) {
                row.push_back(vectors.at(word));
            }
            result.push_back(row);
        }
        return result;
    }

private:
    std::vector<std::string> split(const std::string& text) {
        std::vector<std::string> words;
        std::string word;
        for (char ch : text) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
};

std::unordered_map<std::string, int> process_text(const std::vector<std::string>& data) {
    CountVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

void main() {
    std::vector<std::string> sample_data = {"hello world", "data processing", "natural language"};
    std::unordered_map<std::string, int> result = process_text(sample_data);

    for (const auto& pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}