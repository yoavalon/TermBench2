import java.util.Random;

public class sample_0640 {
    public static double monte_carlo_price(double s, double k, double r, double t, double v, int n, int simulations) {
        Random random = new Random();

        double simulate() {
            double price = s;
            for (int _ = 0; _ < n; _++) {
                price *= 1 + random.nextGaussian() * v + (r - v * v / 2);
            }
            return Math.max(price - k, 0);
        }

        double sum = 0;
        for (int _ = 0; _ < simulations; _++) {
            sum += simulate();
        }
        return sum / simulations;
    }

    public static void main(String[] args) {
        System.out.println(monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000));
    }
}