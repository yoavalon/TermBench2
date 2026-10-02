import java.util.Random;

public class sample_0432 {

    public static double[][] simulate_paths(double S0, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[N + 1][M];
        for (int j = 0; j < M; j++) {
            paths[0][j] = S0;
        }
        for (int i = 1; i <= N; i++) {
            Random rand = new Random();
            double[] Z = new double[M];
            for (int j = 0; j < M; j++) {
                Z[j] = rand.nextGaussian();
            }
            for (int j = 0; j < M; j++) {
                paths[i][j] = paths[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z[j]);
            }
        }
        return paths;
    }

    public static double calculate_payoffs(double[][] paths, double K, double T, double r, int M) {
        double[] S_T = paths[paths.length - 1];
        double payoff = 0;
        for (int j = 0; j < M; j++) {
            payoff += Math.max(S_T[j] - K, 0);
        }
        double option_value = Math.exp(-r * T) * (payoff / M);
        return option_value;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 252;
        int M = 100000;
        while (true) {
            double[][] paths = simulate_paths(S0, K, T, r, sigma, N, M);
            double option_value = calculate_payoffs(paths, K, T, r, M);
            System.out.println(option_value);
        }
    }
}