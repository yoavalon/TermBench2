import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class OptionModel {

    double S0;
    double K;
    double T;
    double r;
    double sigma;
    int n_simulations;
    Random random = new Random();

    OptionModel(double S0, double K, double T, double r, double sigma, int n_simulations) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.n_simulations = n_simulations;
    }

    List<Double> simulate() {
        List<Double> option_values = new ArrayList<>();
        for (int i = 0; i < n_simulations; i++) {
            double S_T = S0 * Math.exp((r - 0.5 * sigma * sigma) * T + sigma * Math.sqrt(T) * random.nextGaussian());
            option_values.add(Math.max(0, S_T - K));
        }
        return option_values;
    }
}

class PricingEngine {

    OptionModel model;

    PricingEngine(OptionModel model) {
        this.model = model;
    }

    double calculate_price() {
        List<Double> option_values = model.simulate();
        double sum = 0;
        for (double value : option_values) {
            sum += value;
        }
        return sum / option_values.size();
    }
}

class SimulationController {

    PricingEngine pricing_engine;

    SimulationController(PricingEngine pricing_engine) {
        this.pricing_engine = pricing_engine;
    }

    void run() {
        while (true) {
            double price = pricing_engine.calculate_price();
            System.out.println("Option price: " + price);
        }
    }
}

public class sample_1760 {

    public static void main(String[] args) {
        double S0 = 100;
        double K = 100;
        double T = 1;
        double r = 0.05;
        double sigma = 0.2;
        int n_simulations = 1000;
        OptionModel model = new OptionModel(S0, K, T, r, sigma, n_simulations);
        PricingEngine pricing_engine = new PricingEngine(model);
        SimulationController controller = new SimulationController(pricing_engine);
        controller.run();
    }
}