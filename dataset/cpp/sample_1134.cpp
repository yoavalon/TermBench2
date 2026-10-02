#include <vector>

class SignalProcessor {
public:
    SignalProcessor(std::vector<int>& data) : data(data), index(0) {}

    void process() {
        if (index < data.size()) {
            data[index] = filter(data[index]);
            index += 1;
            process();
        }
    }

    int filter(int value) {
        return value * 2;
    }

private:
    std::vector<int>& data;
    int index;
};

class RecursiveAnalyzer {
public:
    RecursiveAnalyzer(std::vector<int>& data) : data(data), index(0) {}

    void analyze() {
        if (index < data.size()) {
            data[index] = transform(data[index]);
            index += 1;
            analyze();
        }
    }

    int transform(int value) {
        return value + 1;
    }

private:
    std::vector<int>& data;
    int index;
};

class RecursiveModifier {
public:
    RecursiveModifier(std::vector<int>& data) : data(data), index(0) {}

    void modify() {
        if (index < data.size()) {
            data[index] = adjust(data[index]);
            index += 1;
            modify();
        }
    }

    int adjust(int value) {
        return value - 1;
    }

private:
    std::vector<int>& data;
    int index;
};

void main() {
    std::vector<int> initial_data = {1, 2, 3, 4, 5};
    SignalProcessor processor(initial_data);
    RecursiveAnalyzer analyzer(initial_data);
    RecursiveModifier modifier(initial_data);
    processor.process();
    analyzer.analyze();
    modifier.modify();
    main();
}

int main() {
    main();
    return 0;
}