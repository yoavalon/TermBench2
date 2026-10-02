import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0771 {

    static Random random = new Random();

    static double optimize(List<Double> positions, List<Double> velocities, List<Double> best_positions, double global_best, double w, double c1, double c2, int iterations, int count) {
        if (count == iterations) {
            return global_best;
        }
        List<Double> new_velocities = new ArrayList<>();
        List<Double> new_positions = new ArrayList<>();
        for (int i = 0; i < positions.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double velocity = w * velocities.get(i) + c1 * r1 * (best_positions.get(i) - positions.get(i)) + c2 * r2 * (global_best - positions.get(i));
            double position = positions.get(i) + velocity;
            new_velocities.add(velocity);
            new_positions.add(position);
        }
        List<Double> fitnesses = new ArrayList<>();
        for (double position : new_positions) {
            fitnesses.add(fitness(position));
        }
        List<Double> new_best_positions = new ArrayList<>();
        for (int i = 0; i < positions.size(); i++) {
            new_best_positions.add(fitnesses.get(i) < fitness(best_positions.get(i)) ? new_positions.get(i) : best_positions.get(i));
        }
        double new_global_best = fitnesses.stream().min(Double::compare).orElse(global_best);
        new_global_best = fitness(new_global_best) < fitness(global_best) ? new_global_best : global_best;
        return optimize(new_positions, new_velocities, new_best_positions, new_global_best, w, c1, c2, iterations, count + 1);
    }

    static double fitness(double position) {
        return Math.sin(position) * Math.sin(position);
    }

    public static void main(String[] args) {
        List<Double> positions = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            positions.add(random.nextDouble() * 20 - 10);
        }
        List<Double> velocities = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            velocities.add(0.0);
        }
        List<Double> best_positions = new ArrayList<>(positions);
        double global_best = positions.stream().min(Double::compare).orElse(0.0);
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 30;
        double result = optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations, 0);
        System.out.println(result);
    }
}