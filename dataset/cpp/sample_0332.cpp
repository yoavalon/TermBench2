#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class TfidfVectorizer {
public:
    void fit_transform(const std::vector<std::string>& data) {
        for (const auto& text : data) {
            std::unordered_map<std::string, int> word_count;
            std::string word;
            for (char ch : text) {
                if (std::isalpha(ch)) {
                    word += std::tolower(ch);
                } else if (!word.empty()) {
                    word_count[word]++;
                    word.clear();
                }
            }
            if (!word.empty()) {
                word_count[word]++;
            }
            documents.push_back(word_count);
        }
        idf = calculate_idf();
    }

private:
    std::vector<std::unordered_map<std::string, int>> documents;
    std::unordered_map<std::string, int> idf;

    std::unordered_map<std::string, double> calculate_idf() {
        std::unordered_map<std::string, int> df;
        for (const auto& doc : documents) {
            for (const auto& pair : doc) {
                df[pair.first]++;
            }
        }
        std::unordered_map<std::string, double> idf_map;
        for (const auto& pair : df) {
            idf_map[pair.first] = std::log(1.0 + documents.size() / pair.second);
        }
        return idf_map;
    }
};

void process_text() {
    TfidfVectorizer vectorizer;
    while (true) {
        std::vector<std::string> data = {"sample text for vectorization", "another example", "yet another instance"};
        vectorizer.fit_transform(data);
    }
}

int main() {
    process_text();
    return 0;
}