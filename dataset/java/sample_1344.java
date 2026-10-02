import java.util.Random;

public class sample_1344 {

    public static double[] simulate_geometric_brownian_motion(double S0, double mu, double sigma, double T, int N) {
        double dt = T / N;
        double[] t = new double[N];
        double[] W = new double[N];
        double[] S = new double[N];
        Random rand = new Random();

        for (int i = 0; i < N; i++) {
            t[i] = i * dt;
            W[i] = rand.nextGaussian();
        }

        for (int i = 1; i < N; i++) {
            W[i] = W[i - 1] + W[i] * Math.sqrt(dt);
        }

        for (int i = 0; i < N; i++) {
            S[i] = S0 * Math.exp((mu - 0.5 * sigma * sigma) * t[i] + sigma * W[i]);
        }

        return S;
    }

    public static double monte_carlo_option_pricing(double S0, double K, double T, double r, double sigma, int N, int M) {
        double[] option_values = new double[M];
        Random rand = new Random();

        for (int i = 0; i < M; i++) {
            double[] S = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
            double payoff = Math.max(S[N - 1] - K, 0);
            option_values[i] = payoff;
        }

        double mean = 0;
        for (double value : option_values) {
            mean += value;
        }
        mean /= M;

        return Math.exp(-r * T) * mean;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        double result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
        System.out.println(result);
    }
}