import java.util.Random;

public class sample_1845 {

    public static double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double[] S_t = new double[N + 1];
        S_t[0] = S;
        Random random = new Random();
        double[] z = new double[N];
        for (int i = 0; i < N; i++) {
            z[i] = random.nextGaussian();
        }
        for (int i = 1; i <= N; i++) {
            S_t[i] = S_t[i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i - 1]);
        }
        double payoff = Math.max(S_t[N] - K, 0);
        double option_price = Math.exp(-r * T) * payoff;
        return option_price;
    }

    public static void main(String[] args) {
        double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
        System.out.println(result);
    }
}