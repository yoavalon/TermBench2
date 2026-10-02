import java.util.Random;

public class sample_1205 {
    public static void main(String[] args) {
        simulate_options(1000, 100, 100, 0.2, 0.05, 1);
    }

    public static double simulate_options(int num_simulations, double strike_price, double underlying_price, double volatility, double risk_free_rate, double time_to_maturity) {
        Random random = new Random();
        double[] values = new double[num_simulations];
        for (int i = 0; i < num_simulations; i++) {
            values[i] = Math.max(0, underlying_price * Math.exp((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity + volatility * Math.sqrt(time_to_maturity) * random.nextGaussian()) - strike_price);
        }
        double sum = 0;
        for (double value : values) {
            sum += value;
        }
        return sum / num_simulations;
    }
}