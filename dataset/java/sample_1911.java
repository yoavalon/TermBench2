import java.util.Random;

public class sample_1911 {

    public static double[][] simulatePaths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] S = new double[N + 1][M];
        S[0] = S0;
        Random rand = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < M; i++) {
                double Z = rand.nextGaussian();
                S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        return S;
    }

    public static double optionPrice(double[][] S, double K, double T, double r, String type) {
        double[] payoff = new double[S[S.length - 1].length];
        for (int i = 0; i < payoff.length; i++) {
            if (type.equals("call")) {
                payoff[i] = Math.max(S[S.length - 1][i] - K, 0);
            } else {
                payoff[i] = Math.max(K - S[S.length - 1][i], 0);
            }
        }
        double price = Math.exp(-r * T) * mean(payoff);
        return price;
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double num : array) {
            sum += num;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        int N = 100, M = 10000;
        double[][] S = simulatePaths(S0, T, r, sigma, N, M);
        double price = optionPrice(S, K, T, r, "call");
        System.out.println(price);
    }
}