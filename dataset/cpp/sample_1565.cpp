#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>

class TfidfVectorizer {
public:
    void fit_transform(const std::vector<std::string>& data) {
        idf = calculate_idf(data);
        tfidf = calculate_tfidf(data);
    }

    void print() const {
        for (const auto& row : tfidf) {
            for (double val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::unordered_map<std::string, int> doc_freq;
    std::unordered_map<std::string, double> idf;
    std::vector<std::vector<double>> tfidf;

    std::unordered_map<std::string, double> calculate_idf(const std::vector<std::string>& data) {
        std::unordered_map<std::string, int> df;
        for (const auto& doc : data) {
            std::unordered_map<std::string, bool> words_in_doc;
            for (const auto& word : split(doc)) {
                words_in_doc[word] = true;
            }
            for (const auto& word : words_in_doc) {
                df[word]++;
            }
        }
        std::unordered_map<std::string, double> idf_map;
        for (const auto& word : df) {
            idf_map[word.first] = std::log(1.0 * data.size() / word.second);
        }
        return idf_map;
    }

    std::vector<std::vector<double>> calculate_tfidf(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> tfidf_matrix;
        for (const auto& doc : data) {
            std::vector<double> tfidf_row;
            std::unordered_map<std::string, int> word_count;
            for (const auto& word : split(doc)) {
                word_count[word]++;
            }
            for (const auto& word : split(doc)) {
                double tf = 1.0 * word_count[word] / split(doc).size();
                double tfidf_val = tf * idf[word];
                tfidf_row.push_back(tfidf_val);
            }
            tfidf_matrix.push_back(tfidf_row);
        }
        return tfidf_matrix;
    }

    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> result;
        std::string word;
        for (char ch : str) {
            if (ch == ' ') {
                if (!word.empty()) {
                    result.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            result.push_back(word);
        }
        return result;
    }
};

void process_data() {
    std::vector<std::string> data = {"hello world", "goodbye world", "hello again"};
    TfidfVectorizer vectorizer;
    while (true) {
        vectorizer.fit_transform(data);
        vectorizer.print();
    }
}

int main() {
    process_data();
    return 0;
}