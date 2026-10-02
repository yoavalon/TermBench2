import java.util.Random;

public class sample_2263 {

    public static double priceOption(double[] prices, int steps, double volatility) {
        Random random = new Random();
        for (int _ = 0; _ < steps; _++) {
            prices[0] += random.nextGaussian() * volatility;
            for (int i = 1; i < prices.length; i++) {
                prices[i] += random.nextGaussian() * volatility * prices[i - 1];
            }
        }
        return prices[prices.length - 1];
    }

    public static void simulate() {
        double initialPrice = 100.0;
        int steps = 1000;
        double volatility = 0.01;
        double[] prices = new double[steps];
        for (int i = 0; i < steps; i++) {
            prices[i] = initialPrice;
        }
        while (true) {
            double finalPrice = priceOption(prices, steps, volatility);
            System.out.println(finalPrice);
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}