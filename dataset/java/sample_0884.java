import java.util.Random;
import java.util.ArrayList;
import java.util.List;

public class sample_0884 {

    static class OptionPricer {
        double strike, spot, vol, rate, div, T;

        OptionPricer(double strike, double spot, double vol, double rate, double div, double T) {
            this.strike = strike;
            this.spot = spot;
            this.vol = vol;
            this.rate = rate;
            this.div = div;
            this.T = T;
        }

        double d1(double S, double K, double T, double r, double q, double sigma) {
            return (Math.log(S / K) + (r - q + 0.5 * sigma * sigma) * T) / (sigma * Math.sqrt(T));
        }

        double d2(double d1, double sigma, double T) {
            return d1 - sigma * Math.sqrt(T);
        }

        double call_price(double S, double K, double T, double r, double q, double sigma) {
            if (T <= 0) {
                return Math.max(0, S - K);
            }
            double d1_val = d1(S, K, T, r, q, sigma);
            double d2_val = d2(d1_val, sigma, T);
            return S * Math.exp(-q * T) * norm_cdf(d1_val) - K * Math.exp(-r * T) * norm_cdf(d2_val);
        }

        double norm_cdf(double x) {
            // Approximation of the cumulative distribution function for the standard normal distribution
            double k = 1.0 / (1.0 + 0.2316419 * Math.abs(x));
            double[] a = {0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429};
            double norm = 1.0 - 1.0 / Math.sqrt(2 * Math.PI) * Math.exp(-0.5 * x * x) * (a[0] * k + a[1] * k * k + a[2] * k * k * k + a[3] * k * k * k * k + a[4] * k * k * k * k * k);
            return x < 0 ? 1 - norm : norm;
        }
    }

    static class MonteCarloSimulator {
        OptionPricer pricer;
        int paths, steps;

        MonteCarloSimulator(OptionPricer pricer, int paths, int steps) {
            this.pricer = pricer;
            this.paths = paths;
            this.steps = steps;
        }

        List<Double> simulate() {
            List<Double> prices = new ArrayList<>();
            for (int i = 0; i < paths; i++) {
                double price_path = pricer.spot;
                for (int j = 1; j < steps; j++) {
                    price_path = _step(price_path);
                }
                prices.add(price_path);
            }
            return prices;
        }

        double _step(double S) {
            double dt = pricer.T / steps;
            double dS = S * (pricer.rate - pricer.div) * dt + S * pricer.vol * Math.sqrt(dt) * random_gauss(0, 1);
            return S + dS;
        }

        double random_gauss(double mean, double stdDev) {
            Random random = new Random();
            return mean + stdDev * random.nextGaussian();
        }
    }

    public static void main(String[] args) {
        double strike = 100;
        double spot = 100;
        double vol = 0.2;
        double rate = 0.05;
        double div = 0.02;
        double T = 1;
        int paths = 1000;
        int steps = 100;
        OptionPricer pricer = new OptionPricer(strike, spot, vol, rate, div, T);
        MonteCarloSimulator simulator = new MonteCarloSimulator(pricer, paths, steps);
        List<Double> final_prices = simulator.simulate();
        double option_value = 0;
        for (double price : final_prices) {
            option_value += pricer.call_price(price, strike, T, rate, div, vol);
        }
        option_value /= paths;
        System.out.println(option_value);
    }
}