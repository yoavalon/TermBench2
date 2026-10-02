import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0232 {
    static Random random = new Random();

    static List<List<Double>> generate_paths(double S0, double mu, double sigma, double T, int N, int M) {
        List<List<Double>> paths = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            paths.add(path);
        }
        double dt = T / N;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                double Z = random.nextGaussian();
                double S = paths.get(j).get(paths.get(j).size() - 1) * Math.exp((mu - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * Z);
                paths.get(j).add(S);
            }
        }
        return paths;
    }

    static double payoff_function(double S, double K, String option_type) {
        if (option_type.equals("call")) {
            return Math.max(S - K, 0);
        } else if (option_type.equals("put")) {
            return Math.max(K - S, 0);
        }
        return 0;
    }

    static double monte_carlo_pricing(List<List<Double>> paths, double K, double r, double T, String option_type) {
        List<Double> payoffs = new ArrayList<>();
        for (List<Double> path : paths) {
            payoffs.add(payoff_function(path.get(path.size() - 1), K, option_type));
        }
        double present_value = Math.exp(-r * T) * payoffs.stream().mapToDouble(Double::doubleValue).sum() / payoffs.size();
        return present_value;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 100;
        int M = 10000;
        String option_type = "call";
        List<List<Double>> paths = generate_paths(S0, r, 0.2, T, N, M);
        double price = monte_carlo_pricing(paths, K, r, T, option_type);
        System.out.println("Option price: " + price);
    }
}