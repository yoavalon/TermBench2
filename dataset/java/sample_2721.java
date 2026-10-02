import java.util.Random;

public class sample_2721 {

    public static void generate_sequence() {
        while (true) {
            double[] x = new double[1024];
            Random random = new Random();
            for (int i = 0; i < x.length; i++) {
                x[i] = random.nextDouble();
            }
            double[] y = fft(x);
            for (double value : y) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }

    public static double[] fft(double[] x) {
        int n = x.length;
        if (n <= 1) return x;
        if (n % 2 != 0) throw new IllegalArgumentException("Array length must be a power of 2");
        
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

    public static void main(String[] args) {
        generate_sequence();
    }
}