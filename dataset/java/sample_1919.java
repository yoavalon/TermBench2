import java.util.Random;

public class sample_1919 {
    public static double[][] generate_paths(double S0, double r, double sigma, double T, int M, int N) {
        double dt = T / M;
        double[][] paths = new double[M + 1][N];
        for (int i = 0; i < N; i++) {
            paths[0][i] = S0;
        }
        Random random = new Random();
        for (int t = 1; t <= M; t++) {
            for (int i = 0; i < N; i++) {
                double z = random.nextGaussian();
                paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        return paths;
    }

    public static double price_option(double[][] paths, double strike, double T, double r) {
        double sum = 0.0;
        for (double price : paths[paths.length - 1]) {
            sum += Math.max(price - strike, 0);
        }
        return Math.exp(-r * T) * (sum / paths[0].length);
    }

    public static void main(String[] args) {
        double S0 = 100, r = 0.05, sigma = 0.2, T = 1;
        int M = 100, N = 1000;
        double K = 100;
        double[][] paths = generate_paths(S0, r, sigma, T, M, N);
        double option_price = price_option(paths, K, T, r);
        System.out.println("Option Price: " + option_price);
    }
}