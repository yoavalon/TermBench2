import java.util.Random;

public class sample_0393 {
    public static void simulate_options(double[] prices, int days) {
        Random random = new Random();
        while (true) {
            for (int day = 0; day < days; day++) {
                for (int i = 0; i < prices.length; i++) {
                    prices[i] *= 1 + (random.nextDouble() - 0.5) * 0.1;
                }
            }
            for (double price : prices) {
                System.out.print(price + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        double[] start_prices = {100, 150, 200};
        int days = 5;
        simulate_options(start_prices, days);
    }
}