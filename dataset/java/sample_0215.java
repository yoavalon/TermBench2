import java.util.Random;

public class sample_0215 {
    public static double[][] simulate_paths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        paths[0] = new double[M];
        for (int i = 0; i < M; i++) {
            paths[0][i] = S0;
        }
        for (int t = 1; t <= N; t++) {
            Random rand = new Random();
            double[] z = new double[M];
            for (int i = 0; i < M; i++) {
                z[i] = rand.nextGaussian();
            }
            for (int i = 0; i < M; i++) {
                paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double[] payoff_function(double[][] paths, double K, String option_type) {
        double[] payoff = new double[paths[0].length];
        if (option_type.equals("call")) {
            for (int i = 0; i < paths[0].length; i++) {
                payoff[i] = Math.max(paths[paths.length - 1][i] - K, 0);
            }
        } else if (option_type.equals("put")) {
            for (int i = 0; i < paths[0].length; i++) {
                payoff[i] = Math.max(K - paths[paths.length - 1][i], 0);
            }
        }
        return payoff;
    }

    public static double price_option(double S0, double K, double T, double r, double sigma, int N, int M, String option_type) {
        double[][] paths = simulate_paths(S0, T, r, sigma, N, M);
        double[] payoff = payoff_function(paths, K, option_type);
        double sum = 0;
        for (double value : payoff) {
            sum += value;
        }
        return Math.exp(-r * T) * (sum / M);
    }

    public static void main(String[] args) {
        double S0 = 100.0;
        double K = 100.0;
        double T = 1.0;
        double r = 0.05;
        double sigma = 0.2;
        int N = 252;
        int M = 10000;
        String option_type = "call";
        double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
        System.out.println("Option Price: " + option_price);
    }
}