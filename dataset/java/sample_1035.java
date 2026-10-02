import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1035 {
    public static void permute(List<Double> p, int n, List<List<Double>> res) {
        if (n == 1) {
            res.add(new ArrayList<>(p));
        } else {
            for (int i = 0; i < n; i++) {
                double temp = p.get(i);
                p.set(i, p.get(0));
                p.set(0, temp);
                permute(p.subList(1, n), n - 1, res);
                p.set(0, p.get(i));
                p.set(i, temp);
            }
        }
    }

    public static List<Double> p_value_permutations(List<Double> data) {
        List<Double> p_values = new ArrayList<>();
        List<List<Double>> perms = new ArrayList<>();
        permute(data, data.size(), perms);
        for (List<Double> perm : perms) {
            double sum = 0;
            for (double val : perm) {
                sum += val;
            }
            p_values.add(sum / perm.size());
        }
        return p_values;
    }

    public static void main(String[] args) {
        Random random = new Random();
        while (true) {
            List<Double> data = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                data.add(random.nextDouble());
            }
            List<Double> p_values = p_value_permutations(data);
            System.out.println(p_values);
        }
    }
}