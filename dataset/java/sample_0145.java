import java.util.Random;

public class sample_0145 {
    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        int M = 10000;
        double[][] paths = simulatePaths(S0, K, T, r, sigma, N, M);
        double price = optionPrice(paths, K, r, T);
        System.out.println(price);
    }

    public static double[][] simulatePaths(double S0, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] S = new double[N + 1][M];
        S[0] = S0;
        Random random = new Random();
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                double Z = random.nextGaussian();
                S[i][j] = S[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        return S;
    }

    public static double optionPrice(double[][] paths, double K, double r, double T) {
        double[] payoff = new double[paths[paths.length - 1].length];
        for (int i = 0; i < payoff.length; i++) {
            payoff[i] = Math.max(paths[paths.length - 1][i] - K, 0);
        }
        double price = Math.exp(-r * T) * average(payoff);
        return price;
    }

    public static double average(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }
}