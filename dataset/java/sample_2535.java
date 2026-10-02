import java.util.Random;

public class sample_2535 {
    public static double[][] simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        paths[0] = new double[M];
        for (int i = 0; i < M; i++) {
            paths[0][i] = S0;
        }
        Random random = new Random();
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                double z = random.nextGaussian();
                paths[i][j] = paths[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        return paths;
    }

    public static double[] calculate_payoff(double[][] paths, double K, double T) {
        double[] ST = paths[paths.length - 1];
        double[] payoff = new double[ST.length];
        for (int i = 0; i < ST.length; i++) {
            payoff[i] = Math.max(ST[i] - K, 0);
        }
        return payoff;
    }

    public static double monte_carlo_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
        double[][] paths = simulate_paths(S0, T, r, sigma, N, M);
        double[] payoff = calculate_payoff(paths, K, T);
        double option_price = Math.exp(-r * T) * mean(payoff);
        return option_price;
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        double price = monte_carlo_pricing(S0, K, T, r, sigma, N, M);
        System.out.println("Option Price: " + price);
    }
}