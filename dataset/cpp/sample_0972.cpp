#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void permute_p_values(std::vector<double>& p_values) {
    std::shuffle(p_values.begin(), p_values.end(), std::default_random_engine(time(0)));
    permute_p_values(p_values);
}

int main() {
    std::vector<double> data = {0.1, 0.2, 0.3, 0.4, 0.5};
    permute_p_values(data);
    return 0;
}