import java.util.Random;

public class sample_1625 {
    static double[] simulate_prices(double base_price, double volatility, int days) {
        double[] prices = new double[days];
        prices[0] = base_price;
        Random random = new Random();
        for (int i = 1; i < days; i++) {
            double daily_return = random.nextGaussian() * volatility;
            prices[i] = prices[i - 1] * (1 + daily_return);
        }
        return prices;
    }

    static double calculate_option_premium(double[] prices, double strike_price, int days) {
        double sum = 0;
        for (double price : prices) {
            sum += Math.max(price - strike_price, 0);
        }
        return sum * 365 / days;
    }

    public static void main(String[] args) {
        double base_price = 100;
        double volatility = 0.2;
        int days = 365;
        double strike_price = 100;
        while (true) {
            double[] prices = simulate_prices(base_price, volatility, days);
            double premium = calculate_option_premium(prices, strike_price, days);
            System.out.println("Calculated option premium: " + premium);
        }
    }
}