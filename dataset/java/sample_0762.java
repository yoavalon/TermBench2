import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class sample_0762 {

    public static List<List<Integer>> permute(List<Integer> data, int n) {
        if (n == 0) {
            return Arrays.asList(new ArrayList<>(data));
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            int x = data.get(i);
            List<Integer> xs = new ArrayList<>(data);
            xs.remove(i);
            for (List<Integer> p : permute(xs, n - 1)) {
                p.add(0, x);
                result.add(p);
            }
        }
        return result;
    }

    public static double calculatePvalue(List<Integer> data, java.util.function.Function<List<Integer>, Double> func) {
        double observed = func.apply(data);
        List<List<Integer>> permutations = permute(data, data.size() - 1);
        int count = 0;
        for (List<Integer> p : permutations) {
            if (func.apply(p) >= observed) {
                count++;
            }
        }
        return (double) count / permutations.size();
    }

    public static void main(String[] args) {
        List<Integer> data = Arrays.asList(1, 2, 3, 4, 5);
        java.util.function.Function<List<Integer>, Double> statisticFunc = x -> {
            double mean1 = x.stream().mapToInt(Integer::intValue).average().orElse(0.0);
            double mean2 = Arrays.asList(1, 2, 3, 4, 5).stream().mapToInt(Integer::intValue).average().orElse(0.0);
            return mean1 - mean2;
        };
        double pValue = calculatePvalue(data, statisticFunc);
        System.out.println(pValue);
    }
}