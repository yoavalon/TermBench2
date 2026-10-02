import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_2318 {
    static Random random = new Random();

    static List<Map<String, Object>> initialize_particles(int dimensions, int count) {
        List<Map<String, Object>> particles = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            List<Double> position = new ArrayList<>();
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                position.add(random.nextDouble() * 20 - 10);
                velocity.add(random.nextDouble() * 2 - 1);
            }
            Map<String, Object> particle = new HashMap<>();
            particle.put("position", position);
            particle.put("velocity", velocity);
            particle.put("best_position", new ArrayList<>(position));
            particles.add(particle);
        }
        return particles;
    }

    static void evaluate_fitness(List<Map<String, Object>> particles, double objective_function(List<Double> position)) {
        for (Map<String, Object> particle : particles) {
            List<Double> positionList = (List<Double>) particle.get("position");
            double fitness = objective_function(positionList);
            particle.put("fitness", fitness);
        }
    }

    static void update_particles(List<Map<String, Object>> particles, Map<String, Object> global_best, double inertia_weight, double cognitive_weight, double social_weight) {
        for (Map<String, Object> particle : particles) {
            List<Double> position = (List<Double>) particle.get("position");
            List<Double> velocity = (List<Double>) particle.get("velocity");
            List<Double> best_position = (List<Double>) particle.get("best_position");
            for (int i = 0; i < position.size(); i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive_velocity = cognitive_weight * r1 * (best_position.get(i) - position.get(i));
                double social_velocity = social_weight * r2 * (global_best.get("position")).get(i) - position.get(i));
                velocity.set(i, inertia_weight * velocity.get(i) + cognitive_velocity + social_velocity);
                position.set(i, position.get(i) + velocity.get(i));
            }
            if ((double) particle.get("fitness") < (double) particle.get("fitness")) {
                particle.put("best_position", new ArrayList<>(position));
            }
        }
    }

    static Map<String, Object> find_global_best(List<Map<String, Object>> particles) {
        Map<String, Object> global_best = particles.get(0);
        for (int i = 1; i < particles.size(); i++) {
            Map<String, Object> particle = particles.get(i);
            if ((double) particle.get("fitness") < (double) global_best.get("fitness")) {
                global_best = particle;
            }
        }
        return global_best;
    }

    static double objective_function(List<Double> position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    public static void main(String[] args) {
        int dimensions = 2;
        int particle_count = 30;
        double inertia_weight = 0.7;
        double cognitive_weight = 1.5;
        double social_weight = 1.5;
        List<Map<String, Object>> particles = initialize_particles(dimensions, particle_count);
        while (true) {
            evaluate_fitness(particles, sample_2318::objective_function);
            Map<String, Object> global_best = find_global_best(particles);
            update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight);
        }
    }
}