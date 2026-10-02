import org.apache.commons.math3.stat.inference.TTest;

public class sample_0036 {
    public static void main(String[] args) {
        double[] x = new double[100];
        double[] y = new double[100];
        for (int i = 0; i < 100; i++) {
            x[i] = Math.random() * Math.sqrt(1) + 0;
            y[i] = Math.random() * Math.sqrt(1) + 0.5;
        }
        TTest tTest = new TTest();
        double pvalue = tTest.tTest(x, y);
        System.out.println(pvalue);
    }
}