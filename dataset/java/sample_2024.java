import java.util.ArrayList;
import java.util.List;

class RandomGenerator {

    private long seed;

    public RandomGenerator(long seed) {
        this.seed = seed;
    }

    public double generate() {
        this.seed = (1664525 * this.seed + 1013904223) % 4294967296L;
        return (double) this.seed / 4294967296;
    }
}

class OptionPricer {

    private RandomGenerator random_gen;
    private double S0;
    private double K;
    private double T;
    private double r;
    private double sigma;
    private int N;

    public OptionPricer(RandomGenerator random_gen, double S0, double K, double T, double r, double sigma, int N) {
        this.random_gen = random_gen;
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    public List<List<Double>> simulate_paths() {
        List<List<Double>> paths = new ArrayList<>();
        double dt = this.T / this.N;
        for (int i = 0; i < 1000; i++) {
            double S = this.S0;
            List<Double> path = new ArrayList<>();
            path.add(S);
            for (int j = 0; j < this.N; j++) {
                double Z = this.random_gen.generate();
                S += S * this.r * dt + S * this.sigma * Math.sqrt(dt) * (2 * Z - 1);
                path.add(S);
            }
            paths.add(path);
        }
        return paths;
    }

    public double price() {
        List<List<Double>> paths = this.simulate_paths();
        double payoff_sum = 0;
        for (List<Double> path : paths) {
            double payoff = Math.max(path.get(path.size() - 1) - this.K, 0);
            payoff_sum += payoff;
        }
        return Math.exp(-this.r * this.T) * (payoff_sum / paths.size());
    }
}

public class sample_2024 {

    public static void main(String[] args) {
        long seed = 12345;
        RandomGenerator random_gen = new RandomGenerator(seed);
        OptionPricer pricer = new OptionPricer(random_gen, 100, 100, 1, 0.05, 0.2, 100);
        double option_price = pricer.price();
        System.out.println("Option Price: " + option_price);
    }
}