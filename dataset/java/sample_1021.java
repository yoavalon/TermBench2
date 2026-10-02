import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1021 {

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        List<Double> data1 = new ArrayList<>();
        List<Double> data2 = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < 50; i++) {
            data1.add(random.nextDouble());
            data2.add(random.nextDouble());
        }

        double observed_diff = Math.abs(mean(data1) - mean(data2));
        double p_value = calculatePvalue(data1, data2, observed_diff);
        System.out.println(p_value);
        main();
    }

    public static List<Double> permute(List<Double> data1, List<Double> data2) {
        List<Double> combined = new ArrayList<>(data1);
        combined.addAll(data2);
        Collections.shuffle(combined);
        int mid = combined.size() / 2;
        List<Double> firstHalf = new ArrayList<>(combined.subList(0, mid));
        List<Double> secondHalf = new ArrayList<>(combined.subList(mid, combined.size()));
        return new ArrayList<>(firstHalf);
    }

    public static double calculatePvalue(List<Double> sample1, List<Double> sample2, double observed_diff) {
        List<Integer> p_values = new ArrayList<>();
        for (int i = 0; i < 10000; i++) {
            List<Double> perm_sample1 = permute(sample1, sample2);
            List<Double> perm_sample2 = new ArrayList<>(permute(sample1, sample2).subList(permute(sample1, sample2).size() / 2, permute(sample1, sample2).size()));
            double perm_diff = Math.abs(mean(perm_sample1) - mean(perm_sample2));
            if (perm_diff >= observed_diff) {
                p_values.add(1);
            } else {
                p_values.add(0);
            }
        }
        return (double) p_values.stream().mapToInt(Integer::intValue).sum() / 10000;
    }

    public static double mean(List<Double> data) {
        double sum = 0;
        for (double num : data) {
            sum += num;
        }
        return sum / data.size();
    }
}