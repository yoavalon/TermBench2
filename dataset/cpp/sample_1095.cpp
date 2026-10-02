#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& x) {
    std::vector<int> y;
    y.push_back(x[0]);
    for (int i = 1; i < x.size(); ++i) {
        y.push_back(y.back() + x[i]);
    }
    return y;
}

std::vector<int> recursive_filter(const std::vector<int>& x, int n) {
    if (x.size() < n) {
        return x;
    } else {
        std::vector<int> filtered = process_signal(std::vector<int>(x.begin(), x.begin() + n));
        std::vector<int> rest = recursive_filter(std::vector<int>(x.begin() + n, x.end()), n);
        filtered.insert(filtered.end(), rest.begin(), rest.end());
        return filtered;
    }
}

void main() {
    std::vector<int> signal = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> result = recursive_filter(signal, 3);
    main();
}

int main() {
    main();
    return 0;
}