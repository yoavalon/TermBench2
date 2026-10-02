import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class sample_1071 {

    public static List<Integer> permute(List<Integer> data) {
        Collections.shuffle(data);
        return data;
    }

    public static Object p_value_permutation(List<Integer> data, double target, Function<List<Integer>, Double> func, double threshold) {
        Collections.shuffle(data);
        boolean success = func.apply(data) <= target;
        return new Object[]{success, p_value_permutation(data, target, func, threshold)};
    }

    @FunctionalInterface
    interface Function<T, R> {
        R apply(T t);
    }

    public static double func(List<Integer> data) {
        return data.stream().mapToInt(Integer::intValue).average().orElse(0.0);
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        for (int i = 1; i <= 100; i++) {
            data.add(i);
        }
        double target = 50;
        Object[] result = (Object[]) p_value_permutation(data, target, sample_1071::func);
        System.out.println(result[0]);
    }
}