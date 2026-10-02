import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_pos;
    double best_score;

    Particle(int dim, double[][] bounds) {
        Random rand = new Random();
        position = new double[dim];
        velocity = new double[dim];
        best_pos = new double[dim];
        best_score = Double.POSITIVE_INFINITY;

        for (int i = 0; i < dim; i++) {
            position[i] = rand.nextDouble() * (bounds[i][1] - bounds[i][0]) + bounds[i][0];
            velocity[i] = rand.nextDouble() * 2 - 1;
            best_pos[i] = position[i];
        }
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        Random rand = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = c1 * r1 * (best_pos[i] - position[i]);
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
}

class Swarm {
    Particle[] particles;
    double[] global_best;
    double global_best_score;

    Swarm(int dim, int num_particles, double[][] bounds) {
        particles = new Particle[num_particles];
        global_best = new double[dim];
        global_best_score = Double.POSITIVE_INFINITY;

        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dim, bounds);
        }
    }

    void update_global_best() {
        for (Particle particle : particles) {
            double score = evaluate(particle.position);
            if (score < global_best_score) {
                for (int i = 0; i < global_best.length; i++) {
                    global_best[i] = particle.position[i];
                }
                global_best_score = score;
                particle.best_score = score;
                for (int i = 0; i < best_pos.length; i++) {
                    particle.best_pos[i] = particle.position[i];
                }
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

    void run(int iterations) {
        for (int i = 0; i < iterations; i++) {
            for (Particle particle : particles) {
                particle.update_velocity(global_best, 0.7, 1.5, 1.5);
                particle.update_position(bounds);
            }
            update_global_best();
        }
    }
}

public class sample_2071 {
    public static void main(String[] args) {
        int dim = 3;
        int num_particles = 20;
        double[][] bounds = new double[dim][2];
        for (int i = 0; i < dim; i++) {
            bounds[i][0] = -10;
            bounds[i][1] = 10;
        }
        Swarm swarm = new Swarm(dim, num_particles, bounds);
        swarm.run(100);
        System.out.println("Global Best Position: " + java.util.Arrays.toString(swarm.global_best));
        System.out.println("Global Best Score: " + swarm.global_best_score);
    }
}