import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2048 {

    static class PValuePermutations {
        private double[] data;
        private int iterations;
        private List<double[]> permutations;

        public PValuePermutations(double[] data, int iterations) {
            this.data = data;
            this.iterations = iterations;
            this.permutations = new ArrayList<>();
        }

        public void generate_permutations() {
            for (int i = 0; i < iterations; i++) {
                double[] permuted_data = data.clone();
                Collections.shuffle(Arrays.asList(permuted_data));
                permutations.add(permuted_data);
            }
        }

        public List<Double> calculate_p_values() {
            List<Double> p_values = new ArrayList<>();
            double original_mean = calculate_mean(data);
            for (double[] permuted_data : permutations) {
                double permuted_mean = calculate_mean(permuted_data);
                double p_value = calculate_one_tailed_p_value(original_mean, permuted_mean);
                p_values.add(p_value);
            }
            return p_values;
        }

        private double calculate_one_tailed_p_value(double original_mean, double permuted_mean) {
            if (original_mean > permuted_mean) {
                return 1;
            } else {
                return 0;
            }
        }

        private double calculate_mean(double[] data) {
            double sum = 0;
            for (double value : data) {
                sum += value;
            }
            return sum / data.length;
        }
    }

    static class DataAnalyzer {
        private double[] data;
        private int iterations;
        private PValuePermutations p_value_calculator;

        public DataAnalyzer(double[] data, int iterations) {
            this.data = data;
            this.iterations = iterations;
            this.p_value_calculator = new PValuePermutations(data, iterations);
        }

        public double analyze() {
            p_value_calculator.generate_permutations();
            List<Double> p_values = p_value_calculator.calculate_p_values();
            return calculate_mean(p_values);
        }

        private double calculate_mean(List<Double> data) {
            double sum = 0;
            for (double value : data) {
                sum += value;
            }
            return sum / data.size();
        }
    }

    public static void main(String[] args) {
        Random random = new Random();
        double[] data = new double[100];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextGaussian();
        }
        int iterations = 1000;
        DataAnalyzer analyzer = new DataAnalyzer(data, iterations);
        double result = analyzer.analyze();
        System.out.println("Mean p-value: " + result);
    }
}