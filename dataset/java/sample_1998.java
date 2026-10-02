import java.util.Random;

public class sample_1998 {

    public static double[][] simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / M;
        double[][] paths = new double[N][M];
        for (int i = 0; i < N; i++) {
            paths[i][0] = S0;
        }
        for (int t = 1; t < M; t++) {
            Random rand = new Random();
            double[] z = new double[N];
            for (int i = 0; i < N; i++) {
                z[i] = rand.nextGaussian();
            }
            for (int i = 0; i < N; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double option_pricing(double[][] paths, double K, double T, double r, int M) {
        double payoff = 0;
        for (int i = 0; i < paths.length; i++) {
            payoff += Math.max(paths[i][M - 1] - K, 0);
        }
        double price = Math.exp(-r * T) * (payoff / paths.length);
        return price;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 10000;
        int M = 100;
        double[][] paths = simulate_paths(S0, T, r, sigma, N, M);
        double option_price = option_pricing(paths, K, T, r, M);
        System.out.println(option_price);
    }
}