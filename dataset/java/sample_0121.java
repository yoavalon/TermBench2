import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0121 {
    public static List<Double> simulate_stock_price(double start, double volatility, int days) {
        List<Double> prices = new ArrayList<>();
        prices.add(start);
        Random random = new Random();
        for (int i = 0; i < days; i++) {
            double price_change = random.nextGaussian() * volatility;
            double new_price = prices.get(prices.size() - 1) * (1 + price_change);
            prices.add(new_price);
        }
        return prices;
    }

    public static double calculate_option_value(List<Double> prices, double strike, int days, double risk_free_rate) {
        double final_price = prices.get(prices.size() - 1);
        double payoff = Math.max(final_price - strike, 0);
        return payoff / Math.pow(1 + risk_free_rate, days);
    }

    public static void main(String[] args) {
        double start_price = 100;
        double volatility = 0.2;
        double strike_price = 105;
        int days = 30;
        double risk_free_rate = 0.05;
        int iterations = 1000;
        double total_value = 0;
        for (int i = 0; i < iterations; i++) {
            List<Double> prices = simulate_stock_price(start_price, volatility, days);
            double option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
            total_value += option_value;
        }
        double average_value = total_value / iterations;
        System.out.println(average_value);
    }
}