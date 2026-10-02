import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1030 {

    public static double[] permute(double[] data1, double[] data2) {
        double[] combined = new double[data1.length + data2.length];
        System.arraycopy(data1, 0, combined, 0, data1.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        Collections.shuffle(Arrays.asList(combined));
        int mid = combined.length / 2;
        double[] group1 = Arrays.copyOfRange(combined, 0, mid);
        double[] group2 = Arrays.copyOfRange(combined, mid, combined.length);
        return new double[]{group1, group2};
    }

    public static double calculate_pvalue(double[] data1, double[] data2) {
        double mean1 = 0, mean2 = 0;
        for (double num : data1) {
            mean1 += num;
        }
        mean1 /= data1.length;
        for (double num : data2) {
            mean2 += num;
        }
        mean2 /= data2.length;
        return mean1 - mean2;
    }

    public static void recurse(double[] data1, double[] data2, List<Double> pvalues) {
        double[][] groups = permute(data1, data2);
        pvalues.add(calculate_pvalue(groups[0], groups[1]));
        recurse(data1, data2, pvalues);
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        for (int i = 0; i < 100; i++) {
            data1[i] = rand.nextDouble();
            data2[i] = rand.nextDouble();
        }
        List<Double> pvalues = new ArrayList<>();
        recurse(data1, data2, pvalues);
    }
}