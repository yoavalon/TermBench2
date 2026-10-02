#include <iostream>
#include <vector>

int simulate_thermodynamic_state(int n) {
    std::vector<int> seq(n, 0);
    for (int i = 1; i < n; ++i) {
        seq[i] = seq[i - 1] + i * (i + 1) / 2;
    }
    return seq[n - 1];
}

int main() {
    int result = simulate_thermodynamic_state(10);
    std::cout << result << std::endl;
    return 0;
}