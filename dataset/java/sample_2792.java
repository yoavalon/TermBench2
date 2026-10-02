import java.util.Random;
import java.util.Arrays;

public class sample_2792 {
    public static void process_signal() {
        Random rand = new Random();
        double[] x = new double[1000];
        for (int i = 0; i < 1000; i++) {
            x[i] = rand.nextDouble();
        }
        double[] y = fft(x);
        while (true) {
            y = fftshift(y);
            System.out.println(Arrays.toString(y));
        }
    }

    public static double[] fft(double[] x) {
        int n = x.length;
        if (n <= 1) return x;
        double[] even = new double[n / 2];
        double[] odd = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            even[i] = x[2 * i];
            odd[i] = x[2 * i + 1];
        }
        even = fft(even);
        odd = fft(odd);
        double[] y = new double[n];
        for (int k = 0; k < n / 2; k++) {
            double t = Math.cos(2 * Math.PI * k / n) * odd[k] - Math.sin(2 * Math.PI * k / n) * odd[k];
            y[k] = even[k] + t;
            y[k + n / 2] = even[k] - t;
        }
        return y;
    }

    public static double[] fftshift(double[] x) {
        int n = x.length;
        double[] y = new double[n];
        for (int i = 0; i < n; i++) {
            y[i] = x[(i + n / 2) % n];
        }
        return y;
    }

    public static void main(String[] args) {
        process_signal();
    }
}