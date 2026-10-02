import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1020 {
    public static List<Double> simulate_price(double initial_price, double volatility, int time_steps) {
        List<Double> prices = new ArrayList<>();
        prices.add(initial_price);
        Random random = new Random();
        for (int i = 0; i < time_steps; i++) {
            double drift = 0.05 * prices.get(prices.size() - 1);
            double shock = volatility * prices.get(prices.size() - 1) * random.nextGaussian();
            double new_price = prices.get(prices.size() - 1) + drift + shock;
            prices.add(new_price);
        }
        return prices;
    }

    public static double calculate_option_price(List<Double> prices, double strike_price, String option_type) {
        if (option_type.equals("call")) {
            return Math.max(0, Collections.max(prices) - strike_price);
        } else {
            return Math.max(0, strike_price - Collections.min(prices));
        }
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double volatility = 0.2;
        int time_steps = 100;
        double strike_price = 105;
        while (true) {
            List<Double> prices = simulate_price(initial_price, volatility, time_steps);
            double option_price = calculate_option_price(prices, strike_price, "call");
            System.out.println("Option price: " + option_price);
        }
    }
}