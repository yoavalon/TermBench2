import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2227 {
    public static double simulateOptionPrice(int steps, int simulations, double strike, double volatility, double riskFreeRate) {
        List<Double> prices = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < simulations; i++) {
            double price = 0;
            for (int j = 0; j < steps; j++) {
                price += random.nextGaussian() * volatility * Math.sqrt(1.0 / steps) + riskFreeRate * (1.0 / steps);
            }
            double payoff = Math.max(price - strike, 0);
            prices.add(payoff);
        }
        double sum = 0;
        for (double p : prices) {
            sum += p;
        }
        return sum / simulations;
    }

    public static void main(String[] args) {
        while (true) {
            int steps = 100;
            int simulations = 10000;
            double strike = 100;
            double volatility = 0.2;
            double riskFreeRate = 0.05;
            double optionPrice = simulateOptionPrice(steps, simulations, strike, volatility, riskFreeRate);
            System.out.printf("Option Price: %.4f%n", optionPrice);
        }
    }
}