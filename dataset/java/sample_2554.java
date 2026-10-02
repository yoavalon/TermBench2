import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2554 {

    public static List<List<Double>> initialize_particles(int num_particles, int dimensions) {
        List<List<Double>> particles = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < num_particles; i++) {
            List<Double> particle = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                particle.add(random.nextDouble() * 2 - 1);
            }
            particles.add(particle);
        }
        return particles;
    }

    public static double evaluate_fitness(List<Double> position, List<Double> target) {
        double sum = 0;
        for (int i = 0; i < position.size(); i++) {
            double diff = position.get(i) - target.get(i);
            sum += diff * diff;
        }
        return sum;
    }

    public static List<Double> update_velocity(List<Double> velocity, List<Double> position, List<Double> p_best, List<Double> g_best, double w, double c1, double c2) {
        List<Double> new_velocity = new ArrayList<>();
        Random random = new Random();
        double r1 = random.nextDouble();
        double r2 = random.nextDouble();
        for (int i = 0; i < velocity.size(); i++) {
            double new_v = w * velocity.get(i) + c1 * r1 * (p_best.get(i) - position.get(i)) + c2 * r2 * (g_best.get(i) - position.get(i));
            new_velocity.add(new_v);
        }
        return new_velocity;
    }

    public static List<Double> update_position(List<Double> position, List<Double> velocity) {
        List<Double> new_position = new ArrayList<>();
        for (int i = 0; i < position.size(); i++) {
            double new_x = position.get(i) + velocity.get(i);
            new_position.add(new_x);
        }
        return new_position;
    }

    public static List<Double> particle_swarm(int num_particles, int dimensions, List<Double> target, int max_iterations) {
        List<List<Double>> particles = initialize_particles(num_particles, dimensions);
        List<List<Double>> velocities = new ArrayList<>();
        for (int i = 0; i < num_particles; i++) {
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                velocity.add(0.0);
            }
            velocities.add(velocity);
        }
        List<List<Double>> p_best = new ArrayList<>(particles);
        List<Double> g_best = particles.stream().min((p1, p2) -> Double.compare(evaluate_fitness(p1, target), evaluate_fitness(p2, target))).orElse(null);

        for (int t = 0; t < max_iterations; t++) {
            for (int i = 0; i < num_particles; i++) {
                if (evaluate_fitness(particles.get(i), target) < evaluate_fitness(p_best.get(i), target)) {
                    p_best.set(i, new ArrayList<>(particles.get(i)));
                }
            }
            g_best = p_best.stream().min((p1, p2) -> Double.compare(evaluate_fitness(p1, target), evaluate_fitness(p2, target))).orElse(null);

            for (int i = 0; i < num_particles; i++) {
                velocities.set(i, update_velocity(velocities.get(i), particles.get(i), p_best.get(i), g_best, 0.7, 1.5, 1.5));
                particles.set(i, update_position(particles.get(i), velocities.get(i)));
            }
        }
        return g_best;
    }

    public static void main(String[] args) {
        List<Double> target = List.of(0.0, 0.0);
        List<Double> result = particle_swarm(30, 2, target, 100);
        System.out.println(result);
    }
}