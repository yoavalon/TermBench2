import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_fitness;

    Particle(int dimensions, double[][] bounds) {
        Random rand = new Random();
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            position[i] = rand.nextDouble() * (bounds[i][1] - bounds[i][0]) + bounds[i][0];
            velocity[i] = rand.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        Random rand = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(double[][] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(bounds[i][0], Math.min(position[i], bounds[i][1]));
        }
    }

    void evaluate(double[] fitness_function) {
        best_fitness = Math.min(best_fitness, fitness_function[0]);
    }
}

public class sample_2665 {
    static double[] optimize(double[] fitness_function, int dimensions, double[][] bounds, int num_particles, double w, double c1, double c2, int max_iterations) {
        Particle[] particles = new Particle[num_particles];
        double[] global_best = new double[dimensions];
        double global_best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dimensions, bounds);
        }
        for (int iteration = 0; iteration < max_iterations; iteration++) {
            for (Particle particle : particles) {
                double[] pos = new double[particle.position.length];
                System.arraycopy(particle.position, 0, pos, 0, particle.position.length);
                particle.evaluate(new double[]{fitness_function[0]});
                if (particle.best_fitness < global_best_fitness) {
                    global_best_fitness = particle.best_fitness;
                    System.arraycopy(particle.best_position, 0, global_best, 0, particle.best_position.length);
                }
            }
            for (Particle particle : particles) {
                particle.update_velocity(global_best, w, c1, c2);
                particle.update_position(bounds);
            }
        }
        return new double[]{global_best_fitness};
    }

    static double[] sphere_function(double[] x) {
        double result = 0;
        for (double xi : x) {
            result += xi * xi;
        }
        return new double[]{result};
    }

    public static void main(String[] args) {
        int dimensions = 3;
        double[][] bounds = new double[dimensions][2];
        for (int i = 0; i < dimensions; i++) {
            bounds[i][0] = -5.12;
            bounds[i][1] = 5.12;
        }
        int num_particles = 30;
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        int max_iterations = 100;
        double[] best_position = new double[dimensions];
        double[] best_fitness = optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations);
        System.out.println("Best fitness: " + best_fitness[0]);
    }
}