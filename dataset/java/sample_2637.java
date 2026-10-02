import java.util.Arrays;
import java.util.Random;

public class sample_2637 {
    public static double[] generate_sequence(int n, int seed) {
        Random random = new Random(seed);
        double[] sequence = new double[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = random.nextGaussian();
        }
        return sequence;
    }

    public static double calculate_p_value(double[] sequence) {
        int n = sequence.length;
        double mean = Arrays.stream(sequence).sum() / n;
        double variance = Arrays.stream(sequence).map(x -> (x - mean) * (x - mean)).sum() / n;
        double std_dev = Math.sqrt(variance);
        double z_score = mean / (std_dev / Math.sqrt(n));
        double p_value = 1 - Math.erf(z_score / Math.sqrt(2));
        return p_value;
    }

    public static double[] perform_permutations(double[] sequence, int iterations) {
        double[] p_values = new double[iterations];
        Random random = new Random();
        for (int i = 0; i < iterations; i++) {
            random.shuffle(sequence);
            p_values[i] = calculate_p_value(sequence);
        }
        return p_values;
    }

    public static double analyze_p_values(double[] p_values) {
        Arrays.sort(p_values);
        double median_p_value = p_values[p_values.length / 2];
        return median_p_value;
    }

    public static void main(String[] args) {
        int sequence_length = 100;
        int seed_value = 42;
        int num_iterations = 1000;
        double[] sequence = generate_sequence(sequence_length, seed_value);
        double[] p_values = perform_permutations(sequence, num_iterations);
        double median_p_value = analyze_p_values(p_values);
        System.out.println("Median p-value: " + median_p_value);
    }
}