import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0611 {
    public static double monte_carlo_pricing(double S, double K, double T, double r, double sigma, int N, int M) {
        double dt = T / N;
        List<List<Double>> paths = new ArrayList<>();
        Random random = new Random();
        
        for (int j = 0; j < M; j++) {
            paths.add(new ArrayList<>());
            paths.get(j).add(S);
        }
        
        for (int t = 1; t <= N; t++) {
            for (int j = 0; j < M; j++) {
                double lastPrice = paths.get(j).get(paths.get(j).size() - 1);
                double drift = (r - 0.5 * sigma * sigma) * dt;
                double diffusion = sigma * Math.sqrt(dt) * random.nextGaussian();
                double nextPrice = lastPrice * Math.exp(drift + diffusion);
                paths.get(j).add(nextPrice);
            }
        }
        
        double optionPrice = 0;
        for (List<Double> path : paths) {
            double payoff = Math.max(path.get(path.size() - 1) - K, 0);
            optionPrice += payoff;
        }
        
        return Math.exp(-r * T) * optionPrice / M;
    }

    public static void main(String[] args) {
        monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);
    }
}