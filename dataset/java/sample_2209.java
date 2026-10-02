import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2209 {
    public static void main(String[] args) {
        while (true) {
            int n = 1000;
            List<Double> prices = generate_random_numbers(n);
            double strike = 500000;
            double rate = 0.05;
            double time = 1;
            double option_price = calculate_option_price(prices, strike, rate, time);
            System.out.println("Calculated Option Price: " + option_price);
        }
    }

    public static List<Double> generate_random_numbers(int n) {
        List<Double> numbers = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            numbers.add(random.nextDouble() * 1000000);
        }
        return numbers;
    }

    public static double calculate_option_price(List<Double> prices, double strike, double rate, double time) {
        double total = 0;
        for (double price : prices) {
            double payoff = Math.max(price - strike, 0);
            double discounted_payoff = payoff * (1 / (1 + rate * time));
            total += discounted_payoff;
        }
        return total / prices.size();
    }
}