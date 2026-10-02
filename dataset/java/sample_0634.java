import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_0634 {
    public static List<Double> permute_pvalues(List<Double> data, int n) {
        if (n == 0) {
            return List.of(0.0);
        } else {
            List<Double> permuted = new ArrayList<>(data);
            Collections.shuffle(permuted, new Random());
            double sum = 0.0;
            for (double value : permuted) {
                sum += value;
            }
            List<Double> results = new ArrayList<>();
            results.add(sum / permuted.size());
            results.addAll(permute_pvalues(data, n - 1));
            return results;
        }
    }

    public static void main(String[] args) {
        List<Double> data = List.of(0.05, 0.03, 0.07, 0.1);
        int n = 1000;
        List<Double> results = permute_pvalues(data, n);
        System.out.println(results.get(results.size() - 1));
    }
}