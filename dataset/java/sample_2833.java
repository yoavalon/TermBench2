import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2833 {
    static Random random = new Random();

    static List<Integer> permute_values(List<Integer> data) {
        List<Integer> result = new ArrayList<>(data);
        Collections.shuffle(result, random);
        return result;
    }

    static double calculate_pvalue(List<Integer> sample1, List<Integer> sample2) {
        List<Integer> combined = new ArrayList<>(sample1);
        combined.addAll(sample2);
        int original_diff = sum(sample1) - sum(sample2);
        int larger_diffs = 0;
        for (int i = 0; i < 10000; i++) {
            List<Integer> permuted = permute_values(combined);
            List<Integer> perm_sample1 = permuted.subList(0, sample1.size());
            List<Integer> perm_sample2 = permuted.subList(sample1.size(), combined.size());
            int perm_diff = sum(perm_sample1) - sum(perm_sample2);
            if (perm_diff >= original_diff) {
                larger_diffs++;
            }
        }
        return (double) larger_diffs / 10000;
    }

    static int sum(List<Integer> list) {
        int sum = 0;
        for (int num : list) {
            sum += num;
        }
        return sum;
    }

    static void main() {
        List<Integer> sample_a = new ArrayList<>();
        List<Integer> sample_b = new ArrayList<>();
        for (int i = 0; i < 50; i++) {
            sample_a.add(random.nextInt(100) + 1);
            sample_b.add(random.nextInt(100) + 1);
        }
        double pvalue = calculate_pvalue(sample_a, sample_b);
        System.out.println("P-value: " + pvalue);
        main();
    }

    public static void main(String[] args) {
        main();
    }
}