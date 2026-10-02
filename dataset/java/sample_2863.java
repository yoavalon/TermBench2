import java.util.Random;

public class sample_2863 {
    static Random random = new Random();

    static double simulate_stock_price(double s0, double mu, double sigma, double dt) {
        return s0 * (1 + mu * dt + sigma * random.nextGaussian() * Math.sqrt(dt));
    }

    static double monte_carlo_option_pricing(double s0, double strike, double r, double t, double sigma, int n_simulations) {
        double dt = t / 252;
        double[] option_values = new double[n_simulations];
        for (int i = 0; i < n_simulations; i++) {
            double price = s0;
            for (int j = 0; j < 252; j++) {
                price = simulate_stock_price(price, r - 0.5 * sigma * sigma, sigma, dt);
            }
            option_values[i] = Math.max(price - strike, 0);
        }
        double sum = 0;
        for (double value : option_values) {
            sum += value;
        }
        return sum / n_simulations;
    }

    public static void main(String[] args) {
        double s0 = 100, strike = 105, r = 0.05, t = 1, sigma = 0.2;
        int n_simulations = 10000;
        while (true) {
            double price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations);
            System.out.println("Option price: " + price);
        }
    }
}