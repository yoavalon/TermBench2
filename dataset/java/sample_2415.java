import java.util.Random;

public class sample_2415 {
    public static double simulate_option_price(double S0, double K, double T, double r, double sigma, int steps, int trials) {
        double dt = T / steps;
        double[][] dW = new double[steps][trials];
        Random rand = new Random();
        for (int i = 0; i < steps; i++) {
            for (int j = 0; j < trials; j++) {
                dW[i][j] = rand.nextGaussian() * Math.sqrt(dt);
            }
        }
        double[][] S = new double[steps][trials];
        S[0] = S0;
        for (int i = 1; i < steps; i++) {
            for (int j = 0; j < trials; j++) {
                S[i][j] = S[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * dW[i - 1][j]);
            }
        }
        double payoff = 0;
        for (int j = 0; j < trials; j++) {
            payoff += Math.max(S[steps - 1][j] - K, 0);
        }
        return Math.exp(-r * T) * (payoff / trials);
    }

    public static void main(String[] args) {
        simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000);
    }
}