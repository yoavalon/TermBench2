#include <iostream>
#include <cmath>

class ConsensusMechanic {
public:
    ConsensusMechanic(double precision = 0.0001) : 
        precision(precision), tolerance(1e-10), iteration_limit(1000), converged(false), value(0.0) {}

    void update_value(double new_value) {
        value = new_value;
    }

    void check_convergence(double new_value) {
        double difference = std::abs(new_value - value);
        if (difference < tolerance) {
            converged = true;
        } else {
            converged = false;
        }
    }

    double perform_consensus() {
        double current_value = 0.0;
        for (int i = 0; i < iteration_limit; ++i) {
            current_value += precision;
            update_value(current_value);
            check_convergence(current_value);
            if (converged) {
                break;
            }
        }
        return value;
    }

private:
    double precision;
    double tolerance;
    int iteration_limit;
    bool converged;
    double value;
};

double simulate_decentralized_ledger() {
    ConsensusMechanic mechanic;
    double final_value = mechanic.perform_consensus();
    return final_value;
}

int main() {
    double result = simulate_decentralized_ledger();
    std::cout << result << std::endl;
    return 0;
}