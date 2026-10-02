import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2547 {

    public static List<Double> simulate_stock_price(int days, double initial_price, double volatility) {
        double price = initial_price;
        List<Double> prices = new ArrayList<>();
        prices.add(price);
        Random random = new Random();
        for (int i = 0; i < days; i++) {
            price *= 1 + volatility * random.nextGaussian();
            prices.add(price);
        }
        return prices;
    }

    public static double calculate_option_value(List<Double> prices, double strike_price, int days, double risk_free_rate) {
        double final_price = prices.get(prices.size() - 1);
        double payoff = Math.max(final_price - strike_price, 0);
        double discount_factor = 1 / Math.pow(1 + risk_free_rate, days);
        return payoff * discount_factor;
    }

    public static void main(String[] args) {
        int days = 30;
        double initial_price = 100;
        double volatility = 0.2;
        double strike_price = 105;
        double risk_free_rate = 0.05;
        List<Double> prices = simulate_stock_price(days, initial_price, volatility);
        double option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
        System.out.println("Option value: " + option_value);
    }
}