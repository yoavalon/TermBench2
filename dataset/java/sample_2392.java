import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class sample_2392 {
    public static void main(String[] args) {
        int num_particles = 30;
        int dimensions = 2;
        double inertia_weight = 0.7;
        double cognitive_weight = 1.5;
        double social_weight = 1.5;
        List<Map<String, List<Double>>> particles = initializeParticles(num_particles, dimensions);
        while (true) {
            evaluateFitness(particles, fitnessFunction);
            List<Double> global_best_position = findGlobalBest(particles);
            updateParticles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight);
        }
    }

    public static List<Map<String, List<Double>>> initializeParticles(int num_particles, int dimensions) {
        List<Map<String, List<Double>>> particles = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < num_particles; i++) {
            List<Double> position = new ArrayList<>();
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
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

    public static void evaluateFitness(List<Map<String, List<Double>>> particles, FitnessFunction fitnessFunction) {
        for (Map<String, List<Double>> particle : particles) {
            particle.put("fitness", fitnessFunction.apply(particle.get("position")));
        }
    }

    public static void updateParticles(List<Map<String, List<Double>>> particles, List<Double> global_best_position, double inertia_weight, double cognitive_weight, double social_weight) {
        Random random = new Random();
        for (Map<String, List<Double>> particle : particles) {
            List<Double> position = particle.get("position");
            List<Double> velocity = particle.get("velocity");
            List<Double> best_position = particle.get("best_position");
            for (int i = 0; i < position.size(); i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive_velocity = cognitive_weight * r1 * (best_position.get(i) - position.get(i));
                double social_velocity = social_weight * r2 * (global_best_position.get(i) - position.get(i));
                velocity.set(i, inertia_weight * velocity.get(i) + cognitive_velocity + social_velocity);
                position.set(i, position.get(i) + velocity.get(i));
            }
            if (fitnessFunction.apply(position) < fitnessFunction.apply(best_position)) {
                best_position.clear();
                best_position.addAll(position);
            }
        }
    }

    public static List<Double> findGlobalBest(List<Map<String, List<Double>>> particles) {
        Map<String, List<Double>> best_particle = particles.stream()
                .min((p1, p2) -> Double.compare(p1.get("fitness"), p2.get("fitness")))
                .orElse(null);
        return best_particle.get("position");
    }

    @FunctionalInterface
    public interface FitnessFunction {
        double apply(List<Double> position);
    }

    public static double fitnessFunction(List<Double> position) {
        return position.stream().mapToDouble(x -> x * x).sum();
    }
}