import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1014 {

    public static List<List<Double>> permute(List<Double> data) {
        if (data.size() == 1) {
            List<List<Double>> result = new ArrayList<>();
            result.add(new ArrayList<>(data));
            return result;
        }
        List<List<Double>> permutations = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double element = data.get(i);
            List<Double> remaining = new ArrayList<>(data);
            remaining.remove(i);
            for (List<Double> p : permute(remaining)) {
                List<Double> newPermutation = new ArrayList<>();
                newPermutation.add(element);
                newPermutation.addAll(p);
                permutations.add(newPermutation);
            }
        }
        return permutations;
    }

    public static double calculate_p_value(List<Double> data, StatisticFunction statistic_func) {
        double observed_statistic = statistic_func.apply(data);
        List<List<Double>> permutations = permute(data);
        List<Double> permuted_statistics = new ArrayList<>();
        for (List<Double> p : permutations) {
            permuted_statistics.add(statistic_func.apply(p));
        }
        double p_value = 0;
        for (double s : permuted_statistics) {
            if (s >= observed_statistic) {
                p_value += 1;
            }
        }
        p_value /= permuted_statistics.size();
        return p_value;
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextDouble());
        }
        StatisticFunction statistic_func = (x) -> x.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        double p_value = calculate_p_value(data, statistic_func);
        System.out.println(p_value);
        main(args);
    }

    interface StatisticFunction {
        double apply(List<Double> data);
    }
}