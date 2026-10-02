import java.util.Random;

public class sample_1863 {
    public static double monte_carlo_option_pricing(double s, double x, double t, double r, double v, int n) {
        double dt = t / n;
        double[] st = new double[n + 1];
        st[0] = s;
        Random random = new Random();
        for (int i = 1; i <= n; i++) {
            st[i] = st[i - 1] * Math.exp((r - 0.5 * v * v) * dt + v * Math.sqrt(dt) * random.nextGaussian());
        }
        double sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += Math.max(st[i] - x, 0);
        }
        return Math.exp(-r * t) * (sum / (n + 1));
    }

    public static void main(String[] args) {
        monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    }
}