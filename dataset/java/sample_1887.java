import java.util.Random;

public class sample_1887 {
    public static double monte_carlo_option_pricing(double S, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        double[] S_T = new double[N];
        Random rand = new Random();
        for (int i = 0; i < N; i++) {
            S_T[i] = S * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * rand.nextGaussian());
        }
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += Math.max(S_T[i] - K, 0);
        }
        return Math.exp(-r * T) * (sum / N);
    }

    public static void main(String[] args) {
        double result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000);
        System.out.println(result);
    }
}