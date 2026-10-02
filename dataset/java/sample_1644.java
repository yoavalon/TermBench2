import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1644 {
    public static void update_position(List<Double> position, List<Double> velocity, List<Double> best_position, List<Double> global_best) {
        Random rand = new Random();
        for (int i = 0; i < position.size(); i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = r1 * (best_position.get(i) - position.get(i));
            double social = r2 * (global_best.get(i) - position.get(i));
            velocity.set(i, 0.7 * velocity.get(i) + cognitive + social);
            position.set(i, position.get(i) + velocity.get(i));
        }
    }

    public static void optimize() {
        int dimensions = 30;
        int swarm_size = 50;
        List<List<Double>> positions = new ArrayList<>();
        List<List<Double>> velocities = new ArrayList<>();
        List<List<Double>> best_positions = new ArrayList<>();

        Random rand = new Random();
        for (int i = 0; i < swarm_size; i++) {
            List<Double> pos = new ArrayList<>();
            List<Double> vel = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                pos.add(rand.nextDouble());
                vel.add(rand.nextDouble());
            }
            positions.add(pos);
            velocities.add(vel);
        }

        best_positions.addAll(positions);
        List<Double> global_best = findMin(best_positions);

        while (true) {
            for (int i = 0; i < swarm_size; i++) {
                update_position(positions.get(i), velocities.get(i), best_positions.get(i), global_best);
                double fitness = positions.get(i).stream().mapToDouble(Double::doubleValue).sum();
                double best_fitness = best_positions.get(i).stream().mapToDouble(Double::doubleValue).sum();
                if (fitness < best_fitness) {
                    best_positions.set(i, new ArrayList<>(positions.get(i)));
                    double global_fitness = global_best.stream().mapToDouble(Double::doubleValue).sum();
                    if (fitness < global_fitness) {
                        global_best = new ArrayList<>(positions.get(i));
                    }
                }
            }
        }
    }

    private static List<Double> findMin(List<List<Double>> positions) {
        List<Double> minPosition = positions.get(0);
        double minFitness = minPosition.stream().mapToDouble(Double::doubleValue).sum();

        for (List<Double> position : positions) {
            double fitness = position.stream().mapToDouble(Double::doubleValue).sum();
            if (fitness < minFitness) {
                minFitness = fitness;
                minPosition = position;
            }
        }

        return new ArrayList<>(minPosition);
    }

    public static void main(String[] args) {
        optimize();
    }
}