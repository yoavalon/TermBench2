import java.util.Random;

public class sample_2675 {

    static class PermutationCalculator {
        int n;
        int k;

        PermutationCalculator(int n, int k) {
            this.n = n;
            this.k = k;
        }

        int factorial(int num) {
            int result = 1;
            for (int i = 2; i <= num; i++) {
                result *= i;
            }
            return result;
        }

        int calculate_permutations() {
            return factorial(n) / factorial(n - k);
        }
    }

    static class SimulationEngine {
        PermutationCalculator perm_calc;
        int iterations;

        SimulationEngine(PermutationCalculator perm_calc, int iterations) {
            this.perm_calc = perm_calc;
            this.iterations = iterations;
        }

        double run_simulation() {
            int success_count = 0;
            Random random = new Random();
            for (int i = 0; i < iterations; i++) {
                if (random.nextDouble() < 1.0 / perm_calc.calculate_permutations()) {
                    success_count++;
                }
            }
            return (double) success_count / iterations;
        }
    }

    static class AnalysisModule {
        SimulationEngine sim_engine;

        AnalysisModule(SimulationEngine sim_engine) {
            this.sim_engine = sim_engine;
        }

        double analyze_results() {
            return sim_engine.run_simulation();
        }
    }

    public static void main(String[] args) {
        int n = 5;
        int k = 3;
        int iterations = 100000;
        PermutationCalculator perm_calc = new PermutationCalculator(n, k);
        SimulationEngine sim_engine = new SimulationEngine(perm_calc, iterations);
        AnalysisModule analysis_module = new AnalysisModule(sim_engine);
        double p_value = analysis_module.analyze_results();
        System.out.println(p_value);
    }
}