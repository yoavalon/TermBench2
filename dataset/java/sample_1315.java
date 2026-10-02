import java.util.Random;

public class sample_1315 {
    public static double[][] generate_paths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        paths[0] = new double[M];
        for (int i = 0; i < M; i++) {
            paths[0][i] = S0;
        }
        Random rand = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < M; i++) {
                double z = rand.nextGaussian();
                paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        return paths;
    }

    public static double option_price(double[][] paths, double K, double r, double T) {
        int M = paths[paths.length - 1].length;
        double payoffSum = 0;
        for (int i = 0; i < M; i++) {
            payoffSum += Math.max(paths[paths.length - 1][i] - K, 0);
        }
        return Math.exp(-r * T) * (payoffSum / M);
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double sigma = 0.2;
        double T = 1;
        int N = 252;
        int M = 10000;
        double[][] paths = generate_paths(S0, T, r, sigma, N, M);
        double price = option_price(paths, K, r, T);
        System.out.println(price);
    }
}