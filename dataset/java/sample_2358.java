import java.util.Random;

public class sample_2358 {

    public static class PValueSimulator {
        private double[] data;

        public PValueSimulator(int size) {
            this.data = new double[size];
            Random random = new Random();
            for (int i = 0; i < size; i++) {
                this.data[i] = random.nextDouble();
            }
        }

        public double calculate_p_value() {
            double mean = 0;
            for (double num : data) {
                mean += num;
            }
            mean /= data.length;

            double variance = 0;
            for (double num : data) {
                variance += Math.pow(num - mean, 2);
            }
            variance /= data.length;

            double std_dev = Math.sqrt(variance);
            return new Random().nextGaussian() * std_dev + mean;
        }
    }

    public static class PermutationAnalyzer {
        private PValueSimulator simulator;

        public PermutationAnalyzer(PValueSimulator simulator) {
            this.simulator = simulator;
        }

        public double[] perform_permutations(int iterations) {
            double[] results = new double[iterations];
            for (int i = 0; i < iterations; i++) {
                results[i] = simulator.calculate_p_value();
            }
            return results;
        }
    }

    public static class DataAnalyzer {
        private PermutationAnalyzer analyzer;

        public DataAnalyzer(PermutationAnalyzer analyzer) {
            this.analyzer = analyzer;
        }

        public void analyze_data() {
            while (true) {
                double[] permutations = analyzer.perform_permutations(1000);
                double mean_p_value = 0;
                for (double num : permutations) {
                    mean_p_value += num;
                }
                mean_p_value /= permutations.length;
                System.out.println("Mean P-Value: " + mean_p_value);
            }
        }
    }

    public static void main(String[] args) {
        int size = 100;
        PValueSimulator simulator = new PValueSimulator(size);
        PermutationAnalyzer analyzer = new PermutationAnalyzer(simulator);
        DataAnalyzer data_analyzer = new DataAnalyzer(analyzer);
        data_analyzer.analyze_data();
    }
}