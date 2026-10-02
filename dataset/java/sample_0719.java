import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0719 {
    public static void main(String[] args) {
        Random random = new Random();
        List<Double> positions = new ArrayList<>();
        List<Double> velocities = new ArrayList<>();
        List<Double> personal_best = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            positions.add(random.nextDouble() * 20 - 10);
            velocities.add(0.0);
            personal_best.add(positions.get(i));
        }

        double global_best = Double.MAX_VALUE;
        for (double pos : positions) {
            if (fitness(pos) < fitness(global_best)) {
                global_best = pos;
            }
        }

        optimize(positions, velocities, personal_best, global_best, 0, 100);
    }

    public static double optimize(List<Double> positions, List<Double> velocities, List<Double> personal_best, double global_best, int iteration, int max_iterations) {
        if (iteration >= max_iterations) {
            return global_best;
        }

        List<Double> new_positions = new ArrayList<>();
        List<Double> new_velocities = new ArrayList<>();

        for (int i = 0; i < positions.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double new_velocity = velocities.get(i) + 2 * r1 * (personal_best.get(i) - positions.get(i)) + 2 * r2 * (global_best - positions.get(i));
            double new_position = positions.get(i) + new_velocity;
            new_positions.add(new_position);
            new_velocities.add(new_velocity);
        }

        double new_global_best = Double.MAX_VALUE;
        for (double pos : new_positions) {
            if (fitness(pos) < fitness(new_global_best)) {
                new_global_best = pos;
            }
        }

        return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations);
    }

    public static double fitness(double x) {
        return x * x;
    }
}