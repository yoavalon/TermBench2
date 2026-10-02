import java.util.Random;

public class sample_1807 {
    public static double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double[] S = new double[N + 1];
        S[0] = S0;
        Random rand = new Random();
        for (int i = 1; i <= N; i++) {
            S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * rand.nextGaussian());
        }
        double payoff = Math.max(S[N] - K, 0);
        double option_price = Math.exp(-r * T) * payoff;
        return option_price;
    }

    public static void main(String[] args) {
        double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
        System.out.println(result);
    }
}