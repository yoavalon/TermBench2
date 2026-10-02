import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class FinancialModel {
    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;

    FinancialModel(double S0, double K, double T, double r, double sigma, int N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    List<List<Double>> simulate_price_paths() {
        double dt = T / N;
        List<List<Double>> paths = new ArrayList<>();
        paths.add(new ArrayList<>(List.of(S0)));
        for (int i = 1; i <= N; i++) {
            List<List<Double>> new_paths = new ArrayList<>();
            for (List<Double> path : paths) {
                double S = path.get(path.size() - 1);
                double dW = new Random().nextGaussian() * Math.sqrt(dt);
                double new_S = S * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * dW);
                List<Double> new_path = new ArrayList<>(path);
                new_path.add(new_S);
                new_paths.add(new_path);
            }
            paths = new_paths;
        }
        return paths;
    }
}

class OptionPricer {
    FinancialModel model;

    OptionPricer(FinancialModel model) {
        this.model = model;
    }

    double payoff(List<Double> price_path) {
        return Math.max(model.K - price_path.get(price_path.size() - 1), 0);
    }

    double price_option() {
        List<List<Double>> paths = model.simulate_price_paths();
        double sum = 0;
        for (List<Double> path : paths) {
            sum += payoff(path) * Math.exp(-model.r * model.T);
        }
        return sum / paths.size();
    }
}

public class sample_0882 {
    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 100;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N);
        OptionPricer pricer = new OptionPricer(model);
        double option_price = pricer.price_option();
        System.out.println("Option Price: " + option_price);
    }
}