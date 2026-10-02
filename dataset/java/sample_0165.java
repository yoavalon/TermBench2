import java.util.Random;

public class sample_0165 {

    public static double[][] generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        double[][] S = new double[N + 1][M];
        S[0] = S0;
        Random random = new Random();
        for (int t = 1; t <= N; t++) {
            for (int m = 0; m < M; m++) {
                S[t][m] = S[t - 1][m] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * random.nextGaussian());
            }
        }
        return S;
    }

    public static double option_price(double[][] paths, double K, double r, double T, double[] payoff) {
        double[] discounted_payoffs = new double[payoff.length];
        for (int i = 0; i < payoff.length; i++) {
            discounted_payoffs[i] = Math.exp(-r * T) * payoff[i];
        }
        double sum = 0;
        for (double dp : discounted_payoffs) {
            sum += dp;
        }
        return sum / discounted_payoffs.length;
    }

    public static double[] european_call(double[] S, double K) {
        double[] payoff = new double[S.length];
        for (int i = 0; i < S.length; i++) {
            payoff[i] = Math.max(S[i] - K, 0);
        }
        return payoff;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 252;
        int M = 10000;
        double sigma = 0.2;
        double mu = 0.1;

        double[][] paths = generate_paths(S0, mu, sigma, T, N, M);
        double[] payoff = european_call(paths[N], K);
        double call_price = option_price(paths, K, r, T, payoff);
        System.out.println(call_price);
    }
}