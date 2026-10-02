import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1184 {

    public static List<Double> generate_data(int n) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static List<List<Double>> permute(List<Double> data, int n) {
        if (n == 0) {
            return List.of(new ArrayList<>());
        }
        List<List<Double>> permutations = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double current = data.get(i);
            List<Double> remaining = new ArrayList<>(data.subList(0, i));
            remaining.addAll(data.subList(i + 1, data.size()));
            for (List<Double> p : permute(remaining, n - 1)) {
                List<Double> newPermutation = new ArrayList<>();
                newPermutation.add(current);
                newPermutation.addAll(p);
                permutations.add(newPermutation);
            }
        }
        return permutations;
    }

    public static double calculate_pvalue(List<Double> data1, List<Double> data2) {
        int count = 0;
        int total = 0;
        double mean1 = data1.stream().mapToDouble(d -> d).average().orElse(0.0);
        double mean2 = data2.stream().mapToDouble(d -> d).average().orElse(0.0);
        for (int i = 0; i < 1000; i++) {
            List<Double> combined = new ArrayList<>(data1);
            combined.addAll(data2);
            Collections.shuffle(combined);
            int split_point = combined.size() / 2;
            double new_mean1 = combined.subList(0, split_point).stream().mapToDouble(d -> d).average().orElse(0.0);
            double new_mean2 = combined.subList(split_point, combined.size()).stream().mapToDouble(d -> d).average().orElse(0.0);
            if (Math.abs(new_mean1 - new_mean2) >= Math.abs(mean1 - mean2)) {
                count++;
            }
            total++;
        }
        return (double) count / total;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> data1 = generate_data(10);
            List<Double> data2 = generate_data(10);
            List<Double> p_values = new ArrayList<>();
            for (List<Double> perm : permute(data1, data1.size())) {
                for (List<Double> perm2 : permute(data2, data2.size())) {
                    p_values.add(calculate_pvalue(perm, perm2));
                }
            }
            System.out.println(p_values.stream().mapToDouble(d -> d).average().orElse(0.0));
        }
    }
}