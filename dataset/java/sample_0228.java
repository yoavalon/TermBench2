import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0228 {

    public static void main(String[] args) {
        int size = 30;
        int dimensions = 2;
        double[] search_space = {-10, 10};
        int max_iterations = 100;
        Swarm swarm = new Swarm(size, dimensions, search_space);
        optimize(swarm, max_iterations);
    }

    static class Swarm {
        int size;
        int dimensions;
        double[] search_space;
        List<Particle> particles;

        Swarm(int size, int dimensions, double[] search_space) {
            this.size = size;
            this.dimensions = dimensions;
            this.search_space = search_space;
            this.particles = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                particles.add(new Particle(dimensions, search_space));
            }
        }

        void update() {
            for (Particle particle : particles) {
                particle.update_velocity();
                particle.update_position();
            }
        }
    }

    static class Particle {
        int dimensions;
        double[] search_space;
        double[] position;
        double[] velocity;
        double[] best_position;
        double best_fitness;

        Particle(int dimensions, double[] search_space) {
            this.dimensions = dimensions;
            this.search_space = search_space;
            this.position = new double[dimensions];
            this.velocity = new double[dimensions];
            this.best_position = new double[dimensions];
            Random random = new Random();
            for (int i = 0; i < dimensions; i++) {
                position[i] = random.nextDouble() * (search_space[1] - search_space[0]) + search_space[0];
                velocity[i] = random.nextDouble() * 2 - 1;
                best_position[i] = position[i];
            }
            best_fitness = Double.POSITIVE_INFINITY;
        }

        void update_velocity() {
            double w = 0.7;
            double c1 = 1.5;
            double c2 = 1.5;
            Random random = new Random();
            for (int i = 0; i < dimensions; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive = c1 * r1 * (best_position[i] - position[i]);
                double social = c2 * r2 * (best_position[i] - position[i]);
                velocity[i] = w * velocity[i] + cognitive + social;
            }
        }

        void update_position() {
            for (int i = 0; i < dimensions; i++) {
                position[i] += velocity[i];
                position[i] = Math.max(search_space[0], Math.min(search_space[1], position[i]));
            }
        }
    }

    static double fitness_function(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += Math.pow(x, 2);
        }
        return sum;
    }

    static void optimize(Swarm swarm, int max_iterations) {
        for (int iteration = 0; iteration < max_iterations; iteration++) {
            for (Particle particle : swarm.particles) {
                double current_fitness = fitness_function(particle.position);
                if (current_fitness < particle.best_fitness) {
                    particle.best_fitness = current_fitness;
                    for (int i = 0; i < particle.dimensions; i++) {
                        particle.best_position[i] = particle.position[i];
                    }
                }
            }
            swarm.update();
        }
    }
}