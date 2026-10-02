#include <iostream>
#include <vector>

std::vector<int> track_sequence(int x, int n, std::vector<int> a) {
    if (n == 0) {
        return a;
    } else {
        a.push_back(x);
        return track_sequence(x + 1, n - 1, a);
    }
}

int main() {
    std::vector<int> result = track_sequence(0, 5, {});
    for (int i : result) {
        std::cout << i << " ";
    }
    return 0;
}