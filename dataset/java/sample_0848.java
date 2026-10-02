import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0848 {

    public static class OptionPricing {

        private double S0;
        private double K;
        private double T;
        private double r;
        private double sigma;
        private int N;

        public OptionPricing(double S0, double K, double T, double r, double sigma, int N) {
            this.S0 = S0;
            this.K = K;
            this.T = T;
            this.r = r;
            this.sigma = sigma;
            this.N = N;
        }

        private List<Double> _simulate_paths(double S0, double T, double r, double sigma, int N) {
            double dt = T / N;
            List<Double> paths = new ArrayList<>();
            paths.add(S0);
            for (int _ = 1; _ <= N; _++) {
                Random random = new Random();
                double z = random.nextGaussian();
                double S = paths.get(paths.size() - 1) * (1 + r * dt + sigma * z * Math.sqrt(dt));
                paths.add(S);
            }
            return paths;
        }

        private double _option_value(List<Double> paths, double K) {
            double value = 0;
            for (double S_T : paths) {
                value += Math.max(S_T - K, 0);
            }
            return value / paths.size();
        }

        public double price() {
            List<Double> paths = _simulate_paths(S0, T, r, sigma, N);
            return _option_value(paths, K);
        }
    }

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 1000;
        OptionPricing option = new OptionPricing(S0, K, T, r, sigma, N);
        double result = option.price();
        System.out.println("Option price: " + result);
    }
}