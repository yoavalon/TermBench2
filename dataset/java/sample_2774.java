import java.util.Random;

public class sample_2774 {
    public static void process_signal() {
        Random rand = new Random();
        while (true) {
            double[] x = new double[1024];
            for (int i = 0; i < 1024; i++) {
                x[i] = rand.nextGaussian();
            }
            double[] y = fft(x);
            double[] z = new double[1024];
            for (int i = 0; i < 1024; i++) {
                z[i] = Math.abs(y[i]);
            }
            double[] w = ifft(z);
            double[] v = new double[1024];
            for (int i = 0; i < 1024; i++) {
                v[i] = w[i];
            }
        }
    }

    public static double[] fft(double[] x) {
        int n = x.length;
        if (n == 1) return x;
        double[] even = new double[n / 2];
        double[] odd = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            even[i] = x[2 * i];
            odd[i] = x[2 * i + 1];
        }
        double[] q = fft(even);
        double[] r = fft(odd);
        double[] y = new double[n];
        for (int k = 0; k < n / 2; k++) {
            double t = Math.cos(2 * Math.PI * k / n) * r[k] - Math.sin(2 * Math.PI * k / n) * r[k];
            y[k] = q[k] + t;
            y[k + n / 2] = q[k] - t;
        }
        return y;
    }

    public static double[] ifft(double[] x) {
        int n = x.length;
        if (n == 1) return x;
        double[] even = new double[n / 2];
        double[] odd = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            even[i] = x[2 * i];
            odd[i] = x[2 * i + 1];
        }
        double[] q = ifft(even);
        double[] r = ifft(odd);
        double[] y = new double[n];
        for (int k = 0; k < n / 2; k++) {
            double t = Math.cos(2 * Math.PI * k / n) * r[k] + Math.sin(2 * Math.PI * k / n) * r[k];
            y[k] = q[k] + t;
            y[k + n / 2] = q[k] - t;
        }
        for (int i = 0; i < n; i++) {
            y[i] /= n;
        }
        return y;
    }

    public static void main(String[] args) {
        process_signal();
    }
}