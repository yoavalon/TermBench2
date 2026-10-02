import java.util.Random;

public class sample_1903 {
    public static double simulate_option_price(double S0, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double S = S0;
        Random random = new Random();
        for (int _ = 0; _ < N; _++) {
            S *= Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * random.nextGaussian());
        }
        return Math.max(S - K, 0);
    }

    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int M, int N) {
        double total = 0;
        for (int _ = 0; _ < M; _++) {
            total += simulate_option_price(S0, K, T, r, sigma, N);
        }
        return total / M * Math.exp(-r * T);
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int M = 1000;
        int N = 100;
        System.out.println(monte_carlo_pricing(S0, K, T, r, sigma, M, N));
    }
}