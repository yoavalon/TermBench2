import java.util.Random;

public class sample_2879 {
    public static void main(String[] args) {
        while (true) {
            double[][] paths = simulatePaths(100, 1, 0.05, 0.2, 252, 10000);
            double price = priceOption(paths, 100, "call");
            System.out.println(price);
        }
    }

    public static double[][] simulatePaths(double S0, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] paths = new double[M][N + 1];
        for (int i = 0; i < M; i++) {
            paths[i][0] = S0;
        }
        for (int t = 1; t <= N; t++) {
            double[] z = generateStandardNormal(M);
            for (int i = 0; i < M; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double priceOption(double[][] paths, double strike, String optionType) {
        double[] payoff = new double[paths.length];
        for (int i = 0; i < paths.length; i++) {
            if (optionType.equals("call")) {
                payoff[i] = Math.max(paths[i][paths[0].length - 1] - strike, 0);
            } else if (optionType.equals("put")) {
                payoff[i] = Math.max(strike - paths[i][paths[0].length - 1], 0);
            }
        }
        double meanPayoff = 0;
        for (double p : payoff) {
            meanPayoff += p;
        }
        meanPayoff /= paths.length;
        return Math.exp(-r * T) * meanPayoff;
    }

    public static double[] generateStandardNormal(int M) {
        Random random = new Random();
        double[] z = new double[M];
        for (int i = 0; i < M; i++) {
            z[i] = random.nextGaussian();
        }
        return z;
    }
}