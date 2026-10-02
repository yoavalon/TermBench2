import java.util.Random;

public class sample_0093 {
    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / M;
        double[][] S = new double[M + 1][N];
        S[0] = S0;
        Random random = new Random();
        for (int t = 1; t <= M; t++) {
            for (int i = 0; i < N; i++) {
                double Z = random.nextGaussian();
                S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        double payoff = 0;
        for (int i = 0; i < N; i++) {
            payoff += Math.max(S[M][i] - K, 0);
        }
        return Math.exp(-r * T) * (payoff / N);
    }

    public static void main(String[] args) {
        monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
    }
}