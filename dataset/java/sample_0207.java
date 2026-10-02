import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_0207 {
    public static void main(String[] args) {
        int num_particles = 20;
        int num_dimensions = 2;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int max_iterations = 100;

        List<Map<String, List<Double>>> particles = initialize_particles(num_particles, num_dimensions);
        Map<String, List<Double>> global_best = evaluate_fitness(particles, fitness_function);
        for (int i = 0; i < max_iterations; i++) {
            update_velocity(particles, global_best, w, c1, c2);
            update_position(particles);
            global_best = evaluate_fitness(particles, fitness_function);
        }
        System.out.println('Best position found: ' + global_best.get('best_position'));
        System.out.println('Fitness value: ' + fitness_function(global_best.get('best_position')));
    }

    public static List<Map<String, List<Double>>> initialize_particles(int num_particles, int num_dimensions) {
        List<Map<String, List<Double>>> particles = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < num_particles; i++) {
            List<Double> position = new ArrayList<>();
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < num_dimensions; j++) {
                position.add(random.nextDouble() * 20 - 10);
                velocity.add(random.nextDouble() * 2 - 1);
            }
            Map<String, List<Double>> particle = new HashMap<>();
            particle.put("position", position);
            particle.put("velocity", velocity);
            particle.put("best_position", new ArrayList<>(position));
            particles.add(particle);
        }
        return particles;
    }

    public static void update_velocity(List<Map<String, List<Double>>> particles, Map<String, List<Double>> global_best, double w, double c1, double c2) {
        Random random = new Random();
        for (Map<String, List<Double>> particle : particles) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            List<Double> position = particle.get("position");
            List<Double> velocity = particle.get("velocity");
            List<Double> best_position = particle.get("best_position");
            List<Double> global_best_position = global_best.get("position");
            for (int i = 0; i < position.size(); i++) {
                double cognitive_velocity = c1 * r1 * (best_position.get(i) - position.get(i));
                double social_velocity = c2 * r2 * (global_best_position.get(i) - position.get(i));
                velocity.set(i, w * velocity.get(i) + cognitive_velocity + social_velocity);
            }
        }
    }

    public static void update_position(List<Map<String, List<Double>>> particles) {
        for (Map<String, List<Double>> particle : particles) {
            List<Double> position = particle.get("position");
            List<Double> velocity = particle.get("velocity");
            for (int i = 0; i < position.size(); i++) {
                position.set(i, position.get(i) + velocity.get(i));
            }
        }
    }

    public static Map<String, List<Double>> evaluate_fitness(List<Map<String, List<Double>>> particles, FitnessFunction fitness_function) {
        Map<String, List<Double>> global_best = null;
        double min_fitness = Double.MAX_VALUE;
        for (Map<String, List<Double>> particle : particles) {
            List<Double> position = particle.get("position");
            double fitness = fitness_function.apply(position);
            if (fitness < fitness_function.apply(particle.get("best_position"))) {
                particle.put("best_position", new ArrayList<>(position));
            }
            if (fitness < min_fitness) {
                min_fitness = fitness;
                global_best = particle;
            }
        }
        return global_best;
    }

    @FunctionalInterface
    public interface FitnessFunction {
        double apply(List<Double> position);
    }
}