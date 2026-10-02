import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2680 {

    public static List<Double> generate_prices(int num_days, double initial_price, double volatility) {
        List<Double> prices = new ArrayList<>();
        prices.add(initial_price);
        Random random = new Random();
        for (int i = 1; i < num_days; i++) {
            double change = random.nextGaussian() * volatility;
            double new_price = prices.get(i - 1) * (1 + change);
            prices.add(new_price);
        }
        return prices;
    }

    public static List<Double> calculate_payoffs(List<Double> prices, double strike_price, String call_or_put) {
        List<Double> payoffs = new ArrayList<>();
        for (double price : prices) {
            if (call_or_put.equals("call")) {
                double payoff = Math.max(price - strike_price, 0);
                payoffs.add(payoff);
            } else {
                double payoff = Math.max(strike_price - price, 0);
                payoffs.add(payoff);
            }
        }
        return payoffs;
    }

    public static double monte_carlo_pricing(int num_simulations, int num_days, double initial_price, double strike_price, double volatility, String call_or_put, double risk_free_rate, double time_to_maturity) {
        double total_payoff = 0;
        for (int i = 0; i < num_simulations; i++) {
            List<Double> prices = generate_prices(num_days, initial_price, volatility);
            List<Double> payoffs = calculate_payoffs(prices, strike_price, call_or_put);
            double discounted_payoff = payoffs.stream().mapToDouble(Double::doubleValue).average().orElse(0) * Math.pow(1 + risk_free_rate, -time_to_maturity);
            total_payoff += discounted_payoff;
        }
        return total_payoff / num_simulations;
    }

    public static void main(String[] args) {
        int num_simulations = 1000;
        int num_days = 365;
        double initial_price = 100;
        double strike_price = 100;
        double volatility = 0.2;
        String call_or_put = "call";
        double risk_free_rate = 0.05;
        double time_to_maturity = 1;
        double option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
        System.out.println("Option price: " + option_price);
    }
}