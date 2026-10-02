import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_fitness;
    Random random = new Random();

    Particle(int dimensions) {
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            position[i] = random.nextDouble() * 2 - 1;
            velocity[i] = random.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        for (int i = 0; i < position.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(double[][] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], position[i]));
        }
    }

    void evaluate_fitness(double[] fitness_function) {
        double fitness = 0;
        for (double xi : position) {
            fitness += xi * xi;
        }
        if (fitness < best_fitness) {
            best_fitness = fitness;
            for (int i = 0; i < position.length; i++) {
                best_position[i] = position[i];
            }
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] global_best;
    double global_best_fitness;
    double[][] bounds;
    double[] fitness_function;
    Random random = new Random();

    Swarm(int num_particles, int dimensions, double[][] bounds, double[] fitness_function) {
        particles = new Particle[num_particles];
        global_best = new double[dimensions];
        global_best_fitness = Double.POSITIVE_INFINITY;
        this.bounds = bounds;
        this.fitness_function = fitness_function;
        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dimensions);
        }
        for (int i = 0; i < dimensions; i++) {
            global_best[i] = random.nextDouble() * 2 - 1;
        }
    }

    void update_global_best() {
        for (Particle particle : particles) {
            if (particle.best_fitness < global_best_fitness) {
                global_best_fitness = particle.best_fitness;
                for (int i = 0; i < particle.position.length; i++) {
                    global_best[i] = particle.best_position[i];
                }
            }
        }
    }

    void optimize(double w, double c1, double c2) {
        while (true) {
            for (Particle particle : particles) {
                particle.update_velocity(global_best, w, c1, c2);
                particle.update_position(bounds);
                particle.evaluate_fitness(fitness_function);
            }
            update_global_best();
        }
    }
}

public class sample_2902 {
    public static void main(String[] args) {
        int dimensions = 2;
        int num_particles = 30;
        double[][] bounds = { {-10, -10}, {10, 10} };
        Swarm swarm = new Swarm(num_particles, dimensions, bounds, new double[0]);
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        swarm.optimize(w, c1, c2);
    }
}