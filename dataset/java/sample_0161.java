import java.util.Random;

public class sample_0161 {
    public static double simulate_stock_price(int steps, double initial_price, double drift, double volatility) {
        double price = initial_price;
        for (int i = 0; i < steps; i++) {
            price += price * (drift + volatility * new Random().nextGaussian());
        }
        return price;
    }

    public static double price_option(double pricing_function, double initial_price, double strike_price, int steps, double drift, double volatility, int simulations) {
        double total = 0;
        for (int i = 0; i < simulations; i++) {
            double final_price = simulate_stock_price(steps, initial_price, drift, volatility);
            double payoff = Math.max(final_price - strike_price, 0);
            total += payoff;
        }
        return total / simulations;
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double strike_price = 100;
        int steps = 100;
        double drift = 0.0001;
        double volatility = 0.01;
        int simulations = 10000;
        double option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
        System.out.println("Option Price: " + option_price);
    }
}