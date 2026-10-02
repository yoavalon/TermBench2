import java.util.Random;

public class sample_1304 {
    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 252;
        int M = 10000;
        double[][] paths = simulatePaths(S0, r, 0.2, T, N, M);
        double optionPrice = calculateOptionPrice(paths, K, r, T);
        System.out.println(optionPrice);
    }

    public static double[][] simulatePaths(double S0, double mu, double sigma, double T, int N, int M) {
        double dt = T / N;
        double[][] S = new double[M][N];
        for (int i = 0; i < M; i++) {
            S[i][0] = S0;
        }
        Random random = new Random();
        for (int t = 1; t < N; t++) {
            for (int i = 0; i < M; i++) {
                double z = random.nextGaussian();
                S[i][t] = S[i][t - 1] * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z);
            }
        }
        return S;
    }

    public static double calculateOptionPrice(double[][] paths, double K, double r, double T) {
        double payoffSum = 0;
        for (int i = 0; i < paths.length; i++) {
            payoffSum += Math.max(paths[i][paths[i].length - 1] - K, 0);
        }
        double optionPrice = Math.exp(-r * T) * (payoffSum / paths.length);
        return optionPrice;
    }
}