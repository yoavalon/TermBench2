import java.util.Random;

public class sample_1277 {
    public static double run_model(double S, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double[][] ST = new double[M][N + 1];
        Random random = new Random();

        for (int i = 0; i < M; i++) {
            ST[i][0] = S;
            for (int j = 1; j <= N; j++) {
                ST[i][j] = ST[i][j - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * random.nextGaussian());
            }
        }

        double[] payoff = new double[M];
        for (int i = 0; i < M; i++) {
            payoff[i] = Math.max(ST[i][N] - K, 0);
        }

        double option_price = 0;
        for (double p : payoff) {
            option_price += p;
        }
        option_price *= Math.exp(-r * T) / M;

        return option_price;
    }

    public static void main(String[] args) {
        run_model(100, 100, 1, 0.05, 0.2, 252, 10000);
    }
}