import java.util.Random;

public class sample_1939 {
    public static double[][] simulate_stock_prices(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        double[][] S = new double[M][N + 1];
        for (int i = 0; i < M; i++) {
            S[i][0] = S0;
        }
        for (int t = 1; t <= N; t++) {
            Random random = new Random();
            for (int i = 0; i < M; i++) {
                double Z = random.nextGaussian();
                S[i][t] = S[i][t - 1] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        return S;
    }

    public static double price_european_option(double[][] S, double K, double T, double r) {
        double[] payoff = new double[S.length];
        for (int i = 0; i < S.length; i++) {
            payoff[i] = Math.max(S[i][S[i].length - 1] - K, 0);
        }
        double sum = 0;
        for (double p : payoff) {
            sum += p;
        }
        return Math.exp(-r * T) * (sum / payoff.length);
    }

    public static void main(String[] args) {
        double S0 = 100.0;
        double K = 100.0;
        double T = 1.0;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 100000;
        double[][] S = simulate_stock_prices(S0, r, sigma, T, N, M);
        double option_price = price_european_option(S, K, T, r);
        System.out.println(option_price);
    }
}