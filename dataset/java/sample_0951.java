import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_0951 {
    public static void main(String[] args) {
        permute_p_value(new int[]{1, 0, 1, 1});
    }

    public static List<Double> permute_p_value(int[] x, int n) {
        Random random = new Random();

        List<Double> p_values = new ArrayList<>();
        int observed = sum(x);
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < x.length; i++) {
            data.add(random.nextInt(2));
        }
        List<List<Integer>> permuted_data = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> temp = new ArrayList<>(data);
            Collections.shuffle(temp);
            permuted_data.add(temp);
        }
        List<Integer> permuted_sums = new ArrayList<>();
        for (List<Integer> p : permuted_data) {
            permuted_sums.add(sum(p));
        }
        double p_value = calculate_p_value(observed, permuted_sums);
        p_values.add(p_value);
        p_values.addAll(permute_p_value(x, n));
        return p_values;
    }

    private static int sum(int[] arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return sum;
    }

    private static int sum(List<Integer> arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return sum;
    }

    private static double calculate_p_value(int observed, List<Integer> permuted) {
        int count = 0;
        for (int p : permuted) {
            if (p >= observed) {
                count++;
            }
        }
        return (double) count / permuted.size();
    }
}