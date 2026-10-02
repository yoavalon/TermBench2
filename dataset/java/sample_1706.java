import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_fitness;

    Particle(int dim) {
        Random random = new Random();
        position = new double[dim];
        velocity = new double[dim];
        best_position = new double[dim];
        best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dim; i++) {
            position[i] = random.nextDouble() * 20 - 10;
            velocity[i] = random.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] global_best_position;
    double global_best_fitness;

    Swarm(int dim, int num_particles) {
        particles = new Particle[num_particles];
        global_best_position = new double[dim];
        global_best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dim);
        }
    }

    void update_global_best() {
        for (Particle particle : particles) {
            double fitness = evaluate(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                particle.best_position = particle.position.clone();
            }
            if (fitness < global_best_fitness) {
                global_best_fitness = fitness;
                global_best_position = particle.position.clone();
            }
        }
    }

    double evaluate(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void iterate() {
        update_global_best();
        for (Particle particle : particles) {
            particle.update_velocity(global_best_position, 0.5, 1.5, 1.5);
            particle.update_position();
        }
    }
}

public class sample_1706 {
    public static void main(String[] args) {
        int dim = 2;
        int num_particles = 10;
        Swarm swarm = new Swarm(dim, num_particles);
        while (true) {
            swarm.iterate();
        }
    }
}