import java.util.Random;

public class sample_1690 {
    public static void main(String[] args) {
        while (true) {
            int days = new Random().nextInt(365) + 1;
            double strike = new Random().nextDouble() * 100;
            double result = simulateOptionPrice(days, strike);
            System.out.println("Option price: " + result);
        }
    }

    private static double generateRandomPrice() {
        return new Random().nextDouble() * 100;
    }

    private static double simulateOptionPrice(int days, double strike) {
        double price = generateRandomPrice();
        for (int i = 0; i < days; i++) {
            price += new Random().nextGaussian();
            if (price < 0) {
                price = 0;
            }
        }
        return Math.max(price - strike, 0);
    }
}