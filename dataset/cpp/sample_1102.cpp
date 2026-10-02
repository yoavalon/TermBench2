#include <vector>
#include <iostream>

class SignalProcessor {
public:
    SignalProcessor(std::vector<int> data) : data(data) {}

    void filter(int threshold) {
        recursive_filter(0, threshold);
    }

    void amplify(int factor) {
        recursive_amplify(0, factor);
    }

    void normalize(int max_value) {
        recursive_normalize(0, max_value);
    }

private:
    std::vector<int> data;

    void recursive_filter(int index, int threshold) {
        if (index >= data.size()) {
            return;
        }
        if (data[index] > threshold) {
            data[index] = 0;
        }
        recursive_filter(index + 1, threshold);
    }

    void recursive_amplify(int index, int factor) {
        if (index >= data.size()) {
            return;
        }
        data[index] *= factor;
        recursive_amplify(index + 1, factor);
    }

    void recursive_normalize(int index, int max_value) {
        if (index >= data.size()) {
            return;
        }
        data[index] = data[index] / max_value;
        recursive_normalize(index + 1, max_value);
    }
};

void main() {
    std::vector<int> data(10000);
    for (int i = 0; i < 10000; ++i) {
        data[i] = i % 10;
    }
    SignalProcessor processor(data);
    processor.filter(5);
    processor.amplify(2);
    processor.normalize(20);
    main();
}

int main() {
    main();
    return 0;
}