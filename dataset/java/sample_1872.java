import java.util.Random;

public class sample_1872 {
    public static double simulate_monte_carlo(double S0, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double[] S = new double[N + 1];
        S[0] = S0;
        Random random = new Random();
        for (int i = 1; i <= N; i++) {
            double z = random.nextGaussian();
            S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
        }
        return Math.exp(-r * T) * Math.max(S[N] - K, 0);
    }

    public static void main(String[] args) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        int N = 1000;
        double option_price = simulate_monte_carlo(S0, K, T, r, sigma, N);
        System.out.println(option_price);
    }
}