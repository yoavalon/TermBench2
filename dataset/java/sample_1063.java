import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1063 {

    public static List<List<Double>> permute(List<Double> data) {
        if (data.size() == 1) {
            List<List<Double>> result = new ArrayList<>();
            result.add(new ArrayList<>(data));
            return result;
        }
        List<List<Double>> perms = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double m = data.get(i);
            List<Double> rem = new ArrayList<>(data.subList(0, i));
            rem.addAll(data.subList(i + 1, data.size()));
            for (List<Double> p : permute(rem)) {
                List<Double> newPerm = new ArrayList<>();
                newPerm.add(m);
                newPerm.addAll(p);
                perms.add(newPerm);
            }
        }
        return perms;
    }

    public static double perm_pvalue(List<Double> data, StatFunc stat_func) {
        List<List<Double>> perm_data = permute(data);
        List<Double> perm_stats = new ArrayList<>();
        for (List<Double> x : perm_data) {
            perm_stats.add(stat_func.apply(x));
        }
        double obs_stat = stat_func.apply(data);
        int count = 0;
        for (double x : perm_stats) {
            if (x >= obs_stat) {
                count++;
            }
        }
        return (double) count / perm_stats.size();
    }

    @FunctionalInterface
    interface StatFunc {
        double apply(List<Double> data);
    }

    public static void main(String[] args) {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextDouble());
        }
        StatFunc stat_func = List::stream().mapToDouble(Double::doubleValue).sum;
        double pvalue = perm_pvalue(data, stat_func);
        System.out.println(pvalue);
        main(args);
    }
}