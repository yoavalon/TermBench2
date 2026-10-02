#include <iostream>
#include <vector>

std::vector<int> filter_signal(const std::vector<int>& signal, int threshold) {
    if (signal.size() == 0) {
        return {};
    } else {
        std::vector<int> filtered;
        if (signal[0] > threshold) {
            filtered.push_back(signal[0]);
        }
        std::vector<int> rest = filter_signal(std::vector<int>(signal.begin() + 1, signal.end()), threshold);
        filtered.insert(filtered.end(), rest.begin(), rest.end());
        return filtered;
    }
}

std::vector<int> process_signal(const std::vector<int>& data) {
    int threshold = 0;
    for (int value : data) {
        threshold += value;
    }
    threshold /= data.size();
    return filter_signal(data, threshold);
}

void main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> result = process_signal(data);
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    main();
}

int main() {
    main();
    return 0;
}