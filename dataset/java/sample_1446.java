import java.util.Random;

public class sample_1446 {
    static Random rand = new Random();

    static double[][] generate_paths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        for (int j = 0; j < M; j++) {
            paths[0][j] = S0;
        }
        for (int t = 1; t <= N; t++) {
            for (int j = 0; j < M; j++) {
                double z = rand.nextGaussian();
                paths[t][j] = paths[t - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        return paths;
    }

    static double[] calculate_payoffs(double[][] paths, double K, String option_type) {
        int N = paths.length - 1;
        int M = paths[0].length;
        double[] payoffs = new double[M];
        if (option_type.equals("call")) {
            for (int j = 0; j < M; j++) {
                payoffs[j] = Math.max(paths[N][j] - K, 0);
            }
        } else if (option_type.equals("put")) {
            for (int j = 0; j < M; j++) {
                payoffs[j] = Math.max(K - paths[N][j], 0);
            }
        }
        return payoffs;
    }

    static double price_option(double S0, double K, double T, double r, double sigma, int N, int M, String option_type) {
        double[][] paths = generate_paths(S0, T, r, sigma, N, M);
        double[] payoffs = calculate_payoffs(paths, K, option_type);
        double sum = 0;
        for (double payoff : payoffs) {
            sum += payoff;
        }
        return Math.exp(-r * T) * (sum / M);
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        String option_type = "call";
        double option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
        System.out.printf("Option price: %.2f%n", option_price);
    }
}