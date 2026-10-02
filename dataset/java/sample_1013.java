import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1013 {
    static Random random = new Random();

    static void update_velocity(List<List<Double>> particles, List<List<Double>> velocities, List<List<Double>> pbest, List<Double> gbest, double w, double c1, double c2) {
        for (int i = 0; i < particles.size(); i++) {
            for (int j = 0; j < particles.get(i).size(); j++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                velocities.get(i).set(j, w * velocities.get(i).get(j) + c1 * r1 * (pbest.get(i).get(j) - particles.get(i).get(j)) + c2 * r2 * (gbest.get(j) - particles.get(i).get(j)));
            }
        }
    }

    static void update_position(List<List<Double>> particles, List<List<Double>> velocities) {
        for (int i = 0; i < particles.size(); i++) {
            for (int j = 0; j < particles.get(i).size(); j++) {
                particles.get(i).set(j, particles.get(i).get(j) + velocities.get(i).get(j));
            }
        }
    }

    static void optimize(List<List<Double>> particles, List<List<Double>> velocities, List<List<Double>> pbest, List<Double> gbest, double w, double c1, double c2) {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        optimize(particles, velocities, pbest, gbest, w, c1, c2);
    }

    static double fitness(List<Double> position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    public static void main(String[] args) {
        int num_particles = 10;
        int dimensions = 2;
        List<List<Double>> particles = new ArrayList<>();
        List<List<Double>> velocities = new ArrayList<>();
        List<List<Double>> pbest = new ArrayList<>();
        List<Double> gbest = new ArrayList<>();

        for (int i = 0; i < num_particles; i++) {
            List<Double> particle = new ArrayList<>();
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                particle.add(random.nextDouble() * 20 - 10);
                velocity.add(random.nextDouble() * 2 - 1);
            }
            particles.add(particle);
            velocities.add(velocity);
            pbest.add(new ArrayList<>(particle));
        }

        gbest.addAll(particles.get(0));
        for (int i = 1; i < num_particles; i++) {
            if (fitness(particles.get(i)) < fitness(gbest)) {
                gbest.clear();
                gbest.addAll(particles.get(i));
            }
        }

        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        optimize(particles, velocities, pbest, gbest, w, c1, c2);
    }
}