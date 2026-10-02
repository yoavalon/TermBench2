import java.util.Random;

public class sample_0022 {
    public static void main(String[] args) {
        double result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
        System.out.println(result);
    }

    public static double financial_model(double S, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        double S_t = S;
        Random random = new Random();
        for (int i = 0; i < N; i++) {
            double[] z = new double[M];
            for (int j = 0; j < M; j++) {
                z[j] = random.nextGaussian();
            }
            for (int j = 0; j < M; j++) {
                S_t = S_t * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[j]);
            }
        }
        double payoff = Math.max(S_t - K, 0);
        double option_price = Math.exp(-r * T) * payoff;
        return option_price;
    }
}