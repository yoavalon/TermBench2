import java.util.Arrays;
import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double max_velocity;
    double best_fitness = Double.MAX_VALUE;

    Particle(int dimensions, double max_velocity) {
        this.position = new double[dimensions];
        this.velocity = new double[dimensions];
        this.best_position = new double[dimensions];
        this.max_velocity = max_velocity;
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        Random rand = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
            velocity[i] = Math.max(-max_velocity, Math.min(velocity[i], max_velocity));
        }
    }

    void update_position() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double[] objective_function) {
        double fitness = 0.0;
        for (double x : position) {
            fitness += Math.pow(x, 2);
        }
        if (fitness < best_fitness) {
            best_fitness = fitness;
            best_position = position.clone();
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] global_best;
    double global_best_fitness = Double.MAX_VALUE;

    Swarm(int dimensions, int population_size, double max_velocity) {
        particles = new Particle[population_size];
        for (int i = 0; i < population_size; i++) {
            particles[i] = new Particle(dimensions, max_velocity);
        }
        global_best = new double[dimensions];
    }

    void initialize_global_best() {
        for (Particle particle : particles) {
            particle.evaluate(objective_function(particle.position));
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position.clone();
            }
        }
    }

    void update_swarm(double w, double c1, double c2) {
        for (Particle particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position();
            particle.evaluate(objective_function(particle.position));
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position.clone();
            }
        }
    }

    static double[] objective_function(double[] position) {
        return position; // Placeholder for the actual function
    }
}

public class sample_0824 {
    public static void main(String[] args) {
        int dimensions = 2;
        int population_size = 30;
        double max_velocity = 0.1;
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        int max_iterations = 100;
        double best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations);
        System.out.println('Best Fitness: ' + best_fitness);
    }

    static double optimize(int dimensions, int population_size, double max_velocity, double w, double c1, double c2, int max_iterations) {
        Swarm swarm = new Swarm(dimensions, population_size, max_velocity);
        swarm.initialize_global_best();
        for (int i = 0; i < max_iterations; i++) {
            swarm.update_swarm(w, c1, c2);
        }
        return swarm.global_best_fitness;
    }
}