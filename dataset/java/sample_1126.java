import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1126 {
    public static void main(String[] args) {
        int sample_size = 5;
        int population_size = 10;
        List<Double> sample = generate_data(sample_size);
        List<Double> population = generate_data(population_size);
        double p_value = calculate_p_value(sample, population);
        System.out.println(p_value);
        main(args);
    }

    public static List<Double> generate_data(int size) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static List<List<Double>> permute(List<Double> data) {
        if (data.size() == 1) {
            List<List<Double>> result = new ArrayList<>();
            result.add(new ArrayList<>(data));
            return result;
        }
        List<List<Double>> permutations = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double first = data.get(i);
            List<Double> rest = new ArrayList<>(data.subList(0, i));
            rest.addAll(data.subList(i + 1, data.size()));
            for (List<Double> p : permute(rest)) {
                List<Double> newPermutation = new ArrayList<>();
                newPermutation.add(first);
                newPermutation.addAll(p);
                permutations.add(newPermutation);
            }
        }
        return permutations;
    }

    public static double calculate_p_value(List<Double> sample, List<Double> population) {
        double sample_mean = sample.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        int count = 0;
        for (List<Double> perm : permute(population)) {
            double perm_mean = perm.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
            if (perm_mean >= sample_mean) {
                count++;
            }
        }
        return (double) count / permute(population).size();
    }
}