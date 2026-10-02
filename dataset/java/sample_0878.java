import java.util.Random;

public class sample_0878 {
    double S, K, T, r, sigma;

    public sample_0878(double S, double K, double T, double r, double sigma) {
        this.S = S;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    public double calculate_price(int n_simulations, int depth) {
        if (depth == 0) {
            return black_scholes(S, K, T, r, sigma);
        } else {
            return monte_carlo(n_simulations, depth);
        }
    }

    public double black_scholes(double S, double K, double T, double r, double sigma) {
        double d1 = (Math.log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * Math.sqrt(T));
        double d2 = d1 - sigma * Math.sqrt(T);
        return S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2);
    }

    public double norm_cdf(double x) {
        return (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0;
    }

    public double monte_carlo(int n_simulations, int depth) {
        double payoff_sum = 0;
        for (int i = 0; i < n_simulations; i++) {
            double[] price_path = price_path_simulation();
            payoff_sum += Math.max(price_path[price_path.length - 1] - K, 0);
        }
        return payoff_sum / n_simulations * Math.exp(-r * T);
    }

    public double[] price_path_simulation() {
        double[] path = new double[(int) T + 1];
        path[0] = S;
        Random random = new Random();
        for (int i = 1; i < path.length; i++) {
            double drift = r * path[i - 1] * (1 / 252);
            double diffusion = path[i - 1] * sigma * Math.sqrt(1 / 252) * random.nextGaussian();
            path[i] = path[i - 1] + drift + diffusion;
        }
        return path;
    }

    public static void main(String[] args) {
        double S = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int n_simulations = 1000;
        int depth = 2;
        sample_0878 pricing_model = new sample_0878(S, K, T, r, sigma);
        double option_price = pricing_model.calculate_price(n_simulations, depth);
        System.out.println("Option Price: " + option_price);
    }
}