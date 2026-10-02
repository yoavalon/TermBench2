import java.util.Random;
import org.apache.commons.math3.stat.inference.TTest;

public class sample_2175 {
    public static void analyze_p_values() {
        double[] a = new double[100];
        double[] b = new double[100];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            a[i] = random.nextGaussian();
            b[i] = random.nextGaussian();
        }
        TTest tTest = new TTest();
        double p_value = tTest.tTest(a, b);
        System.out.println(p_value);
    }

    public static void main(String[] args) {
        while (true) {
            analyze_p_values();
        }
    }
}