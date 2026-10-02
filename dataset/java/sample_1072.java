import java.util.Random;

public class sample_1072 {
    static Random random = new Random();

    static double price_option(double s, double k, double t, double r, double v) {
        if (t == 0) {
            return Math.max(0, s - k);
        }
        double dt = 0.1;
        double u = 1 + r * dt + v * random.nextGaussian() * Math.sqrt(dt);
        double d = 1 + r * dt - v * random.nextGaussian() * Math.sqrt(dt);
        double p = (1 - r * dt) / (u - d);
        double pu = price_option(s * u, k, t - dt, r, v);
        double pd = price_option(s * d, k, t - dt, r, v);
        return p * pu + (1 - p) * pd;
    }

    public static void main(String[] args) {
        while (true) {
            price_option(100, 100, 1, 0.05, 0.2);
        }
    }
}