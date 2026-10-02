import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2561 {
    public static List<Double> generate_data(int n) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static List<Double> calculate_p_values(List<Double> data, int n_permutations) {
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < n_permutations; i++) {
            Collections.shuffle(data);
            double statistic = data.stream().mapToDouble(d -> d).average().orElse(0.0);
            p_values.add(statistic);
        }
        return p_values;
    }

    public static List<Boolean> analyze_p_values(List<Double> p_values, double threshold) {
        List<Boolean> results = new ArrayList<>();
        for (double p : p_values) {
            results.add(p < threshold);
        }
        return results;
    }

    public static void main(String[] args) {
        int data_size = 100;
        int permutations = 1000;
        double threshold = 0.5;
        List<Double> data = generate_data(data_size);
        List<Double> p_values = calculate_p_values(data, permutations);
        List<Boolean> results = analyze_p_values(p_values, threshold);
        System.out.println(results);
    }
}