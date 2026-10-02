import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2014 {

    public static List<Double> generate_data(int size) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data.add(random.nextGaussian());
        }
        return data;
    }

    public static double calculate_p_value(List<Double> data1, List<Double> data2) {
        double mean1 = data1.stream().mapToDouble(d -> d).average().orElse(0.0);
        double mean2 = data2.stream().mapToDouble(d -> d).average().orElse(0.0);
        double variance1 = data1.stream().mapToDouble(d -> (d - mean1) * (d - mean1)).average().orElse(0.0);
        double variance2 = data2.stream().mapToDouble(d -> (d - mean2) * (d - mean2)).average().orElse(0.0);
        double pooled_variance = ((data1.size() - 1) * variance1 + (data2.size() - 1) * variance2) / (data1.size() + data2.size() - 2);
        double t_statistic = (mean1 - mean2) / Math.sqrt(pooled_variance * (1.0 / data1.size() + 1.0 / data2.size()));
        int df = data1.size() + data2.size() - 2;
        double p_value = 2 * (1 - Math.tanh(t_statistic * Math.sqrt(df / (df + t_statistic * t_statistic))));
        return p_value;
    }

    public static List<Double> simulate_p_values(int num_simulations, int sample_size) {
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < num_simulations; i++) {
            List<Double> data1 = generate_data(sample_size);
            List<Double> data2 = generate_data(sample_size);
            p_values.add(calculate_p_value(data1, data2));
        }
        return p_values;
    }

    public static void main(String[] args) {
        int num_simulations = 1000;
        int sample_size = 30;
        List<Double> p_values = simulate_p_values(num_simulations, sample_size);
        Collections.sort(p_values);
        double median_p_value = p_values.get(p_values.size() / 2);
        System.out.println("Median P-value: " + median_p_value);
    }
}