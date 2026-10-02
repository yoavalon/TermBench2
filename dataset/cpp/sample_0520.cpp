#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    std::vector<std::string> preprocess() {
        std::vector<std::string> processed_data;
        for (const auto& text : data) {
            std::string lower_text;
            for (char c : text) {
                lower_text += std::tolower(c);
            }
            lower_text.erase(std::remove_if(lower_text.begin(), lower_text.end(), ispunct), lower_text.end());
            processed_data.push_back(lower_text);
        }
        return processed_data;
    }

    std::unordered_map<std::string, int> tokenize(const std::vector<std::string>& processed_data) {
        std::unordered_map<std::string, int> word_counts;
        for (const auto& text : processed_data) {
            std::istringstream stream(text);
            std::string word;
            while (stream >> word) {
                word_counts[word]++;
            }
        }
        return word_counts;
    }

    void vectorize(const std::unordered_map<std::string, int>& word_counts) {
        std::vector<std::string> unique_words;
        for (const auto& pair : word_counts) {
            unique_words.push_back(pair.first);
        }
        int vector_size = unique_words.size();
        for (const auto& text : data) {
            std::vector<int> vector(vector_size, 0);
            std::istringstream stream(text);
            std::string word;
            while (stream >> word) {
                for (int i = 0; i < vector_size; ++i) {
                    if (unique_words[i] == word) {
                        vector[i]++;
                    }
                }
            }
            vectors.push_back(vector);
        }
    }

private:
    std::vector<std::string> data;
    std::vector<std::vector<int>> vectors;
};

class Processor {
public:
    Processor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    void process() {
        auto processed_data = vectorizer.preprocess();
        auto word_counts = vectorizer.tokenize(processed_data);
        vectorizer.vectorize(word_counts);
    }

private:
    Vectorizer& vectorizer;
};

int main() {
    std::vector<std::string> data = {
        "Natural language processing is fascinating.",
        "This is an example of text data.",
        "Vectorization converts text to numerical format.",
        "Understanding NLP is crucial for many applications.",
        "We process text to extract meaningful information."
    };
    Vectorizer vectorizer(data);
    Processor processor(vectorizer);
    while (true) {
        processor.process();
    }
    return 0;
}