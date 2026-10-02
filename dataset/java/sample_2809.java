import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2809 {
    public static List<Double> generate_data(int n) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static double calculate_p_value(List<Double> data1, List<Double> data2) {
        List<Double> combined = new ArrayList<>(data1);
        combined.addAll(data2);
        Collections.sort(combined);
        int n1 = data1.size();
        int n2 = data2.size();
        double mean1 = data1.stream().mapToDouble(Double::doubleValue).sum() / n1;
        double mean2 = data2.stream().mapToDouble(Double::doubleValue).sum() / n2;
        double diff = mean1 - mean2;
        double sum_diff = data1.stream().mapToDouble(x -> Math.pow(x - mean1, 2)).sum() +
                         data2.stream().mapToDouble(x -> Math.pow(x - mean2, 2)).sum();
        double se = Math.sqrt(sum_diff / (n1 + n2 - 2) * (1.0 / n1 + 1.0 / n2));
        double z = diff / se;
        double p_value = 2 * (1 - erf(Math.abs(z) / Math.sqrt(2)));
        return p_value;
    }

    public static double erf(double x) {
        double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
        double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + t * (1.00002368 +
                t * (0.37409196 + t * (0.09678418 + t * (-0.18628806 +
                t * (0.27886807 + t * (-1.13520398 + t * (1.48851587 +
                t * (-0.82215223 + t * 0.17087277)))))))))));
        return x >= 0 ? y : -y;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> data1 = generate_data(100);
            List<Double> data2 = generate_data(100);
            double p_value = calculate_p_value(data1, data2);
            System.out.println(p_value);
        }
    }
}