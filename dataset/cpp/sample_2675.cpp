#include <iostream>
#include <cmath>
#include <cstdlib>

class PermutationCalculator {
public:
    int n;
    int k;

    PermutationCalculator(int n, int k) : n(n), k(k) {}

    int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; ++i) {
            result *= i;
        }
        return result;
    }

    int calculate_permutations() {
        return factorial(n) / factorial(n - k);
    }
};

class SimulationEngine {
public:
    PermutationCalculator perm_calc;
    int iterations;

    SimulationEngine(PermutationCalculator perm_calc, int iterations) : perm_calc(perm_calc), iterations(iterations) {}

    double run_simulation() {
        int success_count = 0;
        for (int i = 0; i < iterations; ++i) {
            if (static_cast<double>(std::rand()) / RAND_MAX < 1.0 / perm_calc.calculate_permutations()) {
                ++success_count;
            }
        }
        return static_cast<double>(success_count) / iterations;
    }
};

class AnalysisModule {
public:
    SimulationEngine sim_engine;

    AnalysisModule(SimulationEngine sim_engine) : sim_engine(sim_engine) {}

    double analyze_results() {
        return sim_engine.run_simulation();
    }
};

int main() {
    int n = 5;
    int k = 3;
    int iterations = 100000;
    PermutationCalculator perm_calc(n, k);
    SimulationEngine sim_engine(perm_calc, iterations);
    AnalysisModule analysis_module(sim_engine);
    double p_value = analysis_module.analyze_results();
    std::cout << p_value << std::endl;
    return 0;
}