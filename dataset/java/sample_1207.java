import java.util.Random;

public class sample_1207 {
    public static double simulate_option_price(int iterations, double strike, double drift, double volatility, double risk_free_rate, double time_to_maturity) {
        double[] values = new double[iterations];
        for (int i = 0; i < iterations; i++) {
            double price = 0;
            for (int _ = 0; _ < (int) (time_to_maturity * 252); _++) {
                price += price * drift * (1.0 / 252) + price * volatility * new Random().nextGaussian() * Math.sqrt(1.0 / 252);
            }
            values[i] = Math.max(price - strike, 0);
        }
        double sum = 0;
        for (double value : values) {
            sum += value;
        }
        return sum * (1.0 / iterations) * (1.0 / risk_free_rate);
    }

    public static void main(String[] args) {
        simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);
    }
}