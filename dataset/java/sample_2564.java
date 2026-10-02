import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class sample_2564 {
    public static void main(String[] args) {
        int n = 10;
        List<Double> a = generate_data(n);
        List<Double> b = generate_data(n);
        double p_value = calculate_pvalue(a, b);
        System.out.println(p_value);
    }

    public static List<Double> generate_data(int n) {
        Random random = new Random();
        return Arrays.stream(new double[n])
                .map(i -> random.nextDouble())
                .boxed()
                .collect(Collectors.toList());
    }

    public static double calculate_pvalue(List<Double> a, List<Double> b) {
        List<Double> combined = Stream.concat(a.stream(), b.stream())
                .sorted()
                .collect(Collectors.toList());
        int rank_sum = combined.stream()
                .mapToInt(combined::indexOf)
                .map(i -> i + 1)
                .sum();
        int n1 = a.size();
        int n2 = b.size();
        double mean_rank_sum = n1 * (n1 + n2 + 1) / 2.0;
        double var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12.0;
        double z = (rank_sum - mean_rank_sum) / Math.sqrt(var_rank_sum);
        return 2 * (1 - erf(Math.abs(z) / Math.sqrt(2)));
    }

    public static double erf(double x) {
        double t = 1.0 / (1.0 + 0.5 * Math.abs(x));
        double y = 1.0 - t * Math.exp(-x * x - 1.26551223 + 1.00002368 * t
                + 0.37409196 * t * t + 0.09678418 * t * t * t
                - 0.18628806 * t * t * t * t + 0.27886807 * t * t * t * t * t
                - 1.13520398 * t * t * t * t * t * t);
        return x >= 0 ? y : -y;
    }
}