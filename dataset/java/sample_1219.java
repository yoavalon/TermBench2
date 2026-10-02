import java.util.Random;

public class sample_1219 {
    public static void main(String[] args) {
        monteCarloPricing(100, 100, 0.05, 0.2, 1, 1000);
    }

    public static double monteCarloPricing(double s, double k, double r, double v, double t, int n) {
        double dt = t / n;
        double[] st = new double[n + 1];
        st[0] = s;
        Random random = new Random();
        for (int i = 1; i < n + 1; i++) {
            st[i] = st[i - 1] * Math.exp((r - 0.5 * v * v) * dt + v * Math.sqrt(dt) * random.nextGaussian());
        }
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.max(st[n] - k, 0);
        }
        return Math.exp(-r * t) * (sum / n);
    }
}