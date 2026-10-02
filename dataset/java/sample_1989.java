import java.util.Random;

public class sample_1989 {
    public static double[][] simulate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        for (int i = 0; i < M; i++) {
            paths[0][i] = S0;
        }
        for (int t = 1; t <= N; t++) {
            double[] rand = new double[M];
            Random random = new Random();
            for (int i = 0; i < M; i++) {
                rand[i] = random.nextGaussian();
            }
            for (int i = 0; i < M; i++) {
                paths[t][i] = paths[t - 1][i] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * rand[i]);
            }
        }
        return paths;
    }

    public static double option_price(double[][] paths, double K, double r, double T) {
        double sum = 0.0;
        for (int i = 0; i < paths[paths.length - 1].length; i++) {
            sum += Math.max(paths[paths.length - 1][i] - K, 0);
        }
        return Math.exp(-r * T) * (sum / paths[paths.length - 1].length);
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 252;
        int M = 10000;
        double[][] paths = simulate_paths(S0, r, 0.2, T, N, M);
        double price = option_price(paths, K, r, T);
        System.out.printf("Option Price: %.4f%n", price);
    }
}