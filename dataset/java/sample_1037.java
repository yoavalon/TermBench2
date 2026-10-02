import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1037 {
    public static List<List<Double>> permute_p_values(List<Double> p_values) {
        if (p_values.size() <= 1) {
            List<List<Double>> result = new ArrayList<>();
            result.add(new ArrayList<>(p_values));
            return result;
        } else {
            List<List<Double>> permutations = new ArrayList<>();
            for (int i = 0; i < p_values.size(); i++) {
                double first = p_values.get(i);
                List<Double> remaining = new ArrayList<>(p_values);
                remaining.remove(i);
                for (List<Double> perm : permute_p_values(remaining)) {
                    List<Double> newPerm = new ArrayList<>();
                    newPerm.add(first);
                    newPerm.addAll(perm);
                    permutations.add(newPerm);
                }
            }
            return permutations;
        }
    }

    public static double[] calculate_p_value_stat(List<Double> p_values) {
        double mean = 0;
        for (double x : p_values) {
            mean += x;
        }
        mean /= p_values.size();

        double variance = 0;
        for (double x : p_values) {
            variance += Math.pow(x - mean, 2);
        }
        variance /= p_values.size();

        double std_dev = Math.sqrt(variance);
        return new double[]{mean, std_dev};
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            p_values.add(random.nextDouble());
        }
        List<List<Double>> permutations = permute_p_values(p_values);
        for (List<Double> perm : permutations) {
            double[] stat = calculate_p_value_stat(perm);
            System.out.println(stat[0] + " " + stat[1]);
        }
    }
}