import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class FinancialModel {

    double a;
    double b;
    double c;
    int d;
    int e;

    FinancialModel(double initial_price, double volatility, double risk_free_rate, int time_steps, int num_simulations) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = time_steps;
        this.e = num_simulations;
    }

    List<List<Double>> generate_paths() {
        List<List<Double>> paths = new ArrayList<>();
        for (int i = 0; i < e; i++) {
            List<Double> path = new ArrayList<>();
            path.add(a);
            for (int j = 0; j < d; j++) {
                double z = new Random().nextGaussian();
                double next_price = path.get(path.size() - 1) * Math.exp(c - 0.5 * b * b + b * z);
                path.add(next_price);
            }
            paths.add(path);
        }
        return paths;
    }
}

class OptionPricer {

    FinancialModel f;
    double g;
    String h;

    OptionPricer(FinancialModel model, double strike_price, String option_type) {
        this.f = model;
        this.g = strike_price;
        this.h = option_type;
    }

    double price_option() {
        List<List<Double>> paths = f.generate_paths();
        List<Double> payoffs = new ArrayList<>();
        for (List<Double> path : paths) {
            double payoff;
            if (h.equals("call")) {
                payoff = Math.max(path.get(path.size() - 1) - g, 0);
            } else {
                payoff = Math.max(g - path.get(path.size() - 1), 0);
            }
            payoffs.add(payoff);
        }
        double sum = 0;
        for (double payoff : payoffs) {
            sum += payoff;
        }
        return sum / f.e;
    }
}

public class sample_1472 {

    public static void main(String[] args) {
        FinancialModel model = new FinancialModel(100, 0.2, 0.05, 100, 10000);
        OptionPricer pricer = new OptionPricer(model, 100, "call");
        double option_price = pricer.price_option();
        System.out.println("Option Price: " + option_price);
    }
}