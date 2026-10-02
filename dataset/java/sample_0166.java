import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0166 {
    public static void initialize_particles(int num_particles, int dimensions, double[] bounds, List<List<Double>> particles) {
        Random rand = new Random();
        for (int i = 0; i < num_particles; i++) {
            List<Double> particle = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                particle.add(rand.nextDouble() * (bounds[1] - bounds[0]) + bounds[0]);
            }
            particles.add(particle);
        }
    }

    public static List<List<Double>> update_positions(List<List<Double>> particles, List<List<Double>> velocities, double[] bounds) {
        List<List<Double>> new_positions = new ArrayList<>();
        for (int i = 0; i < particles.size(); i++) {
            List<Double> new_position = new ArrayList<>();
            for (int j = 0; j < particles.get(i).size(); j++) {
                double new_pos = Math.max(bounds[0], Math.min(bounds[1], particles.get(i).get(j) + velocities.get(i).get(j)));
                new_position.add(new_pos);
            }
            new_positions.add(new_position);
        }
        return new_positions;
    }

    public static void main(String[] args) {
        int num_particles = 30;
        int dimensions = 2;
        double[] bounds = {0, 10};
        List<List<Double>> particles = new ArrayList<>();
        List<List<Double>> velocities = new ArrayList<>();

        initialize_particles(num_particles, dimensions, bounds, particles);
        for (int i = 0; i < num_particles; i++) {
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                velocity.add(new Random().nextDouble() * 2 - 1);
            }
            velocities.add(velocity);
        }

        for (int i = 0; i < 100; i++) {
            particles = update_positions(particles, velocities, bounds);
        }

        System.out.println(particles);
    }
}