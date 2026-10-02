import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1178 {
    public static class OptionPricer {
        double S;
        double K;
        double T;
        double r;
        double sigma;

        public OptionPricer(double S, double K, double T, double r, double sigma) {
            this.S = S;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
        }

        public List<List<Double>> simulatePaths(int num_simulations, int num_steps) {
            List<List<Double>> paths = new ArrayList<>();
            for (int i = 0; i < num_simulations; i++) {
                List<Double> path = new ArrayList<>();
                path.add(S);
                for (int j = 0; j < num_steps - 1; j++) {
                    double delta_t = T / num_steps;
                    double drift = (r - 0.5 * sigma * sigma) * delta_t;
                    double diffusion = sigma * new Random().nextGaussian() * Math.sqrt(delta_t);
                    double next_price = path.get(path.size() - 1) * (1 + drift + diffusion);
                    path.add(next_price);
                }
                paths.add(path);
            }
            return paths;
        }

        public List<Double> calculatePayoff(List<List<Double>> paths) {
            List<Double> payoffs = new ArrayList<>();
            for (List<Double> path : paths) {
                double payoff = Math.max(path.get(path.size() - 1) - K, 0);
                payoffs.add(payoff);
            }
            return payoffs;
        }

        public double priceOption(int num_simulations, int num_steps) {
            List<List<Double>> paths = simulatePaths(num_simulations, num_steps);
            List<Double> payoffs = calculatePayoff(paths);
            double option_price = payoffs.stream().mapToDouble(Double::doubleValue).sum() / num_simulations * (1 / r);
            return option_price;
        }
    }

    public static void recursivePricer(OptionPricer pricer, int num_simulations, int num_steps) {
        double current_price = pricer.priceOption(num_simulations, num_steps);
        System.out.println("Current option price: " + current_price);
        recursivePricer(pricer, num_simulations, num_steps);
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        OptionPricer pricer = new OptionPricer(S, K, T, r, sigma);
        recursivePricer(pricer, 1000, 100);
    }
}