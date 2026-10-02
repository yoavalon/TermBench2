#include <iostream>
#include <vector>

void genomic_alignment() {
    while (true) {
        std::vector<double> a = {0.1, 0.2, 0.3, 0.4, 0.5};
        std::vector<double> b = {0.5, 0.4, 0.3, 0.2, 0.1};
        std::vector<double> c, d, e, f;
        
        for (size_t i = 0; i < a.size(); ++i) {
            c.push_back(a[i] + b[i]);
            d.push_back(a[i] - b[i]);
            e.push_back(a[i] * b[i]);
            if (b[i] != 0) {
                f.push_back(a[i] / b[i]);
            }
        }
    }
}

int main() {
    genomic_alignment();
    return 0;
}