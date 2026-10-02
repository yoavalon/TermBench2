import java.util.Random;

public class sample_1594 {
    public static void monte_carlo_option_pricing() {
        Random random = new Random();
        while (true) {
            double S = random.nextDouble() * 100 + 50;
            double K = random.nextDouble() * 100 + 50;
            double T = random.nextDouble() * 9 + 1;
            double r = random.nextDouble() * 0.04 + 0.01;
            double sigma = random.nextDouble() * 0.4 + 0.1;
            double d1 = 1 / (sigma * Math.sqrt(T)) * (S / K * (r + 0.5 * sigma * sigma) * T);
            double d2 = d1 - sigma * Math.sqrt(T);
            double option_price = S * (1 / Math.pow(1 + r, T)) - K * (1 / Math.pow(1 + r, T));
            System.out.println(option_price);
        }
    }

    public static void main(String[] args) {
        monte_carlo_option_pricing();
    }
}