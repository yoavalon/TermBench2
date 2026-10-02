import java.util.Random;

public class sample_2567 {
    public static double[][] simulatePrices(int steps, int simulations) {
        double drift = 0.05;
        double volatility = 0.2;
        double initialPrice = 100;
        double dt = 1.0 / steps;
        double[][] paths = new double[simulations][steps];
        for (int i = 0; i < simulations; i++) {
            paths[i][0] = initialPrice;
        }
        for (int t = 1; t < steps; t++) {
            Random rand = new Random();
            double[] z = new double[simulations];
            for (int i = 0; i < simulations; i++) {
                z[i] = rand.nextGaussian();
            }
            for (int i = 0; i < simulations; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((drift - 0.5 * volatility * volatility) * dt + volatility * Math.sqrt(dt) * z[i]);
            }
        }
        return paths;
    }

    public static double[] optionPricing(double[] prices, double strike, String optionType) {
        double[] optionValues = new double[prices.length];
        if (optionType.equals("call")) {
            for (int i = 0; i < prices.length; i++) {
                optionValues[i] = Math.max(prices[i] - strike, 0);
            }
        } else if (optionType.equals("put")) {
            for (int i = 0; i < prices.length; i++) {
                optionValues[i] = Math.max(strike - prices[i], 0);
            }
        } else {
            return null;
        }
        return optionValues;
    }

    public static void main(String[] args) {
        int steps = 252;
        int simulations = 10000;
        double strike = 105;
        double[][] prices = simulatePrices(steps, simulations);
        double[] optionValues = optionPricing(prices[0], strike, "call");
        double sum = 0;
        for (double value : optionValues) {
            sum += value;
        }
        System.out.println(sum / optionValues.length);
    }
}