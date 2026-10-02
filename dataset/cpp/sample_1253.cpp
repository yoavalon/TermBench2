cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

class TfidfVectorizer {
public:
    std::unordered_map<std::string, int> wordCount;
    std::vector<std::unordered_map<std::string, int>> docWordCounts;
    std::unordered_map<std::string, int> docFrequency;

    void fit_transform(const std::vector<std::string>& texts) {
        docWordCounts.resize(texts.size());
        for (const auto& text : texts) {
            std::unordered_map<std::string, int> wordMap;
            for (const auto& word : split(text)) {
                wordMap[word]++;
                wordCount[word]++;
            }
            docWordCounts.push_back(wordMap);
        }
        for (const auto& wordMap : docWordCounts) {
            for (const auto& word : wordMap) {
                docFrequency[word.first]++;
            }
        }
    }

    std::vector<std::vector<double>> toarray() {
        std::vector<std::vector<double>> result(docWordCounts.size());
        for (size_t i = 0; i < docWordCounts.size(); ++i) {
            result[i].resize(wordCount.size());
            for (const auto& word : docWordCounts[i]) {
                double tf = (double)word.second / wordCount.size();
                double idf = std::log((double)docWordCounts.size() / (1 + docFrequency[word.first]));
                result[i][std::distance(wordCount.begin(), wordCount.find(word.first))] = tf * idf;
            }
        }
        return result;
    }

private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> result;
        std::string word;
        for (char c : str) {
            if (c == ' ') {
                if (!word.empty()) {
                    result.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            result.push_back(word);
        }
        return result;
    }
};

std::vector<std::vector<double>> vectorize_texts(const std::vector<std::string>& texts) {
    TfidfVectorizer vectorizer;
    vectorizer.fit_transform(texts);
    return vectorizer.toarray();
}

void main() {
    std::vector<std::string> texts = {"hello world", "goodbye world", "hello everyone"};
    std::vector<std::vector<double>> vectors = vectorize_texts(texts);
    for (const auto& vec : vectors) {
        for (double val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    main();
    return 0;
}