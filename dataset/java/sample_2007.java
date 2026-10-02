import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class FinancialModel {
    double S0;
    double K;
    double T;
    double r;
    double sigma;

    FinancialModel(double S0, double K, double T, double r, double sigma) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    List<List<Double>> simulatePaths(int numSimulations, int numSteps) {
        List<List<Double>> paths = new ArrayList<>();
        double dt = T / numSteps;
        Random random = new Random();
        for (int i = 0; i < numSimulations; i++) {
            double S = S0;
            List<Double> path = new ArrayList<>();
            path.add(S);
            for (int j = 0; j < numSteps; j++) {
                double dS = S * (r * dt + sigma * Math.sqrt(dt) * random.nextGaussian());
                S += dS;
                path.add(S);
            }
            paths.add(path);
        }
        return paths;
    }
}

class OptionPricer {
    FinancialModel model;

    OptionPricer(FinancialModel model) {
        this.model = model;
    }

    double europeanCallPrice(List<List<Double>> paths) {
        double payoff = 0.0;
        for (List<Double> path : paths) {
            payoff += Math.max(path.get(path.size() - 1) - model.K, 0);
        }
        payoff /= paths.size();
        double discountFactor = Math.exp(-model.r * model.T);
        return payoff * discountFactor;
    }
}

class AnalysisEngine {
    OptionPricer pricer;

    AnalysisEngine(OptionPricer pricer) {
        this.pricer = pricer;
    }

    double execute(int numSimulations, int numSteps) {
        List<List<Double>> paths = pricer.model.simulatePaths(numSimulations, numSteps);
        double price = pricer.europeanCallPrice(paths);
        return price;
    }
}

public class sample_2007 {
    public static void main(String[] args) {
        double S0 = 100.0;
        double K = 100.0;
        double T = 1.0;
        double r = 0.05;
        double sigma = 0.2;
        int numSimulations = 1000;
        int numSteps = 100;
        FinancialModel model = new FinancialModel(S0, K, T, r, sigma);
        OptionPricer pricer = new OptionPricer(model);
        AnalysisEngine engine = new AnalysisEngine(pricer);
        double price = engine.execute(numSimulations, numSteps);
        System.out.println("European Call Option Price: " + price);
    }
}