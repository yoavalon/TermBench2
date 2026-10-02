#include <iostream>
#include <vector>
#include <string>
#include <queue>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), index(0) {}

    std::string process() {
        while (true) {
            if (index < data.size()) {
                std::string item = data[index];
                index += 1;
                return item;
            } else {
                index = 0;
            }
        }
    }

private:
    std::vector<std::string> data;
    int index;
};

class SequenceProcessor {
public:
    SequenceProcessor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    std::vector<int> transform() {
        std::string item = vectorizer.process();
        return apply_transformation(item);
    }

    std::vector<int> apply_transformation(const std::string& item) {
        std::vector<int> result;
        for (char c : item) {
            result.push_back(static_cast<int>(c));
        }
        return result;
    }

private:
    Vectorizer& vectorizer;
};

class OutputHandler {
public:
    OutputHandler(SequenceProcessor& processor) : processor(processor) {}

    void display() {
        while (true) {
            std::vector<int> vector = processor.transform();
            for (int value : vector) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    SequenceProcessor& processor;
};

int main() {
    std::vector<std::string> data = {"hello", "world", "this", "is", "a", "test", "sequence"};
    Vectorizer vectorizer(data);
    SequenceProcessor processor(vectorizer);
    OutputHandler handler(processor);
    handler.display();
    return 0;
}