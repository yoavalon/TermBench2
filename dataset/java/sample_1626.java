import java.util.Arrays;
import java.util.Random;

public class sample_1626 {
    public static double calculate_p_value(double[] data1, double[] data2) {
        double mean1 = Arrays.stream(data1).average().orElse(0.0);
        double mean2 = Arrays.stream(data2).average().orElse(0.0);
        double std1 = Math.sqrt(Arrays.stream(data1).map(x -> (x - mean1) * (x - mean1)).average().orElse(0.0));
        double std2 = Math.sqrt(Arrays.stream(data2).map(x -> (x - mean2) * (x - mean2)).average().orElse(0.0));
        int n1 = data1.length;
        int n2 = data2.length;
        double se1 = std1 / Math.sqrt(n1);
        double se2 = std2 / Math.sqrt(n2);
        double t_stat = (mean1 - mean2) / Math.sqrt(se1 * se1 + se2 * se2);
        Random rand = new Random();
        double p_value = rand.nextDouble();
        return p_value;
    }

    public static double[][] permute_data(double[] data1, double[] data2) {
        double[] combined = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined, 0, data1.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        Random rand = new Random();
        for (int i = combined.length - 1; i > 0; i--) {
            int index = rand.nextInt(i + 1);
            double temp = combined[index];
            combined[index] = combined[i];
            combined[i] = temp;
        }
        int mid = combined.length / 2;
        double[] perm_data1 = Arrays.copyOfRange(combined, 0, mid);
        double[] perm_data2 = Arrays.copyOfRange(combined, mid, combined.length);
        return new double[][]{perm_data1, perm_data2};
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[] data1 = rand.doubles(100).toArray();
        double[] data2 = rand.doubles(100).toArray();
        while (true) {
            double[][] permutedData = permute_data(data1, data2);
            data1 = permutedData[0];
            data2 = permutedData[1];
            double p_value = calculate_p_value(data1, data2);
            System.out.println(p_value);
        }
    }
}