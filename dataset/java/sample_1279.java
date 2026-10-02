import java.util.Random;

public class sample_1279 {

    public static double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / M;
        double[][] S_t = new double[N][M + 1];
        for (int i = 0; i < N; i++) {
            S_t[i][0] = S;
        }
        for (int t = 1; t <= M; t++) {
            Random rand = new Random();
            for (int i = 0; i < N; i++) {
                double z = rand.nextGaussian();
                S_t[i][t] = S_t[i][t - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        double[] payoff = new double[N];
        for (int i = 0; i < N; i++) {
            payoff[i] = Math.max(S_t[i][M] - K, 0);
        }
        double option_price = Math.exp(-r * T);
        double sum = 0;
        for (double p : payoff) {
            sum += p;
        }
        option_price *= sum / N;
        return option_price;
    }

    public static void main(String[] args) {
        monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
    }
}