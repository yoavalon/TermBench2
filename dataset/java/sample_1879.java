import java.util.Random;

public class sample_1879 {
    public static double monte_carlo_pricing(double[] S, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double mu = r - 0.5 * sigma * sigma;
        double[][] S_paths = new double[N + 1][S.length];
        System.arraycopy(S, 0, S_paths[0], 0, S.length);
        Random random = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < S.length; i++) {
                double z = random.nextGaussian();
                S_paths[t][i] = S_paths[t - 1][i] * Math.exp(mu * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        double payoff = 0;
        for (double price : S_paths[N]) {
            payoff += Math.max(price - K, 0);
        }
        return Math.exp(-r * T) * (payoff / S.length);
    }

    public static void main(String[] args) {
        monte_carlo_pricing(new double[]{100}, 100, 1, 0.05, 0.2, 100000);
    }
}