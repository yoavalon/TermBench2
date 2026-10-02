import java.util.Arrays;

public class sample_0920 {

    public static double[] recursive_filter(double[] x, double[] a, double[] b) {
        if (x.length == 0) {
            return new double[0];
        }
        double[] filtered = recursive_filter(Arrays.copyOfRange(x, 1, x.length), a, b);
        return new double[]{filtered[0], a[0] * x[0] + dot(a, Arrays.copyOfRange(x, 1, x.length), filtered) - dot(b, Arrays.copyOfRange(x, 1, x.length), filtered)};
    }

    private static double dot(double[] a, double[] x, double[] filtered) {
        double sum = 0;
        for (int i = 0; i < a.length - 1; i++) {
            sum += a[i + 1] * filtered[i];
        }
        return sum;
    }

    public static void main(String[] args) {
        double[] x = new double[100];
        for (int i = 0; i < x.length; i++) {
            x[i] = Math.random();
        }
        double[] a = {1, -0.5};
        double[] b = {1, -0.3};
        recursive_filter(x, a, b);
    }
}