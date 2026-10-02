import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2656 {
    public static void main(String[] args) {
        int size = 30;
        int dimensions = 2;
        double[] bounds = {-10, 10};
        int max_iterations = 100;
        Swarm swarm = new Swarm(size, dimensions, bounds);
        optimize(swarm, max_iterations);
        System.out.println(swarm.gbest.position);
    }

    public static class Swarm {
        int size;
        int dimensions;
        double[] bounds;
        List<Particle> particles;
        Particle gbest;

        Swarm(int size, int dimensions, double[] bounds) {
            this.size = size;
            this.dimensions = dimensions;
            this.bounds = bounds;
            this.particles = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                particles.add(new Particle(dimensions, bounds));
            }
            this.gbest = null;
        }

        void update_gbest() {
            for (Particle particle : particles) {
                if (gbest == null || particle.fitness < gbest.fitness) {
                    gbest = particle;
                }
            }
        }

        void update_particles() {
            for (Particle particle : particles) {
                particle.update_velocity(gbest);
                particle.update_position();
            }
        }
    }

    public static class Particle {
        List<Double> position;
        List<Double> velocity;
        List<Double> best_position;
        double fitness;

        Particle(int dimensions, double[] bounds) {
            Random random = new Random();
            position = new ArrayList<>();
            velocity = new ArrayList<>();
            best_position = new ArrayList<>();
            for (int i = 0; i < dimensions; i++) {
                position.add(random.nextDouble() * (bounds[1] - bounds[0]) + bounds[0]);
                velocity.add(random.nextDouble() * 2 - 1);
                best_position.add(position.get(i));
            }
            fitness = Double.POSITIVE_INFINITY;
        }

        void update_velocity(Particle gbest) {
            double w = 0.5, c1 = 1.5, c2 = 1.5;
            Random random = new Random();
            for (int i = 0; i < velocity.size(); i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive = c1 * r1 * (best_position.get(i) - position.get(i));
                double social = c2 * r2 * (gbest.position.get(i) - position.get(i));
                velocity.set(i, w * velocity.get(i) + cognitive + social);
            }
        }

        void update_position() {
            for (int i = 0; i < position.size(); i++) {
                position.set(i, position.get(i) + velocity.get(i));
                if (position.get(i) < bounds[0]) {
                    position.set(i, bounds[0]);
                }
                if (position.get(i) > bounds[1]) {
                    position.set(i, bounds[1]);
                }
            }
        }
    }

    public static double objective_function(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += Math.pow(xi, 2);
        }
        return sum;
    }

    public static void optimize(Swarm swarm, int max_iterations) {
        for (int i = 0; i < max_iterations; i++) {
            swarm.update_gbest();
            for (Particle particle : swarm.particles) {
                particle.fitness = objective_function(particle.position);
            }
            swarm.update_particles();
        }
    }
}