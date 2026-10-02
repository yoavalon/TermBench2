import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0802 {

    private double price;
    private double strike;
    private double rate;
    private double volatility;
    private double time;
    private int simulations;
    private Random random = new Random();

    public sample_0802(double price, double strike, double rate, double volatility, double time, int simulations) {
        this.price = price;
        this.strike = strike;
        this.rate = rate;
        this.volatility = volatility;
        this.time = time;
        this.simulations = simulations;
    }

    private List<Double> _simulate(int count) {
        if (count >= simulations) {
            return new ArrayList<>();
        }
        double dt = time / simulations;
        double drift = (rate - 0.5 * volatility * volatility) * dt;
        double diffusion = volatility * Math.sqrt(dt);
        double price = this.price * Math.exp(drift + diffusion * random.nextGaussian());
        List<Double> prices = _simulate(count + 1);
        prices.add(0, price);
        return prices;
    }

    private List<Double> _payoff(List<Double> prices) {
        List<Double> payoffs = new ArrayList<>();
        for (double p : prices) {
            payoffs.add(Math.max(p - strike, 0));
        }
        return payoffs;
    }

    public double price_option() {
        List<Double> prices = _simulate(0);
        List<Double> payoffs = _payoff(prices);
        double payoffSum = 0;
        for (double payoff : payoffs) {
            payoffSum += payoff;
        }
        return Math.exp(-rate * time) * payoffSum / simulations;
    }

    public static void main(String[] args) {
        double price = 100;
        double strike = 100;
        double rate = 0.05;
        double volatility = 0.2;
        double time = 1;
        int simulations = 10000;
        sample_0802 model = new sample_0802(price, strike, rate, volatility, time, simulations);
        System.out.println(model.price_option());
    }
}