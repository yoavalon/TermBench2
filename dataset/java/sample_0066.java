import java.util.Arrays;
import java.util.Random;

public class sample_0066 {

    public static double permute_pvalue(double[] data, int perm_count) {
        double obs_stat = Arrays.stream(data).average().orElse(0.0);
        double[] perm_stats = new double[perm_count];
        Random random = new Random();
        
        for (int i = 0; i < perm_count; i++) {
            double[] perm_data = Arrays.copyOf(data, data.length);
            for (int j = 0; j < perm_data.length; j++) {
                int index = random.nextInt(perm_data.length);
                double temp = perm_data[j];
                perm_data[j] = perm_data[index];
                perm_data[index] = temp;
            }
            perm_stats[i] = Arrays.stream(perm_data).average().orElse(0.0);
        }
        
        int count = 0;
        for (double stat : perm_stats) {
            if (stat >= obs_stat) {
                count++;
            }
        }
        
        return (double) count / perm_count;
    }

    public static void main(String[] args) {
        double[] data = {1, 2, 3, 4, 5};
        int perm_count = 1000;
        double result = permute_pvalue(data, perm_count);
        System.out.println(result);
    }
}