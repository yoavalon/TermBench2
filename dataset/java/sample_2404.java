import java.util.Random;

public class sample_2404 {
    public static double financial_model(double S, double K, double T, double r, double sigma, int N) {
        double dt = T / N;
        Random random = new Random();
        double dS = S * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * random.nextGaussian());
        double payoff = Math.max(dS - K, 0);
        double option_price = Math.exp(-r * T) * payoff;
        return option_price;
    }

    public static void main(String[] args) {
        financial_model(100, 100, 1, 0.05, 0.2, 1000);
    }
}