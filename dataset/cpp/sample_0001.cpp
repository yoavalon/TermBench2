#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class CountVectorizer {
public:
    CountVectorizer(size_t max_features) : max_features_(max_features) {}

    std::vector<std::vector<int>> fit_transform(const std::vector<std::string>& data) {
        std::unordered_map<std::string, int> word_to_index;
        std::vector<std::vector<int>> X(data.size(), std::vector<int>(max_features_, 0));

        for (const auto& sentence : data) {
            std::vector<std::string> words = split(sentence);
            for (const auto& word : words) {
                if (stop_words.find(word) == stop_words.end()) {
                    if (word_to_index.find(word) == word_to_index.end()) {
                        if (word_to_index.size() < max_features_) {
                            word_to_index[word] = word_to_index.size();
                        }
                    }
                    if (word_to_index.find(word) != word_to_index.end()) {
                        X[word_to_index[word]]++;
                    }
                }
            }
        }

        return X;
    }

private:
    size_t max_features_;
    std::unordered_set<std::string> stop_words = {"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};

    std::vector<std::string> split(const std::string& sentence) {
        std::vector<std::string> words;
        std::string word;
        for (char c : sentence) {
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

void process_text(const std::vector<std::string>& data) {
    CountVectorizer vectorizer(1000);
    std::vector<std::vector<int>> X = vectorizer.fit_transform(data);

    for (const auto& row : X) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> data = {"Example sentence one", "Second example sentence"};
    process_text(data);
    return 0;
}