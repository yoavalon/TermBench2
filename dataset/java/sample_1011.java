import java.util.Random;

public class sample_1011 {
    public static double simulatePriceChange(double currentPrice, double volatility) {
        return currentPrice * (1 + new Random().nextDouble() * 2 * volatility - volatility);
    }

    public static double recursivePriceSimulation(double price, double volatility, int depth) {
        if (depth == 0) {
            return price;
        }
        double newPrice = simulatePriceChange(price, volatility);
        return recursivePriceSimulation(newPrice, volatility, depth - 1);
    }

    public static void main(String[] args) {
        double initialPrice = 100.0;
        double volatility = 0.05;
        int maxDepth = 10000;
        double finalPrice = recursivePriceSimulation(initialPrice, volatility, maxDepth);
        System.out.println(finalPrice);
    }
}