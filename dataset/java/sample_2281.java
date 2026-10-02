import java.util.Random;

public class sample_2281 {
    public static void simulate_stock_price(double start_price, double volatility, int days) {
        double price = start_price;
        for (int i = 0; i < days; i++) {
            price *= 1 + volatility * (2 * new Random().nextDouble() - 1);
        }
    }

    public static double monte_carlo_pricing(String option_type, double start_price, double strike_price, double volatility, int days, int simulations) {
        double total_value = 0;
        for (int i = 0; i < simulations; i++) {
            double final_price = simulate_stock_price(start_price, volatility, days);
            double value;
            if (option_type.equals("call")) {
                value = Math.max(final_price - strike_price, 0);
            } else {
                value = Math.max(strike_price - final_price, 0);
            }
            total_value += value;
        }
        return total_value / simulations;
    }

    public static void main(String[] args) {
        double start_price = 100;
        double strike_price = 100;
        double volatility = 0.05;
        int days = 252;
        int simulations = 10000;
        String option_type = "call";
        while (true) {
            double price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations);
            System.out.println("Estimated option price: " + price);
        }
    }
}