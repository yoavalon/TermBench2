import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2987 {

    public static List<Integer> random_walk(int steps) {
        int position = 0;
        List<Integer> walk = new ArrayList<>();
        walk.add(position);
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            int step = random.nextInt(2) * 2 - 1;
            position += step;
            walk.add(position);
        }
        return walk;
    }

    public static List<Double> brownian_motion(int steps, double dt, double initial) {
        List<Double> motion = new ArrayList<>();
        double current = initial;
        motion.add(current);
        Random random = new Random();
        for (int i = 0; i < steps; i++) {
            double drift = 0;
            double diffusion = Math.sqrt(dt) * random.nextGaussian();
            current += drift + diffusion;
            motion.add(current);
        }
        return motion;
    }

    static class OptionPricer {
        private double strike;
        private double expiry;

        public OptionPricer(double strike, double expiry) {
            this.strike = strike;
            this.expiry = expiry;
        }

        public double price(List<Double> path) {
            double valueAtExpiry = path.get(path.size() - 1);
            return Math.max(0, valueAtExpiry - strike);
        }
    }

    public static double simulate_option_price(double strike, double expiry, int steps, double dt) {
        OptionPricer pricer = new OptionPricer(strike, expiry);
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            paths.add(brownian_motion(steps, dt, 0));
        }
        List<Double> prices = new ArrayList<>();
        for (List<Double> path : paths) {
            prices.add(pricer.price(path));
        }
        double sum = 0;
        for (double price : prices) {
            sum += price;
        }
        return sum / prices.size();
    }

    public static void main(String[] args) {
        double strikePrice = 100;
        double expiryTime = 1;
        int timeSteps = 100;
        double deltaT = expiryTime / timeSteps;
        while (true) {
            double price = simulate_option_price(strikePrice, expiryTime, timeSteps, deltaT);
            System.out.println("Simulated Option Price: " + price);
        }
    }
}