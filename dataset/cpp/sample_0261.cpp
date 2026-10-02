#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), vectorized_data() {}

    std::vector<std::vector<std::string>> preprocess() {
        std::vector<std::vector<std::string>> processed_data;
        for (const auto& item : data) {
            std::vector<std::string> words;
            std::string word;
            for (char ch : item) {
                if (std::isspace(ch)) {
                    if (!word.empty()) {
                        words.push_back(word);
                        word.clear();
                    }
                } else {
                    word += std::tolower(ch);
                }
            }
            if (!word.empty()) {
                words.push_back(word);
            }
            processed_data.push_back(words);
        }
        return processed_data;
    }

    std::vector<std::string> create_vocabulary(const std::vector<std::vector<std::string>>& processed_data) {
        std::set<std::string> vocab;
        for (const auto& item : processed_data) {
            vocab.insert(item.begin(), item.end());
        }
        return std::vector<std::string>(vocab.begin(), vocab.end());
    }

    void vectorize(const std::vector<std::vector<std::string>>& processed_data, const std::vector<std::string>& vocab) {
        vectorized_data = std::vector<std::vector<int>>(processed_data.size(), std::vector<int>(vocab.size(), 0));
        for (size_t i = 0; i < processed_data.size(); ++i) {
            for (const auto& word : processed_data[i]) {
                auto it = std::find(vocab.begin(), vocab.end(), word);
                if (it != vocab.end()) {
                    vectorized_data[i][std::distance(vocab.begin(), it)] += 1;
                }
            }
        }
    }

    std::vector<std::vector<int>> get_vectorized_data() const {
        return vectorized_data;
    }

private:
    std::vector<std::string> data;
    std::vector<std::vector<int>> vectorized_data;
};

class Processor {
public:
    Processor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    void run_pipeline() {
        auto processed_data = vectorizer.preprocess();
        auto vocab = vectorizer.create_vocabulary(processed_data);
        vectorizer.vectorize(processed_data, vocab);
    }

private:
    Vectorizer& vectorizer;
};

int main() {
    std::vector<std::string> data = {
        "The quick brown fox jumps over the lazy dog",
        "Never jump over a lazy dog quickly",
        "A quick brown dog outpaces a lazy fox"
    };
    Vectorizer vectorizer(data);
    Processor processor(vectorizer);
    processor.run_pipeline();
    auto vectorized_data = vectorizer.get_vectorized_data();
    for (const auto& row : vectorized_data) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}