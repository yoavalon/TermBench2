import java.util.Random;

public class sample_1351 {

    public static double[] simulate_prices(int steps, double mean, double volatility) {
        double[] prices = new double[steps];
        prices[0] = 100;
        Random random = new Random();
        for (int i = 1; i < steps; i++) {
            prices[i] = prices[i - 1] * (1 + random.nextGaussian() * volatility + mean);
        }
        return prices;
    }

    public static double calculate_option_value(double[] prices, double strike, double r, double t) {
        double payoff = Math.max(prices[prices.length - 1] - strike, 0);
        double value = payoff * Math.exp(-r * t);
        return value;
    }

    public static void main(String[] args) {
        int steps = 100;
        double mean = 0.001;
        double volatility = 0.01;
        double strike = 105;
        double r = 0.05;
        double t = 1.0;
        double[] prices = simulate_prices(steps, mean, volatility);
        double option_value = calculate_option_value(prices, strike, r, t);
        System.out.println(option_value);
    }
}