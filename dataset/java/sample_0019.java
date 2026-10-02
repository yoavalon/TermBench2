import java.util.Random;

public class sample_0019 {
    public static double calculate_option_price(double S, double K, double r, double T, double sigma, int N) {
        double dt = T / N;
        double dS = S * sigma * Math.sqrt(dt);
        double[] paths = new double[N];
        paths[0] = S;
        Random rand = new Random();
        for (int i = 1; i < N; i++) {
            paths[i] = paths[i - 1] * Math.exp((r - 0.5 * sigma * sigma) * dt + dS * rand.nextGaussian());
        }
        double payoff = Math.max(paths[N - 1] - K, 0);
        return Math.exp(-r * T) * payoff;
    }

    public static void main(String[] args) {
        double result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
        System.out.println(result);
    }
}