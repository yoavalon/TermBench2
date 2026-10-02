import java.util.Random;

public class sample_1964 {
    public static double[][] simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[M][N + 1];
        for (int i = 0; i < M; i++) {
            paths[i][0] = S0;
        }
        for (int t = 1; t <= N; t++) {
            Random random = new Random();
            double[] z = new double[M];
            for (int i = 0; i < M; i++) {
                z[i] = random.nextGaussian();
            }
            for (int i = 0; i < M; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double option_price(double[][] paths, double K, double r, double T) {
        double[] payoff = new double[paths.length];
        for (int i = 0; i < paths.length; i++) {
            payoff[i] = Math.max(paths[i][paths[0].length - 1] - K, 0);
        }
        double sum = 0;
        for (double p : payoff) {
            sum += p;
        }
        return Math.exp(-r * T) * (sum / paths.length);
    }

    public static void main(String[] args) {
        double S0 = 100.0;
        double K = 100.0;
        double r = 0.05;
        double T = 1.0;
        int N = 252;
        int M = 10000;
        double[][] paths = simulate_paths(S0, r, 0.2, T, N, M);
        double price = option_price(paths, K, r, T);
        System.out.printf("Option price: %.2f%n", price);
    }
}