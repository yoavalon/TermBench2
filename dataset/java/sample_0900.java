import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class FinancialModel {

    double S0, K, T, r, sigma;
    int N;

    FinancialModel(double S0, double K, double T, double r, double sigma, int N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    List<List<Double>> simulatePaths() {
        List<List<Double>> paths = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < N; i++) {
            List<Double> path = new ArrayList<>();
            path.add(S0);
            for (int j = 1; j < T * 252; j++) {
                double S_next = path.get(path.size() - 1) * (1 + random.nextGaussian() * sigma * Math.sqrt(1 / 252));
                path.add(S_next);
            }
            paths.add(path);
        }
        return paths;
    }

    List<Double> calculatePayoffs(List<List<Double>> paths) {
        List<Double> payoffs = new ArrayList<>();
        for (List<Double> path : paths) {
            double payoff = Math.max(0, path.get(path.size() - 1) - K);
            payoffs.add(payoff);
        }
        return payoffs;
    }
}

class OptionPricer {

    FinancialModel model;

    OptionPricer(FinancialModel model) {
        this.model = model;
    }

    double priceOption() {
        List<List<Double>> paths = model.simulatePaths();
        List<Double> payoffs = model.calculatePayoffs(paths);
        List<Double> discountedPayoffs = new ArrayList<>();
        for (double p : payoffs) {
            discountedPayoffs.add(p * Math.exp(-model.r * model.T));
        }
        double sum = 0;
        for (double dp : discountedPayoffs) {
            sum += dp;
        }
        return sum / discountedPayoffs.size();
    }
}

public class sample_0900 {

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 10000;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma, N);
        OptionPricer pricer = new OptionPricer(model);
        double optionPrice = pricer.priceOption();
        System.out.println("Option Price: " + optionPrice);
    }
}