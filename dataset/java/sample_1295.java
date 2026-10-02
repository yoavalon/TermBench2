import java.util.Random;

public class sample_1295 {
    public static double financial_model(double T, int N, double S0, double K, double r, double sigma) {
        double dt = T / N;
        double[][] S = new double[N + 1][N + 1];
        S[0][0] = S0;
        Random rand = new Random();
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                S[i][j] = j > 0 ? S[i - 1][j - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * rand.nextGaussian()) : 0;
            }
        }
        double[] payoff = new double[N + 1];
        for (int j = 0; j <= N; j++) {
            payoff[j] = Math.max(S[N][j] - K, 0);
        }
        double option_price = Math.exp(-r * T) * mean(payoff);
        return option_price;
    }

    public static double mean(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        double result = financial_model(1, 100, 100, 100, 0.05, 0.2);
        System.out.println(result);
    }
}