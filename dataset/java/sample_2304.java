import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2304 {

    public static void main(String[] args) {
        FinancialModel model = new FinancialModel(100, 20, 0.05, 100, 1);
        PricingEngine engine = new PricingEngine(model);
        double price = engine.price_option(1000);
        System.out.println(price);
    }
}

class FinancialModel {

    double a;
    double b;
    double c;
    double d;
    double e;

    FinancialModel(double initial_price, double volatility, double risk_free_rate, double strike_price, double maturity) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = strike_price;
        this.e = maturity;
    }

    List<List<Double>> simulate_paths(int n) {
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Double> path = new ArrayList<>();
            path.add(this.a);
            for (int j = 0; j < (int) (this.e * 252); j++) {
                double z = new Random().nextGaussian();
                double s = path.get(path.size() - 1) * (1 + this.c / 252 + this.b * z / 100);
                path.add(s);
            }
            paths.add(path);
        }
        return paths;
    }

    double payoff(List<Double> path) {
        return Math.max(path.get(path.size() - 1) - this.d, 0);
    }
}

class PricingEngine {

    FinancialModel f;

    PricingEngine(FinancialModel model) {
        this.f = model;
    }

    double price_option(int simulations) {
        double total = 0;
        for (int i = 0; i < simulations; i++) {
            List<List<Double>> paths = this.f.simulate_paths(100);
            double payoff_sum = 0;
            for (List<Double> path : paths) {
                payoff_sum += this.f.payoff(path);
            }
            total += payoff_sum / paths.size();
        }
        return total / simulations * Math.exp(-this.f.c * this.f.e);
    }
}