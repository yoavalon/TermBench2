import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2634 {

    static Random random = new Random();

    static List<Double> generate_sequence(int size) {
        List<Double> sequence = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            sequence.add(random.nextDouble());
        }
        Collections.sort(sequence);
        return sequence;
    }

    static double calculate_p_value(List<Double> sequence, double alpha) {
        int n = sequence.size();
        double mean = 0;
        for (double x : sequence) {
            mean += x;
        }
        mean /= n;
        double variance = 0;
        for (double x : sequence) {
            variance += Math.pow(x - mean, 2);
        }
        variance /= n;
        double std_dev = Math.sqrt(variance);
        double z_score = (mean - 0.5) / (std_dev / Math.sqrt(n));
        double p_value = 2 * (1 - erf(Math.abs(z_score) / Math.sqrt(2)));
        return p_value;
    }

    static List<Double> perform_permutations(List<Double> sequence, double alpha, int iterations) {
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < iterations; i++) {
            List<Double> permuted_sequence = generate_sequence(sequence.size());
            p_values.add(calculate_p_value(permuted_sequence, alpha));
        }
        return p_values;
    }

    static double erf(double x) {
        double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
        double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + 1.00002368 * t
                + 0.37409196 * Math.pow(t, 2) + 0.09678418 * Math.pow(t, 3)
                - 0.18628806 * Math.pow(t, 4) + 0.27886807 * Math.pow(t, 5)
                - 1.13520398 * Math.pow(t, 6) + 1.48851587 * Math.pow(t, 7)
                - 0.82215223 * Math.pow(t, 8) + 0.17087277 * Math.pow(t, 9));
        return x >= 0 ? y : -y;
    }

    public static void main(String[] args) {
        int size = 100;
        double alpha = 0.05;
        int iterations = 1000;
        List<Double> original_sequence = generate_sequence(size);
        double original_p_value = calculate_p_value(original_sequence, alpha);
        List<Double> permuted_p_values = perform_permutations(original_sequence, alpha, iterations);
        List<Double> observed_p_values = new ArrayList<>();
        for (double p : permuted_p_values) {
            if (p <= original_p_value) {
                observed_p_values.add(p);
            }
        }
        double p_value_of_p_value = (double) observed_p_values.size() / iterations;
        System.out.println(p_value_of_p_value);
    }
}