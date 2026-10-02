import java.util.Random;

class Option {
    double strike;
    double maturity;

    Option(double strike, double maturity) {
        this.strike = strike;
        this.maturity = maturity;
    }

    double payoff(double spot) {
        return Math.max(spot - this.strike, 0);
    }
}

class MonteCarloPricer {
    Option option;
    double initial_price;
    double volatility;
    double risk_free_rate;
    int steps;
    int simulations;
    double dt;
    Random random = new Random();

    MonteCarloPricer(Option option, double initial_price, double volatility, double risk_free_rate, int steps, int simulations) {
        this.option = option;
        this.initial_price = initial_price;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
        this.steps = steps;
        this.simulations = simulations;
        this.dt = option.maturity / steps;
    }

    double[][] simulate_paths() {
        double[][] paths = new double[simulations][steps];
        for (int i = 0; i < simulations; i++) {
            paths[i][0] = initial_price;
        }
        for (int t = 1; t < steps; t++) {
            for (int i = 0; i < simulations; i++) {
                paths[i][t] = paths[i][t - 1] * Math.exp((risk_free_rate - 0.5 * volatility * volatility) * dt + volatility * Math.sqrt(dt) * (2 * (random.nextDouble() - 0.5)));
            }
        }
        return paths;
    }

    double price_option() {
        double[][] paths = simulate_paths();
        double[] payoffs = new double[simulations];
        for (int i = 0; i < simulations; i++) {
            payoffs[i] = option.payoff(paths[i][steps - 1]);
        }
        double price = Math.exp(-risk_free_rate * option.maturity) * (Arrays.stream(payoffs).sum() / simulations);
        return price;
    }
}

public class sample_0297 {
    public static void main(String[] args) {
        double strike = 100;
        double maturity = 1.0;
        double initial_price = 100;
        double volatility = 0.2;
        double risk_free_rate = 0.05;
        int steps = 100;
        int simulations = 1000;
        Option option = new Option(strike, maturity);
        MonteCarloPricer pricer = new MonteCarloPricer(option, initial_price, volatility, risk_free_rate, steps, simulations);
        double price = pricer.price_option();
        System.out.println("Option price: " + price);
    }
}