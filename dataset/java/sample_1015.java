import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1015 {
    public static List<List<Double>> permute(List<Double> arr) {
        int n = arr.size();
        if (n == 1) {
            List<List<Double>> result = new ArrayList<>();
            result.add(new ArrayList<>(arr));
            return result;
        } else {
            List<List<Double>> result = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                double first = arr.get(i);
                List<Double> rest = new ArrayList<>(arr.subList(0, i));
                rest.addAll(arr.subList(i + 1, n));
                for (List<Double> p : permute(rest)) {
                    List<Double> newPerm = new ArrayList<>();
                    newPerm.add(first);
                    newPerm.addAll(p);
                    result.add(newPerm);
                }
            }
            return result;
        }
    }

    public static List<Double> permute_p_values(List<Double> data) {
        List<List<Double>> permuted = permute(data);
        List<Double> results = new ArrayList<>();
        for (List<Double> p : permuted) {
            double sum = 0;
            for (double value : p) {
                sum += value;
            }
            results.add(sum);
        }
        return results;
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextDouble());
        }
        List<Double> permuted_p_values = permute_p_values(data);
        main(args);
    }
}