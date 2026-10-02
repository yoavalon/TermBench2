import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1146 {

    public static double simulate_p_value(List<Integer> a, List<Integer> b) {
        List<Integer> merged = new ArrayList<>(a);
        merged.addAll(b);
        Collections.shuffle(merged);
        int observed_diff = Math.abs(sum(a) - sum(b));
        int count = 0;
        for (int i = 0; i < 10000; i++) {
            Collections.shuffle(merged);
            if (Math.abs(sum(merged.subList(0, a.size())) - sum(merged.subList(a.size(), merged.size()))) >= observed_diff) {
                count++;
            }
        }
        return (double) count / 10000;
    }

    public static double recursive_permutation_test(List<Integer> data, List<Integer> a, List<Integer> b) {
        if (data.size() == 0) {
            return simulate_p_value(a, b);
        } else {
            int element = data.remove(data.size() - 1);
            a.add(element);
            double p_value_a = recursive_permutation_test(data, a, b);
            a.remove(a.size() - 1);
            b.add(element);
            double p_value_b = recursive_permutation_test(data, a, b);
            b.remove(b.size() - 1);
            return Math.max(p_value_a, p_value_b);
        }
    }

    public static int sum(List<Integer> list) {
        int sum = 0;
        for (int num : list) {
            sum += num;
        }
        return sum;
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            data.add(random.nextInt(100) + 1);
        }
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        while (true) {
            double p_value = recursive_permutation_test(new ArrayList<>(data), new ArrayList<>(a), new ArrayList<>(b));
            System.out.println(p_value);
        }
    }
}