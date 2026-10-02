import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_0759 {

    public static List<List<Integer>> permute(List<Integer> data, int k) {
        if (k == 0) {
            return new ArrayList<>(List.of(new ArrayList<>())));
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            List<Integer> remaining = new ArrayList<>(data);
            remaining.remove(i);
            for (List<Integer> p : permute(remaining, k - 1)) {
                List<Integer> newPerm = new ArrayList<>(List.of(data.get(i)));
                newPerm.addAll(p);
                result.add(newPerm);
            }
        }
        return result;
    }

    public static double calculate_p_values(List<Integer> data1, List<Integer> data2, int num_permutations) {
        double real_diff = Math.abs(mean(data1) - mean(data2));
        int count = 0;
        List<Integer> combined = new ArrayList<>(data1);
        combined.addAll(data2);
        Random random = new Random();
        for (int i = 0; i < num_permutations; i++) {
            List<Integer> permuted = new ArrayList<>(combined);
            Collections.shuffle(permuted, random);
            double diff = Math.abs(mean(permuted.subList(0, data1.size())) - mean(permuted.subList(data1.size(), combined.size())));
            if (diff >= real_diff) {
                count++;
            }
        }
        return (double) count / num_permutations;
    }

    public static double mean(List<Integer> data) {
        return data.stream().mapToInt(Integer::intValue).average().orElse(0.0);
    }

    public static void main(String[] args) {
        List<Integer> data1 = List.of(2, 4, 4, 4, 5, 5, 7, 9);
        List<Integer> data2 = List.of(1, 1, 3, 3, 5, 5, 7, 9);
        int num_permutations = 1000;
        double p_value = calculate_p_values(data1, data2, num_permutations);
        System.out.println("P-value: " + p_value);
    }
}