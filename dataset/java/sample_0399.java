import java.util.Random;

public class sample_0399 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        System.out.println(financial_model(100, 100, 1, 0.05, 0.2));
    }

    public static double financial_model(double S0, double K, double T, double r, double sigma) {
        int N = 10000;
        double dt = T / N;
        double[][] S = new double[N + 1][N + 1];
        S[0][0] = S0;
        Random random = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i <= t; i++) {
                double Z = random.nextGaussian();
                S[t][i] = S[t - 1][i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
            }
        }
        double sum = 0;
        for (int i = 0; i <= N; i++) {
            sum += Math.max(S[N][i] - K, 0);
        }
        return sum / (N + 1);
    }
}