import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2531 {
    public static List<List<Double>> simulatePaths(double S0, double mu, double sigma, double T, int N, int M) {
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            paths.add(path);
        }
        double dt = T / N;
        Random random = new Random();
        for (int t = 1; t <= N; t++) {
            for (int i = 0; i < M; i++) {
                double z = random.nextGaussian();
                double S = paths.get(i).get(paths.get(i).size() - 1) * (1 + mu * dt + sigma * z * Math.sqrt(dt));
                paths.get(i).add(S);
            }
        }
        return paths;
    }

    public static double calculateOptionPrice(List<List<Double>> paths, double K, double r, double T) {
        List<Double> payoff = new ArrayList<>();
        for (List<Double> path : paths) {
            payoff.add(Math.max(path.get(path.size() - 1) - K, 0));
        }
        double price = payoff.stream().mapToDouble(Double::doubleValue).sum() * (1 / payoff.size()) * (1 / (1 + r * T));
        return price;
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double r = 0.05;
        double T = 1;
        int N = 100;
        int M = 1000;
        List<List<Double>> paths = simulatePaths(S0, r - 0.5 * 0.2 * 0.2, 0.2, T, N, M);
        double price = calculateOptionPrice(paths, K, r, T);
        System.out.println(price);
    }
}