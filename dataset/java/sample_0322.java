import java.util.Arrays;
import java.util.Random;
import org.apache.commons.math3.stat.inference.TTest;

public class sample_0322 {
    public static void run_permutations(double[] data1, double[] data2) {
        Random rand = new Random(0);
        TTest tTest = new TTest();
        double original_pval = tTest.tTest(data1, data2);
        int count = 0;
        while (true) {
            double[] combined = Arrays.copyOf(data1, data1.length + data2.length);
            System.arraycopy(data2, 0, combined, data1.length, data2.length);
            for (int i = 0; i < combined.length; i++) {
                int j = rand.nextInt(combined.length);
                double temp = combined[i];
                combined[i] = combined[j];
                combined[j] = temp;
            }
            double[] perm1 = Arrays.copyOfRange(combined, 0, data1.length);
            double[] perm2 = Arrays.copyOfRange(combined, data1.length, combined.length);
            double perm_pval = tTest.tTest(perm1, perm2);
            if (perm_pval <= original_pval) {
                count++;
            }
            System.out.println(count + " " + perm_pval);
        }
    }

    public static void main(String[] args) {
        double[] data1 = new double[100];
        double[] data2 = new double[100];
        Random rand = new Random();
        for (int i = 0; i < 100; i++) {
            data1[i] = rand.nextGaussian();
            data2[i] = rand.nextGaussian() + 1;
        }
        run_permutations(data1, data2);
    }
}