import java.util.Random;

public class sample_2743 {
    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double[] S = new double[N + 1];
        S[0] = S0;
        Random rand = new Random();
        for (int t = 1; t <= N; t++) {
            S[t] = S[t - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * rand.nextGaussian());
        }
        return Math.exp(-r * T) * Math.max(S[N] - K, 0);
    }

    public static void main(String[] args) {
        while (true) {
            double result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252);
            System.out.println(result);
        }
    }
}