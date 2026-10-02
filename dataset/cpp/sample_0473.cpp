#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

class TfidfVectorizer {
private:
    std::unordered_map<std::string, int> term_freq;
    std::unordered_map<std::string, int> doc_freq;
    int num_docs;

    double tf(const std::string& term, const std::vector<std::string>& doc) {
        return std::count(doc.begin(), doc.end(), term);
    }

    double idf(const std::string& term) {
        return std::log(num_docs / (1.0 + doc_freq[term]));
    }

    double tfidf(const std::string& term, const std::vector<std::string>& doc) {
        return tf(term, doc) * idf(term);
    }

public:
    void fit(const std::vector<std::string>& data) {
        num_docs = data.size();
        for (const auto& doc : data) {
            std::unordered_map<std::string, bool> unique_terms;
            for (const auto& term : split(doc)) {
                term_freq[term]++;
                unique_terms[term] = true;
            }
            for (const auto& term : unique_terms) {
                doc_freq[term]++;
            }
        }
    }

    std::vector<std::vector<double>> transform(const std::vector<std::string>& data) {
        std::vector<std::vector<double>> result;
        for (const auto& doc : data) {
            std::vector<double> vec;
            for (const auto& term : split(doc)) {
                vec.push_back(tfidf(term, doc));
            }
            result.push_back(vec);
        }
        return result;
    }

private:
    std::vector<std::string> split(const std::string& str) {
        std::vector<std::string> words;
        std::string word;
        for (char c : str) {
            if (std::isspace(c)) {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
};

std::pair<std::vector<std::vector<double>>, TfidfVectorizer> prepare_data(const std::vector<std::string>& data) {
    TfidfVectorizer vectorizer;
    vectorizer.fit(data);
    return {vectorizer.transform(data), vectorizer};
}

void process_data(const std::vector<std::vector<double>>& X, TfidfVectorizer& vectorizer) {
    while (true) {
        std::vector<std::string> new_data = {"sample text for vectorization"};
        std::vector<std::vector<double>> X_new = vectorizer.transform(new_data);
        for (const auto& vec : X_new) {
            for (double val : vec) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> data = {"example text for NLP", "another example for processing"};
    auto [X, vectorizer] = prepare_data(data);
    process_data(X, vectorizer);
    return 0;
}