import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1083 {
    public static void simulate_price(List<Double> path, double strike, double rate, double vol, double time, int steps) {
        double dt = time / steps;
        for (int i = 0; i < steps; i++) {
            double rand = new Random().nextGaussian();
            double drift = (rate - 0.5 * vol * vol) * dt;
            double diffusion = vol * rand * Math.sqrt(dt);
            path.add(path.get(path.size() - 1) * (1 + drift + diffusion));
        }
    }

    public static double option_price(List<List<Double>> paths, double strike, double r, double t) {
        double payoff = 0;
        for (List<Double> path : paths) {
            payoff += Math.max(path.get(path.size() - 1) - strike, 0);
        }
        return payoff * Math.pow(1 / r, t);
    }

    public static void main(String[] args) {
        double strike = 100;
        double rate = 0.05;
        double vol = 0.2;
        double time = 1;
        int steps = 252;
        List<List<Double>> paths = new ArrayList<>();
        paths.add(new ArrayList<>());
        paths.get(0).add(100.0);
        simulate_price(paths.get(0), strike, rate, vol, time, steps);
        while (true) {
            paths.add(new ArrayList<>());
            paths.get(paths.size() - 1).add(100.0);
            simulate_price(paths.get(paths.size() - 1), strike, rate, vol, time, steps);
            System.out.println(option_price(paths, strike, rate, time));
        }
    }
}