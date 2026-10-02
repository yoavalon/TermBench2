import java.util.Random;

public class sample_1997 {
    public static double[][] simulatePaths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        paths[0] = new double[M];
        for (int i = 0; i < M; i++) {
            paths[0][i] = S0;
        }
        Random random = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < M; i++) {
                double Z = random.nextGaussian();
                paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        return paths;
    }

    public static double optionPrice(double[][] paths, double K, double r, double T, int N) {
        double[] discountedPayoffs = new double[paths[paths.length - 1].length];
        for (int i = 0; i < discountedPayoffs.length; i++) {
            discountedPayoffs[i] = Math.exp(-r * T) * Math.max(paths[paths.length - 1][i] - K, 0);
        }
        double sum = 0;
        for (double payoff : discountedPayoffs) {
            sum += payoff;
        }
        return sum / discountedPayoffs.length;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        double[][] paths = simulatePaths(S0, T, r, sigma, N, M);
        double price = optionPrice(paths, K, r, T, N);
        System.out.println(price);
    }
}