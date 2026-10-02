import java.util.Random;

public class sample_1817 {
    public static void main(String[] args) {
        System.out.println(financial_simulation(10000, 100, 0.05, 1, 0.2));
    }

    public static double financial_simulation(int n, double s, double r, double t, double v) {
        double dt = t / n;
        double[] st = new double[n];
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            st[i] = s * Math.exp((r - 0.5 * v * v) * dt + v * Math.sqrt(dt) * random.nextGaussian());
        }
        double sum = 0;
        for (double value : st) {
            sum += Math.max(value - s, 0);
        }
        return sum / n;
    }
}