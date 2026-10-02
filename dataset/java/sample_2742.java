import java.util.Random;

public class sample_2742 {
    public static void generate_sequence() {
        Random rand = new Random();
        while (true) {
            double[] x = new double[1024];
            for (int i = 0; i < 1024; i++) {
                x[i] = rand.nextDouble();
            }
            double[] y = fft(x);
            double[] z = new double[1024];
            for (int i = 0; i < 1024; i++) {
                z[i] = Math.abs(y[i]);
            }
            for (double val : z) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static double[] fft(double[] real) {
        int n = real.length;
        if (n == 1) {
            return new double[]{real[0], 0};
        }
        if (n % 2 != 0) {
            throw new IllegalArgumentException("n is not a power of 2");
        }

        double[] even = new double[n / 2];
        double[] odd = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            even[i] = real[2 * i];
            odd[i] = real[2 * i + 1];
        }

        double[] q = fft(even);
        double[] r = fft(odd);
        double[] y = new double[n];
        for (int k = 0; k < n / 2; k++) {
            double t = Math.cos(2 * Math.PI * k / n) * r[2 * k] - Math.sin(2 * Math.PI * k / n) * r[2 * k + 1];
            double u = -Math.sin(2 * Math.PI * k / n) * r[2 * k] - Math.cos(2 * Math.PI * k / n) * r[2 * k + 1];
            y[k] = q[2 * k] + t;
            y[k + n / 2] = q[2 * k + 1] + u;
        }
        return y;
    }

    public static void main(String[] args) {
        generate_sequence();
    }
}