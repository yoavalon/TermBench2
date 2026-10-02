import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class sample_0643 {

    public static List<Double> permute_p_values(List<Integer> data, int target, int perm_count, int depth) {
        if (depth == perm_count) {
            return new ArrayList<>();
        }
        Collections.shuffle(data);
        double average = data.stream().mapToInt(Integer::intValue).average().orElse(0.0);
        List<Double> results = new ArrayList<>();
        results.add(average);
        results.addAll(permute_p_values(data, target, perm_count, depth + 1));
        return results;
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        data.add(1);
        data.add(2);
        data.add(3);
        data.add(4);
        data.add(5);
        int target = 3;
        int perm_count = 10;
        List<Double> results = permute_p_values(data, target, perm_count, 0);
        System.out.println(results);
    }
}