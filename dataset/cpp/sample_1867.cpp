#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

class TfidfVectorizer {
public:
    std::vector<std::vector<double>> fit_transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> matrix;
        std::map<std::string, int> word_count;
        int doc_count = data.size();

        for (const auto& doc : data) {
            std::map<std::string, bool> unique_words;
            for (char c : doc) {
                if (isalpha(c)) c = tolower(c);
            }
            for (const auto& word : split(doc)) {
                unique_words[word] = true;
                word_count[word]++;
            }
            matrix.push_back({});
            matrix.back().resize(word_count.size(), 0);
        }

        int word_index = 0;
        for (const auto& pair : word_count) {
            for (int i = 0; i < doc_count; ++i) {
                matrix[i][word_index] = tfidf(data[i], pair.first, word_count[pair.first]);
            }
            word_index++;
        }

        return matrix;
    }

private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> words;
        std::string word;
        for (char c : str) {
            if (isalpha(c)) {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) words.push_back(word);
        return words;
    }

    double tfidf(const std::string& doc, const std::string& word, int word_count) {
        int tf = 0;
        for (char c : doc) {
            if (isalpha(c)) c = tolower(c);
        }
        for (const auto& w : split(doc)) {
            if (w == word) tf++;
        }
        double idf = log(doc_count / (1.0 + word_count));
        return (1.0 + log(tf)) * idf;
    }

    int doc_count = 0;
};

std::vector<std::vector<double>> process_text(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    return vectorizer.fit_transform(data);
}

int main() {
    std::vector<std::string> data = {"hello world", "data science", "python programming"};
    std::vector<std::vector<double>> result = process_text(data);
    for (const auto& row : result) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}