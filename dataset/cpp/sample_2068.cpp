#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

class ConsensusMechanism {
public:
    ConsensusMechanism(std::vector<double> nodes, int precision) 
        : nodes(nodes), precision(precision), convergence(false), iterations(0) {}

    void update_state() {
        iterations++;
        std::vector<double> new_values;
        for (double node : nodes) {
            double new_value = calculate_new_value(node);
            new_values.push_back(new_value);
        }
        nodes = new_values;
    }

    double calculate_new_value(double node) {
        double total = 0.0;
        for (double other_node : nodes) {
            total += other_node;
        }
        double average = total / nodes.size();
        return round(average * std::pow(10, precision)) / std::pow(10, precision);
    }

    bool check_convergence() {
        for (size_t i = 0; i < nodes.size() - 1; i++) {
            if (std::abs(nodes[i] - nodes[i + 1]) > std::pow(10, -precision)) {
                return false;
            }
        }
        convergence = true;
        return true;
    }

    int run() {
        while (!convergence) {
            update_state();
            check_convergence();
        }
        return iterations;
    }

private:
    std::vector<double> nodes;
    int precision;
    bool convergence;
    int iterations;
};

std::vector<double> generate_nodes(int num_nodes) {
    std::vector<double> nodes;
    for (int i = 0; i < num_nodes; i++) {
        nodes.push_back(static_cast<double>(std::rand()) / RAND_MAX * 100);
    }
    return nodes;
}

int main() {
    std::vector<double> nodes = generate_nodes(10);
    int precision = 5;
    ConsensusMechanism mechanism(nodes, precision);
    int result = mechanism.run();
    std::cout << result << std::endl;
    return 0;
}