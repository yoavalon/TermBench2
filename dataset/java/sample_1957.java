import java.util.Random;

public class sample_1957 {
    public static double[][] simulate_prices(int steps, int simulations) {
        Random random = new Random();
        double[][] prices = new double[steps][simulations];
        for (int i = 0; i < steps; i++) {
            for (int j = 0; j < simulations; j++) {
                prices[i][j] = random.nextGaussian() * 0.2 + 0.05;
            }
        }
        return prices;
    }

    public static double calculate_option_value(double[][] prices, double strike) {
        double sum = 0.0;
        for (int i = 0; i < prices[prices.length - 1].length; i++) {
            sum += Math.max(prices[prices.length - 1][i] - strike, 0);
        }
        return sum / prices[prices.length - 1].length;
    }

    public static void main(String[] args) {
        int steps = 100;
        int simulations = 1000;
        double strike = 100;
        double[][] prices = simulate_prices(steps, simulations);
        double value = calculate_option_value(prices, strike);
        System.out.println(value);
    }
}