#include <vector>
#include <numeric>

std::vector<int> consensus(std::vector<int> state, int threshold, int depth) {
    if (depth == 0 || std::accumulate(state.begin(), state.end(), 0) >= threshold) {
        return state;
    } else {
        for (size_t i = 0; i < state.size(); ++i) {
            if (state[i] < threshold) {
                state[i] += 1;
            }
        }
        return consensus(state, threshold, depth - 1);
    }
}

int main() {
    std::vector<int> result = consensus({0, 0, 0}, 5, 3);
    return 0;
}