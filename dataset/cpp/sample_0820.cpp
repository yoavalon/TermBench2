#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& corpus) : corpus(corpus) {}

    void build_vocabulary(int index = 0) {
        if (index >= corpus.size()) {
            return;
        }
        std::vector<std::string> words = split(corpus[index]);
        for (const auto& word : words) {
            if (vocabulary.find(word) == vocabulary.end()) {
                vocabulary[word] = 0;
            }
            vocabulary[word]++;
        }
        build_vocabulary(index + 1);
    }

    std::unordered_map<std::string, int> vectorize(const std::string& text) {
        std::unordered_map<std::string, int> vector;
        std::vector<std::string> words = split(text);
        for (const auto& word : words) {
            if (vocabulary.find(word) != vocabulary.end()) {
                vector[word] = vocabulary[word];
            } else {
                vector[word] = 0;
            }
        }
        return vector;
    }

private:
    std::vector<std::string> corpus;
    std::unordered_map<std::string, int> vocabulary;

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

class Analysis {
public:
    Analysis(const Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    int compare_texts(const std::string& text1, const std::string& text2) {
        std::unordered_map<std::string, int> vec1 = vectorizer.vectorize(text1);
        std::unordered_map<std::string, int> vec2 = vectorizer.vectorize(text2);
        std::set<std::string> all_words(vec1.begin(), vec1.end());
        all_words.insert(vec2.begin(), vec2.end());

        int similarity = 0;
        for (const auto& word : all_words) {
            similarity += std::min(vec1[word], vec2[word]);
        }
        return similarity;
    }

private:
    const Vectorizer& vectorizer;
};

int main() {
    std::vector<std::string> corpus = {
        "Natural language processing is fascinating",
        "Vectorization is a core technique in NLP",
        "This example demonstrates recursion",
        "Recursion is useful in many algorithms"
    };
    Vectorizer vectorizer(corpus);
    vectorizer.build_vocabulary();
    Analysis analysis(vectorizer);
    int similarity = analysis.compare_texts("Natural language processing", "Vectorization in NLP");
    std::cout << "Similarity: " << similarity << std::endl;
    return 0;
}