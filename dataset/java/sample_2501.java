import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2501 {
    public static List<Double> simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
        List<Double> prices = new ArrayList<>();
        prices.add(initial_price);
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            double shock = random.nextGaussian();
            double new_price = prices.get(prices.size() - 1) * (1 + drift + volatility * shock);
            prices.add(new_price);
        }
        return prices;
    }

    public static double option_pricing(List<Double> prices, double strike_price, boolean is_call) {
        double payoff = 0;
        for (double price : prices) {
            if (is_call) {
                payoff += Math.max(0, price - strike_price);
            } else {
                payoff += Math.max(0, strike_price - price);
            }
        }
        return payoff / prices.size();
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double strike_price = 105;
        double drift = 0.01;
        double volatility = 0.2;
        int steps = 100;
        boolean is_call = true;
        List<Double> prices = simulate_stock_price(steps, initial_price, drift, volatility);
        double value = option_pricing(prices, strike_price, is_call);
        System.out.println("Option value: " + value);
    }
}