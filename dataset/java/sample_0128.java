import java.util.Random;

public class sample_0128 {
    public static double simulate_option_price(int steps, double drift, double volatility, double initial_price) {
        double price = initial_price;
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            price *= 1 + drift + volatility * random.nextGaussian();
        }
        return price;
    }

    public static boolean is_terminating(double price, double strike_price, String call_put) {
        if (call_put.equals("call")) {
            return price > strike_price;
        } else if (call_put.equals("put")) {
            return price < strike_price;
        }
        return false;
    }

    public static void main(String[] args) {
        double initial_price = 100;
        double strike_price = 105;
        double drift = 0.01;
        double volatility = 0.2;
        int steps = 100;
        String call_put = "call";
        double price = simulate_option_price(steps, drift, volatility, initial_price);
        boolean result = is_terminating(price, strike_price, call_put);
        System.out.println(result);
    }
}