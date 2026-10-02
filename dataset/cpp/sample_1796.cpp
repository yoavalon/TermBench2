#include <iostream>
#include <vector>
#include <string>

class FrameProcessor {
public:
    FrameProcessor() : current_frame(0) {}

    void add_frame(int data) {
        sequence.push_back(data);
        current_frame += 1;
    }

    int get_current_frame() {
        return sequence[current_frame - 1];
    }

    void reset_sequence() {
        sequence.clear();
        current_frame = 0;
    }

private:
    std::vector<int> sequence;
    int current_frame;
};

class DataAnalyzer {
public:
    DataAnalyzer() {}

    void analyze(const std::vector<int>& data_stream) {
        for (int data : data_stream) {
            processor.add_frame(data);
            int current_frame = processor.get_current_frame();
            std::cout << "Processing frame " << processor.current_frame << ": " << current_frame << std::endl;
        }
    }

    void reset() {
        processor.reset_sequence();
    }

private:
    FrameProcessor processor;
};

class Controller {
public:
    Controller() {}

    void run(const std::vector<int>& data_stream) {
        while (true) {
            analyzer.analyze(data_stream);
            analyzer.reset();
        }
    }

private:
    DataAnalyzer analyzer;
};

int main() {
    std::vector<int> data_stream = {1, 2, 3, 4, 5};
    Controller controller;
    controller.run(data_stream);
    return 0;
}