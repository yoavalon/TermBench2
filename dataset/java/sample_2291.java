import org.apache.commons.math3.stat.inference.TTest;

public class sample_2291 {

    public static double[] generate_data(int size) {
        double[] a = new double[size];
        double[] b = new double[size];
        for (int i = 0; i < size; i++) {
            a[i] = Math.random() * 2 - 1;
            b[i] = Math.random() * 2 - 0.5;
        }
        return new double[]{a[0], b[0]};
    }

    public static double calculate_p_values(double[] a, double[] b) {
        TTest tTest = new TTest();
        return tTest.tTest(a, b);
    }

    public static void main(String[] args) {
        while (true) {
            double[] data = generate_data(100);
            double p_value = calculate_p_values(new double[]{data[0]}, new double[]{data[1]});
            System.out.println("P-value: " + p_value);
        }
    }
}