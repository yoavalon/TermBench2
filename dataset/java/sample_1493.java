import java.util.Arrays;
import java.util.Random;

class OptionPricer {
    double[] S0;
    double K;
    double T;
    double r;
    double sigma;
    int N;

    OptionPricer(double[] S0, double K, double T, double r, double sigma, int N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    double[][] simulatePaths() {
        double dt = T / N;
        double[][] paths = new double[N + 1][S0.length];
        paths[0] = Arrays.copyOf(S0, S0.length);
        for (int i = 1; i <= N; i++) {
            double[] z = new double[S0.length];
            Random rand = new Random();
            for (int j = 0; j < S0.length; j++) {
                z[j] = rand.nextGaussian();
            }
            for (int j = 0; j < S0.length; j++) {
                paths[i][j] = paths[i - 1][j] * Math.exp((r - 0.5 * sigma * sigma) * dt + sigma * Math.sqrt(dt) * z[j]);
            }
        }
        return paths;
    }

    double[] calculatePayoff(double[][] paths) {
        double[] payoff = new double[paths[0].length];
        for (int i = 0; i < paths[0].length; i++) {
            payoff[i] = Math.max(paths[paths.length - 1][i] - K, 0);
        }
        return payoff;
    }
}

class MonteCarloEngine {
    OptionPricer pricer;
    int num_simulations;

    MonteCarloEngine(OptionPricer pricer, int num_simulations) {
        this.pricer = pricer;
        this.num_simulations = num_simulations;
    }

    double run() {
        double[] payoffs = new double[num_simulations];
        for (int i = 0; i < num_simulations; i++) {
            double[][] paths = pricer.simulatePaths();
            double[] payoff = pricer.calculatePayoff(paths);
            payoffs[i] = payoff[0];
        }
        double price = Math.exp(-pricer.r * pricer.T) * Arrays.stream(payoffs).average().orElse(0);
        return price;
    }
}

public class sample_1493 {
    public static void main(String[] args) {
        double[] S0 = {100};
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int N = 252;
        int num_simulations = 10000;
        OptionPricer pricer = new OptionPricer(S0, K, T, r, sigma, N);
        MonteCarloEngine engine = new MonteCarloEngine(pricer, num_simulations);
        double option_price = engine.run();
        System.out.println("Option Price: " + option_price);
    }
}