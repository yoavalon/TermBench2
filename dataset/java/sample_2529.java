import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2529 {
    static Random random = new Random();

    static List<Double> simulate_price_changes(int steps, double initial_price, double volatility) {
        List<Double> prices = new ArrayList<>();
        prices.add(initial_price);
        for (int i = 0; i < steps; i++) {
            double change = random.nextGaussian() * volatility;
            prices.add(prices.get(prices.size() - 1) * Math.exp(change));
        }
        return prices;
    }

    static double calculate_option_value(List<Double> prices, double strike, double r, double T) {
        double value = 0;
        for (double price : prices) {
            value += Math.max(price - strike, 0) * Math.exp(-r * T);
        }
        return value / prices.size();
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double strike = 105;
        double r = 0.05;
        double T = 1;
        double volatility = 0.2;
        int steps = 1000;
        List<Double> prices = simulate_price_changes(steps, initial_price, volatility);
        double option_value = calculate_option_value(prices, strike, r, T);
        System.out.println("Option Value: " + option_value);
    }
}